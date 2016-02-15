#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

using namespace std;

class Test
{
public:

 friend class boost::serialization::access;

 Test(bool b, char ch, int i, double d, string str)
  : m_bool(b), m_char(ch), m_int(i), m_double(d), m_str(str)
 {
 }

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
  ar& m_bool;
  ar& m_char;
  ar& m_int;
  ar& m_double;
  ar& m_str;
    }

private:
 bool m_bool;
 char m_char;
 int m_int;
 double m_double;
 string m_str;
};

int main()
{
 Test test(true, 'm', 50, 17.89, "fuzhijie");
 std::ofstream ofs("a.map");    //从内存到硬盘
 stringstream binary_sstream;
 stringstream text_sstream;

 long long begin, end;

 int size;

 //使用二进制的方式序列化
 boost::archive::text_oarchive text_oa(text_sstream);
 boost::archive::binary_oarchive binary_oa(binary_sstream);
 boost::archive::text_oarchive oa(ofs);
 begin = time(NULL);
 
  oa << test;   //将对象写入文件中
 for(int i = 0; i < 100; ++i)
 {
  text_oa << test;
 }
 end = time(NULL);

 size = text_sstream.tellp() / (1024 * 1024);

 cout << "text serialization seconds: " << end - begin << ", space: " << size << endl;

 begin = time(NULL);
 for(int i = 0; i < 1000000; ++i)
 {
  binary_oa << test;
 }
 end = time(NULL);

        //以MB为单位
 size = binary_sstream.tellp() / (1024 * 1024);

 cout << "binary serialization seconds: " << end - begin << ", space: " << size << endl;

//反序列化
// std::ifstream ifs("a.map");    //从内存到硬盘
 Test newtest();
 std::ifstream ifs("a.map", std::ios::binary);
 boost::archive::text_iarchive ia(ifs);
 // 从存档中读取类的状态
// ia >> newtest;
//cout << newg;







 return 0;
};

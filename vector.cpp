#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string> vs;      //定义一个字符串向量 , 其实是一个二维的字符串数组a[0][0],就是每一个push_back是一个a[0], 下一次是a[1]
    vs.push_back("Hello Jared");
    vs.push_back("learn vector push_back");
    vs.insert(vs.begin() + 1, "joker");     //在a[0]+1之后,在a[1]变成"joker", 原来的内容自动向后移一个
    vs.insert(vs.begin() + 1, 5, "30stm");  //在a[0]+1之后,在a[1]之后自动加5个"30stm"字符串数组
    vector<string>::iterator i = vs.begin();
    for( ; i < vs.end(); i++)  //iterator是一个很有意思的东西,STL中一个消除指针的替代, i = vs.begin()相当于p = a[0], 然后一个for循环就会把后面的值打出来,如果vs.begin()+1就会从第二个值开始打印
    {
        cout << *i << endl;    //这个时候,因为i就是指向vs的指针,所以取指读它就可以读到vs的值 耶
    }
    cout << vs[0] << endl;
    cout << vs[1] << endl;
    cout << vs[2] << endl;
    cout << vs[3] << endl;
    cout << vs[4] << endl;
    cout << vs[5] << endl;
    cout << vs[6] << endl;
    return 0;
}

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> li(10, 24);   //链表 存了10个24进去
    li.resize(21);          //扩展原来的链表大小由10变成21默认用0填补
    li.resize(25, -1);      //再次扩展原来21的大小, 用-1填补
    list<int>::iterator lii = li.begin();   //用iterator列一个list的指针, 使它指向list的链表头
    for(; lii != li.end(); lii++)   //for循环读取链表
    {
        cout << *lii <<endl;
    }

    list<string> ls(2, "hi");
    ls.resize(10);  //扩展时,会用'\0'填补
    ls.resize(12, "gua");   //后面的12是在前面的10的基础上增加的,所以实际上只出现12-10=2个
    list<string>::iterator lsi = ls.begin();
    for(; lsi != ls.end(); lsi++)
    {
        cout << *lsi <<endl;
    }
    return 0;
}

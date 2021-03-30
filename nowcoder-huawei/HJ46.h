#include <iostream>
#include <string>
std::string truncateString(std::string str, int n)
{
    if(n>str.size())
        return str;
    else
        return str.substr(0,n);
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        int n;
        std::cin>>n;
        std::cout<<truncateString(str,n)<<std::endl;
    }
    return 0;
}
/*
输入一个字符串和一个整数k，截取字符串的前k个字符并输出
本题输入含有多组数据

case:
abABCcDEF
6
anwser:
abABCc

??what's wrong with this? too easy
*/
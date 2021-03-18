#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int hexTodoc(std::string str)
{
    int result = 0;
    auto size = str.size();
    for(int i=size-1;i>1;i--)
    {
        int b = 0;
        if(str[i]>=65 && str[i]<=90)
        {
            b = str[i]-55;
        }
        else
            b = str[i]-48;
        int m = size-1-i;
        result+=b*pow(16,m);
    }
    return result;
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        int num = hexTodoc(str);//std::stoi(str,nullptr,16);//hexTodoc(num)
        std::cout<<num<<std::endl;
    }
    return 0;
}
#include <iostream>
#include <string>
std::string highResolutionAdd(std::string a, std::string b)
{
    std::string sum;
    auto size_a = a.size();
    auto size_b = b.size();
    auto size = size_a;
    if(size_b<size_a)
    {
        for(int i=0;i<size_a-size_b;i++)
        {
            b.insert(0,1,'0');
        }
    }
    else if(size_a<size_b)
    {
        size = size_b;
        for(int i=0;i<size_b-size_a;i++)
        {
            a.insert(0,1,'0');
        }
    }
    #ifdef DEBUG
        std::cout<<"\tfilled a:"<<a<<std::endl;
        std::cout<<"\tfilled b:"<<b<<std::endl;
    #endif
    int carry = 0;
    for(int i=1;i<=size;i++)
    {
        int x = a[size-i] + b[size-i]+carry;
        if(x>=106)
        {
            x = x-106+48;
            carry = 1;
        }
        else
        {
            x = x-48;
            carry = 0;
        }
        #ifdef DEBUG
            std::cout<<"\tloop i:"<<i<<" a[]:"<<a[size-i]<<" b[]:"<<b[size-i]<<" x:"<<char(x)<<" "<<x<<std::endl;
        #endif
        sum.insert(0,1,char(x));
    }
    //last bit carry not solve
    if(carry > 0)
        sum.insert(0,1,'1');
    return sum;
}
int main()
{
    std::string m,n;
    while(std::cin>>m>>n)
    {
        std::cout<<highResolutionAdd(m,n)<<std::endl;
    }
    return 0;
}
/*
string a, string b-> int sum of a&b
字符串的长度不超过10000。
string a -> int a
string b -> int b

0 - 9
48-57

1+9 = 49+57 = 106
106-48*2 = 10
5+6 = 53+54 = 107
107-48*2 = 11

0+0 = 48+48 = 96
96-48*2+48 = 
*/
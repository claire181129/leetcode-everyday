#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int beautyOfName(std::string name)
{
    std::map<char,int> chars;
    auto size = name.size();
    for(int i=0;i<size;i++)
    {
        if(chars.size() == 0)
            chars[name[i]] = 1;
        else
        {   auto it = chars.find(name[i]);
            if(it == chars.end())
            {
                chars[name[i]] = 1;
            }
            else
            {
                it->second++;
            }
        }
    }
    int max = 0;
    int num = 26;
    auto it = chars.begin();
    while(it != chars.end())
    {
        //find the max
        std::map<char,int>::iterator itt = chars.begin();
        itt++;
        for(int i=1;i<chars.size();i++)
        {
            if(it->second<itt->second)
                it = itt;
            itt++;
        }
        max += it->second*num;
        num--;
        //delete the max
        chars.erase(it);
        it = chars.begin();
    }
}
int main()
{
    std::string name;
    while(std::cin>>name)
    {
        int max = beautyOfName(name);
        std::cout<<max<<std::endl;
    }
    return 0;
}

/*
case:
zhangsan
lisi
zhangsan = 26+8+1+14+7+19+1+14 = 192
lisi = 101
zhangsan = z,h,a*2,n*2,g,s
max = 26*2+25*2+24+23+22+21 = 52+50+90 = 192
lisi = l,i*2,s
max = 26*2+25+24

so, string -> [char-number of char, ...], sort by number of char, bigger to smaller
max = n*26 + m*25 + ... 

*/
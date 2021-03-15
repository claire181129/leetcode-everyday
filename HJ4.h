#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> get(std::string str)
{
    auto size = str.size();
    if(size>8)
    {
        int count = size/8;
        int left = size%8;
        std::vector<std::string> result;
        for(int i=0;i<count;i++)
        {
            std::string temp = str.substr(i*8,8);
            result.push_back(temp);
        }
        if(left!=0)
        {
            std::string temp = str.substr(count*8);
            for(int i=0;i<8-left;i++)
                temp+="0";
            result.push_back(temp);
        }
        return result;
    }
    else{
        for(int i=0;i<8-size;i++)
            str+="0";
        return std::vector<std::string>{str};
    }
}
int main()
{
    std::string str;
    std::vector<std::string> result;
    while(std::cin>>str)
    {
        auto temp = get(str);
        for(auto a:temp)
            result.push_back(a);
    }
    for(auto a:result)
        std::cout<<a<<std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

bool find(std::vector<char> nums,char num)
{
    for(auto i:nums)
        if(i == num)
            return true;
    return false;
}
int main()
{
    std::string str;
    std::getline(std::cin,str);
    auto size = str.size();
    std::vector<char> chars;
    for(int i=0;i<size;i++)
    {
        if(str[i]>=0 && str[i]<= 127 && find(chars,str[i]) == false)
        {
            chars.push_back(str[i]);
        }
    }
    std::cout<<chars.size()<<std::endl;
    return 0;
}
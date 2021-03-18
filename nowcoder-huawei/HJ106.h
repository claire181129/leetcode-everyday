#include <string>
#include <iostream>
int main()
{
    std::string str,temp;
    std::getline(std::cin,str);
    size_t size = str.size();
    size_t count = size/2;
    for(int i=0;i<count;i++)
    {
        char c = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = c;
    }
    std::cout<<str<<std::endl;
}
#include <string>
#include <iostream>
#include <vector>
unsigned int countUppercase(std::string str)
{
    unsigned int count = 0;
    char a = 'A', b='Z';
    size_t size = str.size();
    for(int i=0;i<size;i++)
    {
        if(str[i]>=a && str[i]<=b)
            count++;
    }
    return count;
}
int main()
{
    std::string str;
    while(std::getline(std::cin,str))
    {
        std::cout<<countUppercase(str)<<std::endl;
    }
}
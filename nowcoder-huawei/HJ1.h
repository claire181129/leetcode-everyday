#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline(std::cin,str);
    size_t lastb = str.find_last_of(" ");
    str = str.substr(lastb+1);
    std::cout<<str.size()<<std::endl;
    return 0;
}
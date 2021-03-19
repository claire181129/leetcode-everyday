#include <iostream>
#include <string>
std::string markNumber(std::string str)
{
    auto size = str.size();
    int index = 0;
    bool lastIsNumber = false;
    while(index<size)
    {
        if(str[index]>=48 && str[index]<=57)
        {
            if(!lastIsNumber)
                str.insert(index,1,'*');
            lastIsNumber = true;
        }
        else
        {
            lastIsNumber = false;
        }
        index++;
        size = str.size();
    }
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        std::cout<<markNumber(str)<<std::endl;
    }
    return 0;
}

/*
case:
Jkdi234klowe90a3
5151
answer:

trace:
loop from begin to end in string
if is number char && first number char, insert *
note: it's a dynamic loop
note: record if it's the first number char
*/
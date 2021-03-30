#include <iostream>
#include <string>
std::string decodePassword(std::string str)
{
    auto size = str.size();
    for(int i=0;i<size;i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i] += 33;
            if(str[i]>122)
            {
                str[i] = str[i]-122+96;
            }
        }
        else if(str[i] == 'a'|| str[i] == 'b'||str[i] == 'c')
        {
            str[i] = '2';
        }
        else if(str[i] == 'd' ||str[i] == 'e'||str[i] == 'f')
        {
            str[i] = '3';
        }
        else if(str[i] == 'g'||str[i] == 'h'||str[i] == 'i')
        {
            str[i] = '4';
        }
        else if(str[i] == 'j' ||str[i] == 'k'||str[i] == 'l')
        {
            str[i] = '5';
        }
        else if(str[i] == 'm'||str[i] == 'n'||str[i] == 'o')
        {
            str[i] = '6';
        }
        else if(str[i] == 'p'||str[i] == 'q'||str[i] == 'r'||str[i] == 's')
        {
            str[i] = '7';
        }
        else if(str[i] == 't'||str[i] == 'u'||str[i] == 'v')
        {
            str[i] = '8';
        }
        else if(str[i] == 'w'||str[i] == 'x'||str[i] == 'y'||str[i] == 'z')
            str[i] = '9';
    }
    return str;
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        std::cout<<decodePassword(str)<<std::endl;
    }
    return 0;
}
/*
rule:
 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0
case:
YUANzhi1987
anwser:
zvbo9441987
*/
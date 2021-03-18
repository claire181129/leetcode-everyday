#include <iostream>
#include <string>

int main()
{
    std::string str;
    while(std::cin>>str)
    {
        auto size = str.size();
        for(int i=0;i<size;i++)
        {
            char c = str[i];
            for(int j=i+1;j<size;j++)
            {
                if(str[j]<c)
                {
                    str[i] = str[j];
                    str[j] = c;
                    c = str[i];
                }
            }
        }
        std::cout<<str<<std::endl;
    }
    return 0;
}
/*
case: Ihave1nose2hands10fingers

*/
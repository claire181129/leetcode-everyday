#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline(std::cin,str);
    char c;
    std::cin>>c;
    int count = 0;
    auto size = str.size();
    for(int i=0;i<size;i++)
    {
        if(c == str[i])
            count++;
        else if(c-str[i] == 32)
        {//c lowercase, str uppercase
            if(c>=97 && c<=122)
                count++;
        }
        else if(str[i]-c == 32)
        {
            if(str[i]>=97 && str[i]<=122)
                count++;
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}
#include <iostream>
#include <string>
bool istargetstr(std::string str, int begin,int end)
{
    int length = end-begin+1;
    for(int i=1;i<length/2;i++)
    {
        if(str[begin+i] != str[end-i])
            return false;
    }
    return true;
}
int main()
{
    std::string str;
    std::cin>>str;
    int count = 0;
    size_t size = str.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(str[i] == str[j])
            {
                if(istargetstr(str,i,j))
                    if(j-i+1>count)
                        count = j-i+1;
            }
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}
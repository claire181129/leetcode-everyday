#include <iostream>
#include <string>
#include <vector>
int main()
{
    int c,p;
    char slash;
    std::vector<int> nums;
    while(std::cin>>c>>slash>>p)
    {
        if(c!=1)
        {
            for(int i=0;i<c;i++)
            {
                std::cout<<"1"<<"/"<<p;
                if(i!=c-1)
                    std::cout<<"+";
            }
            std::cout<<std::endl;
        }
    }
    return 0;
}
#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <vector>
void updateborn(std::vector<unsigned int> &born)
{
    auto size = born.size();
    //std::cout<<"before:";
    //for(auto a:born)
   //     std::cout<<a<<" ";
    //std::cout<<std::endl;
    for(int i=0;i<size;i++)
    {
        born[i]++;
        if(born[i] >= 3)
            born.push_back(1);
    }
    //std::cout<<"after:";
    //for(auto a:born)
    //    std::cout<<a<<" ";
    //std::cout<<std::endl;
    //std::cout<<std::endl;
}
unsigned int getRabit(unsigned int month)
{
    std::vector<unsigned int> born{1};
    for(int i=1;i<month;i++)
        updateborn(born);
    return born.size();
}
int main()
{
    unsigned int month = 0;
    while(std::cin>>month)
        std::cout<<getRabit(month)<<std::endl;
}
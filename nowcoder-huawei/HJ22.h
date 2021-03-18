#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <vector>
unsigned int getbottle(unsigned int count)
{
    unsigned int result = 0;
    if(count<2)
        return 0;
    else if(count == 2)
        return 1;
    else
    {
        unsigned int change = int(count/3);
        unsigned int save = count-3*change;
        //std::cout<<"count:"<<count<<" change:"<<change<<" left:"<<save;
        count = save + change;
        result = change;
        //std::cout<<" new count:"<<count<<" result:"<<result<<std::endl;
        return result + getbottle(count);
    }
}
int main()
{
    std::vector<unsigned int> bottle;
    unsigned int temp;
    while(std::cin>>temp)
    {
        if(temp != 0)
            bottle.push_back(temp);
    }
    for(auto b:bottle)
    {
        std::cout<<getbottle(b)<<std::endl;
    }
    return 0;
}
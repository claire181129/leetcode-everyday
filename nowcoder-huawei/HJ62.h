#include <iostream>
#include <string>
#include <cmath>
unsigned int count(unsigned int number)
{
    unsigned int count = 0;
    unsigned int m = log(number)/log(2);
    //std::cout<<"m:"<<m<<std::endl;
    for(int i=m;i>=0;i--)
    {
        unsigned int b = number/pow(2,i);
        number = number - b*pow(2,i);
        if(b == 1)
            count++;
    }
    return count;
}
int main()
{
    unsigned int number;
    while(std::cin>>number)
    {
        std::cout<<count(number)<<std::endl;
    }
    return 0;
}
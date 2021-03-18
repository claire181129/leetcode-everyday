#include <iostream>
#include <regex>
#include <string>
#include <cmath>
int main()
{
   int a;
   std::cin>>a;
   //std::ostringstream osstream;
   //osstream<<std::
    double m = log(a)/log(2);
    //std::cout<<"double m:"<<m<<std::endl;
    unsigned int count = 0;
    for(int i=m;i>=0;i--)
    {
        //std::cout<<i<<" ";
        if(int(a/pow(2,i)) == 1)
        {
            count++;
            a = a-pow(2,i);
            //std::cout<<1<<std::endl;
        }
        //else
            //std::cout<<0<<std::endl;
    }
    std::cout<<count<<std::endl;
    return 0;
}
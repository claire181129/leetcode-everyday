#include <iostream>
#include <regex>
#include <string>
#include <cmath>
#include <vector>
int main()
{
    unsigned int a;
   std::cin>>a;
   unsigned int m = log10(a);
   std::vector<unsigned int> result;
   //std::cout<<"int: "<<a<<" max m:"<<m<<std::endl;
   for(int i=m;i>=0;i--)
   {
       unsigned int b = a/pow(10,i);
       a = a- b*pow(10,i);
       //std::cout<<b<<std::endl;
       result.push_back(b);
   }
   //std::cout<<"result:"<<std::endl;
   for(int i=result.size()-1;i>=0;i--)
        std::cout<<result[i];
    return 0;
}
#include <iostream>
int main()
{
    double a;
   std::cin>>a;
   unsigned int m = int(a*10) - int(a)*10;
   //std::cout<<"double: "<<a<<" first dot:"<<m<<std::endl;
   if(m>=5)
        std::cout<<int(a)+1<<std::endl;
    else
        std::cout<<int(a)<<std::endl;
    return 0;
}
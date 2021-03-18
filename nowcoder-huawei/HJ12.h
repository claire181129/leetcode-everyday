#include <string>
#include <iostream>
int main()
{
       std::string str;
   std::cin>>str;
   size_t size = str.size();
   double count = size/2;
   for(int i=0;i<count;i++)
   {
       char temp = str[i];
       str[i] = str[size-i-1];
       str[size-i-1] = temp;
   }
   std::cout<<str<<std::endl;
    return 0;
}
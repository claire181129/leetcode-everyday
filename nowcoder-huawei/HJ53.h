#include <iostream>
#include <string>
#include <cmath>
#include <vector>
std::vector<unsigned int> getline(unsigned int n)
{
    if(n == 1)
        return std::vector<unsigned int>{1};
    else{
        auto lastline = getline(n-1);
        std::vector<unsigned int> newline;
        unsigned int size = 1+(n-1)*2;
        unsigned int size_last = size-2;
        for(unsigned int i=0;i<size;i++)
        {
            int idxa = i-2,idxb=i-1,idxc=i;
            unsigned int a = 0,b=0,c=0;
            if(idxa>=0 && idxa<size_last)
                a = lastline[idxa];
            if(idxb>=0 && idxb<size_last)
                b = lastline[idxb];
            if(idxc>=0 && idxc<size_last)
                c = lastline[idxc];
            newline.push_back(a+b+c);
        }
        return newline;
    }
}
int index(unsigned int number)
{
    std::vector<unsigned int> line;
    line = getline(number);
    for(int i=0;i<line.size();i++)
        if(line[i]%2 == 0)
            return i+1;
    return -1;
}
int main()
{
    unsigned int number;
    while(std::cin>>number)
    {
        std::cout<<index(number)<<std::endl;
    }
    return 0;
}
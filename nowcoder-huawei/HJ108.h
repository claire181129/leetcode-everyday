#include <iostream>
unsigned minMul(unsigned A,unsigned B)
{
    unsigned low = A>B?B:A;
    unsigned high = A*B;
    for(unsigned i=low;i<=high;i++)
    {
        if(i%A == 0 && i%B == 0)
            return i;
        else
            continue;
    }
    return high;
}
int main()
{
    unsigned A=0,B=0;
    std::cin>>A>>B;
    std::cout<<minMul(A,B)<<std::endl;
    return 0;
}
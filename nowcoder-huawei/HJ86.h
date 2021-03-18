#include <iostream>
#include <math.h>

int maxContinuousBit(int num)
{
    int m = log(num)/log(2);
    int count = 0, max = 0;
    for(int i=m;i>=0;i--)
    {
        if(pow(2,i)>num)
        {
            if(count>max)
                max = count;
            count = 0;
        }
        else
        {
            num-=pow(2,i);
            count++;
        }
    }
    if(count>max)
        max = count;
    return max;
}
int main()
{
    int num;
    while(std::cin>>num)
    {
        std::cout << maxContinuousBit(num) << std::endl;
    }
    return 0;
}
/*
input:
3
5
output:
2
1
trace:
3 -> (11)b, 2
5 -> (101)b,1
*/
#include <iostream>
#include <string>
#include <vector>

/*
*/
int countPerfectNumber(int n)
{
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        std::vector<int> factors;
        for(int j=1;j<i;j++)
        {
            if(i%j == 0)
                factors.push_back(j);
        }
        int sum = 0;
        for(auto i:factors)
            sum+=i;
        if(sum == i)
            count++;
    }
    return count;
}
int main()
{
    int n;
    while(std::cin>>n)
    {
        std::cout<<countPerfectNumber(n)<<std::endl;
    }
    return 0;
}
/*
1000
7
100

anwser:
3
1
2

trace:
7, <=7: 1,2,3,4,5,6,7
1, factor: 1, real factor: null, sum of real factor: 0
2, factor: 1,2 real factor: 1, sum: 1
3, factor: 1,3 real: 1 sum: 1
4, factor: 1,2 real: 1,2 sum: 3
5,
6, factor: 1,2,3,6 real: 1 2 3 sum: 6
*/
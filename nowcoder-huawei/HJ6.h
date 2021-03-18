#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

bool isPrime(unsigned long n)
{
    if(n%2 == 0)
        return true;
    for(unsigned long i=3;i<sqrt(n);i+=2)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
void sort(std::vector<unsigned long> &nums)
{
    auto size = nums.size();
    for(unsigned long i=0;i<size;i++)
    {
        for(unsigned long j=i+1;j<size;j++)
        {
            if(nums[j]<nums[i])
            {
                auto temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
int main()
{
    unsigned long n;
    std::cin>>n;
    std::vector<unsigned long> nums;
    while(n%2 == 0)
    {
        n = n/2;
        nums.push_back(2);
    }
    unsigned long i = 3;
    while(i<=n)
    {
        while(n%i == 0)
        {
            n = n/i;
            nums.push_back(i);
        }
        i+=2;
    }
    std::sort(nums.begin(),nums.end());
    for(auto a:nums)
        std::cout<<a<<" ";
    std::cout<<std::endl;
    return 0;
}
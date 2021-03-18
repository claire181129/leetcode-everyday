#include <iostream>
#include <vector>
bool notFound(std::vector<int> nums,int temp)
{
    for(auto i:nums)
        if(i==temp)
            return false;
    return true;
}
void sort(std::vector<int> &nums)
{
    auto size = nums.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(nums[i]>nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    
    while(std::cin>>n)
    {
        std::vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int temp = 0;
            std::cin>>temp;
            if(notFound(nums,temp))
                nums.push_back(temp);
        }
        sort(nums);
        for(auto i:nums)
            std::cout<<i<<std::endl;
    }
    return 0;
}
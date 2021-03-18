//group1
//group2
//left:
#include <iostream>
#include <vector>
bool canDivide(std::vector<int> nums,int x,int y)
{
    auto size = nums.size();
    //std::cout<<"nums:";
    //for(auto i:nums)
    //    std::cout<<i<<" ";
    //std::cout<<"\n"<<x<<" "<<y<<std::endl;
    if(size == 1)
    {
        if(x==0 && y == nums[0])
            return true;
        else if(y == 0 && x == nums[0])
            return true;
        else
            return false;
    }
    else
    {
        int m = nums[size-1];
        nums.pop_back();
        int a = x-m, b = y-m;
        if(canDivide(nums,a,y))
            return true;
        else
            return canDivide(nums,x,b);
    }
}
int main()
{
    int n;
    while(std::cin>>n)
    {
        std::vector<int> nums;
        int sum = 0,fivesum = 0,threesum = 0;
        for(int i=0;i<n;i++)
        {
            int x =0;
            std::cin>>x;
            if(x/5 && x%5 == 0)
                fivesum+=x;
            else if(x/3 && x%3 == 0)
                threesum+=x;
            else
            {
                nums.push_back(x);
                sum+=x;
            }  
        }
        sum+=fivesum+threesum;
        int target = sum/2;
        if(sum%2 == 0)
            if(canDivide(nums,target-fivesum,target-threesum))
                std::cout<<"true"<<std::endl;
            else
                std::cout<<"false"<<std::endl;
        else
            std::cout<<"false"<<std::endl;
    }
    return 0;
}
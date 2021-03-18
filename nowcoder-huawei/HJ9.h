#include <iostream>
#include <vector>
bool find(std::vector<int> nums,int num)
{
    for(auto i:nums)
        if(i == num)
            return true;
    return false;
}
int main()
{

        int n,m;
    std::cin>>n;
    if(n<0)
        m = -n;
    else
        m = n;
    std::vector<int> bits;
    //std::cout<<n<<" "<<m<<std::endl;
    while(m>0)
    {
        int bit = m%10;
        
        if(find(bits,bit) == false)
        {
                bits.push_back(bit);
                //std::cout<<bit<<std::endl;
        }
        m = m/10;
    }
    //std::cout<<"size:"<<bits.size()<<std::endl;
    if(n<0)
        std::cout<<"-";
    for(auto a:bits)
        std::cout<<a;
    return 0;
}
#include <iostream>
int get(int n)
{
    if(n <= 0)
        return 2;
    else
        return 3+get(n-1);
}
int sum(int n)
{
    int result = 0;
    for(int i=0;i<n;i++)
        result+=get(i);
    return result;
}
int main()
{
    int n;
    while(std::cin>>n)
    {
        std::cout<<sum(n)<<std::endl;
    }
}
#include<iostream>
int main()
{
    int num;
    std::cin>>num;
    int money = 100;
    int count = 100;
    int xm=money/5;
    for(int i=0;i<=xm;i++)
    {
        int a = money-i*5;
        int ym=a/3;
        for(int j=0;j<ym;j++)
        {
            a = money-i*5-j*3;
            int z = a*3;
            if(i+j+z == 100)
                std::cout<<i<<" "<<j<<" "<<z<<std::endl;
        }
    }
    return 0;
}
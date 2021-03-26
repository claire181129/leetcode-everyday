#include <iostream>
int pickSeven(int n)
{
    int count = 0;
    #ifdef DEBUG
        std::cout<<"n:"<<n<<std::endl;
    #endif
    for(int i=1;i<=n;i++)
    {
        if(i %7 == 0)
            count++;
        else
        {
            int temp = i;
            while(temp>0)
            {
                int a = temp-temp/10*10;
                #ifdef DEBUG
                    std::cout<<"temp:"<<temp<<" a:"<<a<<std::endl;
                #endif
                if(a == 7)
                {
                    count++;
                    break;
                }
                temp = temp/10;
            }
        }
        #ifdef DEBUG
            std::cout<<"loop:"<<i<<" count:"<<count<<std::endl;
        #endif
    }
    return count;
}
int main()
{
    int n = 0;
    while(std::cin>>n)
    {
        std::cout<<pickSeven(n)<<std::endl;
    }
    return 0;
}
/*
case:
20
10
anwser:
3
1
trace
7,17,14
7
*/
#include <iostream>
bool isAutomorphic(int n)
{
    int x = n*n;
    while(n)
    {
        int a = x-x/10*10;
        int b = n-n/10*10;
        #ifdef DEBUG
            std::cout<<"n:"<<n<<" a:"<<" x:"<<x<<" b:"<<b<<std::endl;
        #endif
        if(a != b)
        {
            return false;
        }
        x = x/10;
        n = n/10;
    }
    return true;
}
int main()
{
    int n=0;
    while(std::cin>>n)
    {
        int count = 0;
        for(int i=0;i<=n;i++)
        {
            if(isAutomorphic(i))
                count++;
        }
        std::cout<<count<<std::endl;
    }
    return 0;
}
/*
fail case:
5
anwser:
3
my anwser:
2
trace:
5*5 = 25, true
4*4 = 16, false
3*3 = 9, false
2*2 = 4, false
1*1 = 1, true
0*0 = 0, true
*/
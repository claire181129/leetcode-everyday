#include <iostream>
#include <string>
#include <vector>
void printNiches(int m)
{
    int cube = m*m*m;
    int n = m;
    int anwser = cube-n*(n-1);
    int first = anwser/n;
    for(int i=0;i<n;i++)
    {
        std::cout<<first+i*2;
        if(i != n-1)
            std::cout<<"+";
    }
    std::cout<<std::endl;
}
int main()
{
    int m;

    while(std::cin>>m)
    {
        //std::cout<<"m:"<<m<<std::endl;
        printNiches(m);
    }
    return 0;
}
/*
input:
6
output:
31+33+35+37+39+41

trace:
6*6*6 = 36*6 = 216

intput:
0
output:
-1 1

trace:
n*num
num1*n+2+4+...+(n-1)*2 = num1*n + n*(n-1)

case: 31+33+35+37+39+41
n = 6
31*6+1+2+3+4+5

216-6*5 = 216-30 = 186
186 / 6 = 31
n = 1
216 - 1*0 = 216
216/6 = 36 



*/
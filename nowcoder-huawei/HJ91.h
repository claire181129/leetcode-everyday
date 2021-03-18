#include <iostream>
#include <vector>
int countSolution(int x, int y, int n, int m)
{
    if(x>n || y>m)
        return 0;
    else if(x == n && y == m)
    {
        return 1;
    }
    else
    {
        return countSolution(x+1,y,n,m)+countSolution(x,y+1,n,m);
    }
}
int solutions(int n,int m)
{
    std::cout<<"solutions  n*m:"<<n<<"*"<<m<<std::endl;
    int x = 0, y = 0;
    return countSolution(x,y,n,m);
}
int main()
{
    int n=0, m=0;
    while(std::cin>>n>>m)
    {
        std::cout<<solutions(n,m)<<std::endl;
    }
    return 0;
}
/*
case:
2 2
1 2
anwser:
6
3
trace:
 - -
| | |
 - -
| | |
 - -
 2*2 -> 3*3
 1*2 -> 2*3

n*m -> array[n+1][m+1]
go from (0,0) to (n,m)

(0,0)
    x+1<3, (1,0)
        x+1<3, (2,0)
            x+1=3 Invalid
            y+1<3, (2,1)
                x+1=3, Invalid
                y+1<3, (2,2) Valid
        y+1<3, (1,1)
        
    y+1<3
    (0,1)

*/
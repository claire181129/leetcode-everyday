#include <iostream>
bool isPrimer(int a)
{
    if(a == 2)
        return true;
    for(int i=2;i<a;i++)
    {
        if(a%i == 0)
            return false;
    }
    return true;
}
void getClosestSum(int n, int& a, int& b)
{
    int smallest = -1;
    for(int i = n-1;i>=2;i--)
    {
        if(isPrimer(i) && isPrimer(n-i))
        {
            int diff;
            if(i>n-i)
                diff = i-(n-i);
            else
                diff = n-i-i;
            if(smallest = -1)
                smallest = diff;
            else if(smallest>diff)
                smallest = diff;
        }

    }
}
int main()
{
    int n;
    while(std::cin>>n)
    {
        int a,b;
        getClosestSum(n,a,b);
        std::cout<<a<<std::endl;
        std::cout<<b<<std::endl;
    }
}

/*
case:
20
anwser:
7
13

trace:
oinput is a number(a),output is two number(b,c), one line per number.
a = b+c
b,c is prime number.
|b-c| is the smallest
so, it's a, b(<a), a-b

loop from a-1 to 2
    if primer
        a- still primer
            record difference value if it's smaller

note: 
1. this loop will cause extra compute, a+b, b+a, will compute twice
*/
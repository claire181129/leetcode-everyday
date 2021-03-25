#include <iostream>
#include <cmath>
void findInterval(double n, double &a, double &b)
{
    //suppose n is positive
    double interval = 1;
    if(n<1)
    {
        interval = 0.1;
    }
    double leftBegin = 0;
    double rightBegin = n;
    if(n<1)
    {
        rightBegin = 1;
    }
    for(double i=leftBegin;i<=rightBegin;i+=interval)
    {
        double temp = n-i*i*i;
        if(temp>=0)
        {
            a = i;
        }
        else
            break;
    }
    for(double i=rightBegin;i>=leftBegin;i-=interval)
    {
        double temp = i*i*i-n;
        if(temp>=0)
        {
            b = i;
        }
        else
            break;
    }
    #ifdef DEBUG
        std::cout<<"n:"<<n<<" a:"<<a<<" b:"<<b<<std::endl;
    #endif
}
double getCubicRoot(double n)
{
    bool negative = false;
    if(n<0)
    {
        negative = true;
        n = -n;
    }

    double a = 0, b = 0;
    findInterval(n,a,b);
    double difference = n-a*a*a;
    double anwser = a;
    for(double i=a;i<=b;i+=0.1)
    {
        double temp = n-i*i*i;
        #ifdef DEBUG
            std::cout<<"temp:"<<temp<<" i:"<<i<<" difference:"<<difference<<" anwser:"<<anwser<<std::endl;
        #endif
        if(temp<0)
            temp = -temp;
        if(temp<difference)
        {
            difference = temp;
            anwser = i;
        }
    }
    if(negative)
    {
        anwser = -anwser;
    }
    return anwser;
}
int main()
{
    double n;
    //std::cout<<"std::cbrt:"<<std::cbrt(0.0056)<<std::endl;
    while(std::cin>>n)
    {
        double a = getCubicRoot(n);
        printf("%0.1f\n",a);
        #ifdef DEBUG
            std::cout<<"std::cbrt:"<<std::cbrt(n)<<std::endl;
        #endif
    }
    return 0;
}
/*
case:
216
anwser:
6.0

trace:
for x, y*y*y = x
x,y
y in (y0,y1)
y is double, has one point


case:
-0.07
anwser:
-0.4
trace:
suppose 0.07
0.1^3 = 0.001
0.2^3 = 0.008
0.3^3 = 0.009
0.4^3 = 0.064
0.5^3 = 0.125
0.6^3 = 0.216
0.7^3 = 0.343

case:
0.056
anwser:
0.177581
trace:
0.5^3 = 0.125
0.4^3 = 0.064
0.3^3 = 0.009
0.2^3 = 0.008
0.1^3 = 0.001

case:
2.1
anwser:
1.28058
trace:
1^3 = 1
2^3 = 8
1.1^3 = 1.331
1.2^3 = 1.728
1.3^3 = 2.197
*/
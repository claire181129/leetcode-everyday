#include <iostream>

float changePrecision(float number,int n)
{
    int m = 1;
    for(int i=0;i<n;i++)
    {
        m*=10;
    }
    int itemp = number*m;
    float ftemp = itemp;
    number = ftemp/m;
    return number;
}

int main()
{
    int n;
    while(std::cin>>n)
    {
        float height = n, length = 0, bounce = 0;
        int i = 0;
        while(i<5)
        {
            length += height + bounce;
            bounce = height/2;
            // method 1: keep precision always
            bounce = changePrecision(bounce,6);
            height = bounce;
            i++;
        }
        // method 2: keep precision only when give out result
        //bounce = changePrecision(bounces,6);
        //length = changePrecision(lengh,6);
        std::cout<<length<<"\r\n"<<bounce<<std::endl;
    }
    return 0;
}
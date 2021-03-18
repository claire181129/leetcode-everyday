#include <iostream>
#include <string>
int dayOfMonth(int year, int month)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(year%100 == 0)
                if(year%400 == 0)
                    return 29;
                else
                    return 28;
            else
                if(year%4 == 0)
                    return 29;
                else
                    return 28;
        default:
            return 0;  
    }
}
int dayOfYear(int year,int month,int day)
{
    int result = day;
    for(int i=1;i<month;i++)
    {
        result+=dayOfMonth(year,i);
    }
    return result;
}
int main()
{
    int year = 0, month = 0, day = 0;
    while(std::cin>>year>>month>>day)
    {
        std::cout<<dayOfYear(year,month,day)<<std::endl;
    }
    return 0;
}
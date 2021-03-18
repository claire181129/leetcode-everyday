#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    while(std::cin>>count)
    {
        std::vector<int> numbers;
        int negtive = 0;
        int positive = 0;
        double avg = 0;
        for(int i=0;i<count;i++)
        {
            int temp;
            std::cin>>temp;
            numbers.push_back(temp);
            if(temp<0)
                negtive++;
            else if(temp>0)
            {
                avg+=temp;
                positive++;
            }
        }
        avg /= positive;

        std::cout<<negtive<<" ";
        printf("%.1f\n",avg);
    }
    return 0;
}
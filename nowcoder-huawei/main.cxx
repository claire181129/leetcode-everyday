#include <iostream>
#include <vector>
struct Choice{
    int price;
    int importance;
    int flag;
    int choose_flag;//0 = not decided, 1 = choosed, -1 = not choosed
};
int get_choose_index(std::vector<Choice> list)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].choose_flag == 0)
        {
            return i;
        }
    }
    return -1;
}
int get_main_index(std::vector<Choice> list, int index)
{
    int count = 0;
    for(int i=0;i<list.size();i++)
    {
        if(list[i].flag == 0)
        {
            count+=1;
            if(count == index)
            {
                return i;
            }
        }
    }
}
int bestPurchaseList(std::vector<Choice> list, int money)
{
    int best;
}
int main()
{
    int money, count;
    while(std::cin>>money>>count)
    {
        std::vector<Choice> purchaseList;
        while(count>0)
        {
            Choice temp;
            std::cin>>temp.price>>temp.importance>>temp.flag;
            temp.choose_flag = 0;
            purchaseList.push_back(temp);
            count--;
        }
        int bestresult = bestPurchaseList(purchaseList,money);
        std::cout<<bestresult<<std::endl;
    }
    return 0;
}
/*
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

2200

choices -> final choose

choice make up algorithm:
sum <= money
if it's a sub thing, it's main thing is in the plan

choose algorithm:
v[i]*h[j] is the max

1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
plan A: 800*1           importance = 800*2 = 1600
plan B: 400*1           importance = 400*3 = 800
plan C: 500*1           importance = 500*2 = 1000
plan D: 400*1 + 500*1   importance = 400*3+500*2 = 2200

plan D is the best choice

the limit is changed after every choice made, choices need to refer to each other.
800 choosed + 800 not choosed = all solutions
800 choosed -> no choice, return the sum of this solution
800 not choosed -> have choice, return recursive function call.

800 2 0 choose
400 5 1 not choose
300 5 1 not choose
400 3 0 not choose
500 2 0 not choose

800 2 0 not choose
400 5 1 not choose
300 5 1 not choose
400 3 0 not choose
500 2 0 not choose

800 2 0 not choose
400 5 1 not choose
300 5 1 not choose
400 3 0 choose
500 2 0

800 2 0 not choose
400 5 1 not choose
300 5 1 not choose
400 3 0 not choose
500 2 0

choose algorithm:
1. price <= money
2. main or main choosed

2000 10

500 1 0 500 109             3
300 5 1     133.3           4   
400 5 1     150             8

400 4 0 100                 2   y
200 5 0 40                  1   y

320 2 0 160     135.5       5   y
500 4 5 136.6               6
400 3 5 144                 7

400 4 0 100                 2   y
410 3 0 136.6               6

200*5+400*4+400*4+500*1+300*5=1000+1600+1600+1500=5700
200*5+400*4+400*4+320*2+500*4 = 

right solution is:
2000 10
500 1 0 n
400 4 0 y
300 5 1 n
400 5 1 n
200 5 0 y
500 4 5 y
400 4 0 y
320 2 0 n
410 3 0 y
400 3 5 n
200*5 + 400*4 + 400*4 + 500*4 + 410*3 = 7430
1910

code trace：2000 10
500 1 0
400 4 0
300 5 1
400 5 1
200 5 0
500 4 5
400 4 0
320 2 0
410 3 0
400 3 5


fun 1:
choose_index = 0;

*/
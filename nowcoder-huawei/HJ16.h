#include <iostream>
#include <string>
#include <vector>
struct Thing{
    int price = 0;
    int importance = 0;
    int id = 0;
};
int bestSolution(std::vector<Thing> things, int money)
{
    std::vector<Thing> solution;
    int best = 0;
    auto size = things.size();
    if(size == 1)
    {
        if(things[0].price<=money)
            best = things[0].importance*things[0].price;
        else
            best = 0;
    }
    else if(size == 0)
        best = 0;
    else
    {
        //case 1: choose first as solution
        if(things[0].price<=money)
        {
        }
        //case 2: not choose first as solution

    }
    std::cout<<"result best:"<<best<<std::endl;
    return best;
}
int main()
{
    int money, count;
    
    while(std::cin>>money>>count)
    {
        std::vector<Thing> things;
        for(int i=0;i<count;i++)
        {
            Thing thing;
            std::cin>>thing.price>>thing.importance>>thing.id;
            things.push_back(thing);
        }
        for(auto it:things)
            std::cout<<it.price<<" "<<it.importance<<" "<<it.id<<std::endl;
        std::cout<<bestSolution(things,money)<<std::endl;
    }
    return 0;
}
//1h44m, quit
/*

1600 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

1600 5
800 2 0
600 5 1
300 5 1
400 3 0
500 2 0

800*2
    800*2 + 600*5 End = 4600
    800*2 + 300*5
        800*2 + 300*5 + 400*3 End = 4300 *BEST*
        800*2 + 300*5 + 500*2 End = 4100
    800*2 + 400*3 End = 2800
    800*2 + 500*2 End = 2600
400*3
    400*3+500*2
500*2
*/
#include <iostream>
#include <string>
int computeStringDistance(std::string src, std::string target)
{
    auto size1 = src.size();
    auto size2 = target.size();
    int index = 0;
    //delete in src
    
}
int main()
{
    std::string src,target;
    while(std::cin>>src>>target)
    {
        std::cout<<computeStringDistance(src,target)<<std::endl;
    }
    return 0;
}

/*
1. src->target, target->src, the distance is same
2. there's no situation that delete insert can compose better solution than replace
3. suppose no delete insert, just replace, n different, m*2 switch, result distance is n-1-m

delete&insert must be twice*n, but replace n-1, when n<1, 2*n<n-1, so no situation.

so case will be divide into:
1. same
2. diffirent
    2.1 replace - no replace
    2.2 delete - no delete
    2.3 insert - no insert

how to make sure the work is complete
case : abcde, acbdf
char by char, in range
there's one string is unchanged, so no need to check that string

first insert char in target that src don't have,so after this, target contain no char src don't have
then delete char in src that target don't have
c in src[abcde]
    c = a
        1. c is in target
            1.1 c is in same place with target
                END: no change
            1.2 c is in different place with target
                1.2.1 need replace
                    1.2.1.1  
        2. c is not in target, 
            END: delete
1. delete: how to delete in src, how to make sure it's extra? 
    string -> char, count
    no char, delete
    char count bigger, delete
2. insert: how to insert in src? 
    char, count
    no char, insert
    char count smaller, insert
3. 

*/
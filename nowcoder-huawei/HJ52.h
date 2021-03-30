#include <iostream>
#include <string>
#include <cassert>

int computeLevenshteinDistance(std::string &src, std::string &target)
{
    #ifdef DEBUG
        std::cout<<"src:"<<src<<std::endl;
        std::cout<<"target:"<<target<<std::endl;
    #endif
    auto size1 = src.size();
    auto size2 = target.size();
    auto size = size1;
    if(size<size2)
        size = size2;
    int index = 0;
    int distance = 0;
    while(index<size)
    {
        if(index>=size1 && index<size2)
        {
            #ifdef DEBUG
                std::cout<<"\ttarget longer than src, insert to src, index:"<<index<<std::endl;
            #endif
            src.append(1,target[index]);
            distance++;
        }
        else if(index<size1 && index>=size2)
        {
            #ifdef DEBUG
                std::cout<<"\tsrc longer than target, delete src,index:"<<index<<std::endl;
            #endif
            src.erase(index,1);
            distance++;
            index--;
        }
        else if(src[index]!=target[index])
        {
    //4.1 if next char1 == char2, delete, if src move one character forward, src and target have more common characaters
    //4.2 if char1 == next char2, insert, if src move one character backward, src and target have more common characters
    //4.3 if next char1 == next char2, replace, if src don't move, src and target have more common characters, things are getting more and more interesting!
            int next_src_index = (index+1<size1)?index+1:-1, next_target_index = (index+1<size2)?index+1:-1;
            
            if(next_src_index == -1 && next_target_index != -1)
            {
                #ifdef DEBUG
                        std::cout<<"\tsrc have no next char, ";
                #endif
                if(src[index] == target[next_target_index])
                {
                    #ifdef DEBUG
                        std::cout<<"insert "<<std::string(1,target[index])<<std::endl;
                    #endif
                    src.insert(index,1,target[index]);
                    distance++;
                }
                else{
                    #ifdef DEBUG
                        std::cout<<"replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                    #endif
                    src[index] = target[index];
                    distance++;
                }
            }
            else if(next_src_index != -1 && next_target_index == -1)
            {
                #ifdef DEBUG
                        std::cout<<"\ttarget have no next char, ";
                #endif
                if(src[next_src_index] == target[index])
                {
                    #ifdef DEBUG
                        std::cout<<"delete "<<std::string(1,src[index])<<std::endl;
                    #endif
                    src.erase(index,1);
                    distance++;
                    index--;
                }
                else{
                    #ifdef DEBUG
                        std::cout<<"replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                    #endif
                    src[index] = target[index];
                    distance++;
                }
            }
            else if(next_src_index == -1 && next_target_index == -1)
            {
                #ifdef DEBUG
                        std::cout<<"\tneither have next char, replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                #endif
                src[index] = target[index];
                distance++;
            }
            else
            {
                int insert_common_count = 0;
                int delete_common_count = 0;
                int replace_common_count = 0;
                if(src[next_src_index] == target[index])
                {
                    for(int i=index;i<size1&&i<size2;i++)
                    {
                        if(src[i+1] == target[i])
                            delete_common_count++;
                    }
                }
                else if(src[index] == target[next_target_index])
                {
                    for(int i=index;i<size1&&i<size2;i++)
                    {
                        if(src[i] == target[i+1])
                            insert_common_count++;
                    }
                }
                else{
                    for(int i=index;i<size1&&i<size2;i++)
                    {
                        if(src[i] == target[i])
                            replace_common_count++;
                    }
                }
                #ifdef DEBUG
                    std::cout<<"\tdelete_count:"<<delete_common_count<<" insert_count:"<<insert_common_count<<" replace_count:"<<replace_common_count<<std::endl;
                #endif
                #ifdef DEBUG
                        std::cout<<"\tboth have next char,index:"<<index<<" ";
                #endif
                if(delete_common_count>insert_common_count && delete_common_count>replace_common_count)
                {
                    #ifdef DEBUG
                        std::cout<<"delete "<<std::string(1,src[index])<<std::endl;
                    #endif
                    src.erase(index,1);
                    distance++;
                    index--;
                }
                else if(insert_common_count>delete_common_count && insert_common_count>replace_common_count)
                {
                    #ifdef DEBUG
                        std::cout<<"insert "<<std::string(1,target[index])<<std::endl;
                    #endif
                    src.insert(index,1,target[index]);
                    distance++;
                }
                else
                {
                    #ifdef DEBUG
                        std::cout<<"replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                    #endif
                    src[index] = target[index];
                    distance++;
                }
            }
        }
        index++;
        size1 = src.size();
        size2 = target.size();
        size = size1;
        if(size2>size)
            size = size2;
    }
    #ifdef DEBUG
        std::cout<<"src:"<<src<<std::endl;
        std::cout<<"target:"<<target<<std::endl;
    #endif
    return distance;
}
int computeStringDistance(std::string src, std::string target)
{
    #ifdef DEBUG
        std::cout<<"src:"<<src<<" target:"<<target<<std::endl;
    #endif
    int distance = 0;
    auto size1 = src.size();
    auto size2 = target.size();
    int index = 0;
    std::string str1;
    std::string str2;
    auto size = size1;
    if(size>size2)
        size = size2;
    for(int i=0;i<size;i++)
    {
        if(src[i] != target[i])
        {
            str1.append(1,src[i]);
            str2.append(1,target[i]);
        }
    }
    if(size1>size2)
    {
        for(int i=size2;i<size1;i++)
            str1.append(1,src[i]);
    }
    else if(size<size2)
    {
        for(int i=size1;i<size2;i++)
            str2.append(1,target[i]);
    }
    #ifdef DEBUG
        std::cout<<"after remove matched char, src:"<<str1<<" target:"<<str2<<std::endl;
    #endif
    if(str1.size() == 0 && str2.size() == 0)
        distance = 0;
    else
    {

    }
    return distance;
}
int main()
{
    std::string src,target;
    while(std::cin>>src>>target)
    {
        std::cout<<computeLevenshteinDistance(src,target)<<std::endl;
        assert(src == target);
    }
    return 0;
}

/*
new question: compute XXXDistance
XXXDistance:
1. delete a character
2. insert a character
3. switch two character

input: abcdefg, abcdef
input: abcde, abcdf
input: abcde, bcdef

1. delete
2. insert
3. replace

how to decide delete/insert/replace?
1. char == char, not changed
2. no char, char, insert
3. char, no char, delete
4. char != char
    4.1 if next char1 == char2, delete
    4.2 if char1 == next char2, insert
    4.3 if next char1 == next char2, replace

input: abcdefg, abcdef
distance = 1
index = 0, a == a
index = 1, b == b
...
index = 6, g != null, delete, distance ++
output: 1

input: abcde, abcdf
index = 0, a == a
...
index = 4, e != f, both no next char, so replace, distance ++
output: 1

input: abcde, bcdef
index = 0, a != b, a!=c, b!=c,b==b, delete, distance++
bcde, bcdef
index = 1, c == c
index = 2, d == d
...
index = 4, null != f, insert, distance++
output: 2

input: abcd, abecd

input: abdf,cdf
delete a, bdf-cdf, replace b with c, distance = 2
replace a with c, cbdf-cdf, delete b, distance = 2

case:
ixfkieaaocalmxhfifyadnouljtezrnpnfoenespcaenyvzcjtppsaxegmeytqrkvdwugvouskcnnqnmhepquncvyvgkansquaotkgvlvplktrabaikeuubfupunpztpvvzdqaqgfmtzxlcxsipltzwjegpqjzclclvjsmqbmiyzvcujpvhupyhvhhjq
ganxioafstgdpceecubqrngumbpjvwxdpzmragsunvfnmejbcvsoydtbbewybygpsmmyjuvezn
ixotitbgzoknoghrrjjwageedzjaghsjvqeqptfphqkvdtevqjjxqgdwfqunvxpxthzzjeprbcvmyphduapyoargbqmizivhfryqdonlritniosmdvuiyhdoykojzvauymskrzrncufasqzuerdehpqceclpbjtvbebuullzaqtokgkfzznumkvvdgwvuiacetbcbmbcrdoemcfjbuw
nqbgetlzozptuajfmvpzqqkuuxrwlhjcuyohpcnzpgkgmieuuavdetngrrxlxfauugyccklhjbsdqriznggbgvmcbamzdtdffpujnxhosgvbllnyoqpvuamsylyxtpqhcbfxhrdznwswmcxhvmrhttipapeshhdzjpmkucwqtztfsyxzwupmdgmlcatlqqwglekqmrojldjfjmthmiriyyavtznlosbixdtjxsjtzfyvvvwsqqfpmxbnkzwotuelfqjlctoaobu
anwser:
153
225

case:
ixfkieaaocal
ixotitbgzokn
anwser：
ixokieaaocal
ixotitbgzokn

ixotieaaocal
ixotitbgzokn

ixotitaaocal
ixotitbgzokn

ixotitbaocal
ixotitbgzokn

ixotitbgocal
ixotitbgzokn

ixotitbgzocal
ixotitbgzokn

ixotitbgzokal
ixotitbgzokn

ixotitbgzoknl
ixotitbgzokn

ixotitbgzokn
ixotitbgzokn

case:
ganxioafstgdpceecubqrngumbpjvwxdpzmragsunvfnmejbcvsoydtbbewybygpsmmyjuvezncnnhpucygasuokvvltaakubuuptvzqqftxcsptwepjccvsqmyvuphphhj
ganxioafstgdpceecubqrngumbpjvwxdpzmragsunvfnmejbcvsoydtbbewybygpsmmyjuvezn
*/
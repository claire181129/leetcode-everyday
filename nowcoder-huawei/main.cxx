#include <iostream>
#include <string>
int computeLevenshteinDistance(std::string src, std::string target)
{
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
            src.append(1,target[index]);
            distance++;
        }
        else if(index<size1 && index>=size2)
        {
            src.erase(index,1);
            distance++;
        }
        else if(src[index]!=target[index])
        {
    //4.1 if next char1 == char2, delete
    //4.2 if char1 == next char2, insert
    //4.3 if next char1 == next char2, replace
            int next_src_index = (index+1<size1)?index+1:-1, next_target_index = (index+1<size2)?index+1:-1;
            if(next_src_index == -1 && next_target_index != -1)
            {
                #ifdef DEBUG
                        std::cout<<"\t src have no next char, ";
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
                    char temp = target[index];
                    target[index] = src[index];
                    src[index] = temp;
                    distance++;
                }
            }
            else if(next_src_index != -1 && next_target_index == -1)
            {
                #ifdef DEBUG
                        std::cout<<"\t target have no next char, ";
                #endif
                if(src[next_src_index] == target[index])
                {
                    #ifdef DEBUG
                        std::cout<<"delete "<<std::string(1,src[index])<<std::endl;
                    #endif
                    src.erase(index,1);
                    distance++;
                }
                else{
                    #ifdef DEBUG
                        std::cout<<"replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                    #endif
                    char temp = target[index];
                    target[index] = src[index];
                    src[index] = temp;
                    distance++;
                }
            }
            else if(next_src_index == -1 && next_target_index == -1)
            {
                #ifdef DEBUG
                        std::cout<<"\t neighter have next char, replace:"<<std::string(1,src[index])<<" with "<<std::string(1,target[index])<<std::endl;
                #endif
                char temp = target[index];
                target[index] = src[index];
                src[index] = temp;
                distance++;
            }
            else
            {
                #ifdef DEBUG
                        std::cout<<"\t both have next char, ";
                #endif
                if(src[next_src_index] == target[index])
                {
                    #ifdef DEBUG
                        std::cout<<"delete "<<std::string(1,src[index])<<std::endl;
                    #endif
                    src.erase(index,1);
                    distance++;
                }
                else if(src[index] == target[next_target_index])
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
                    char temp = target[index];
                    target[index] = src[index];
                    src[index] = temp;
                    distance++;
                }
            }
        }
        index++;
        size1 = src.size();
        size2 = target.size();
    }
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
*/
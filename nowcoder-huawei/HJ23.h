#include <iostream>
#include <string>
#include <vector>
#include <map>

void deleteChar(char c,std::string &str)
{
    //std::cout<<"delete char:"<<std::string(1,c)<<" str:"<<str<<std::endl;
    auto size = str.size();
    int i=0;
    while(i<size)
    {
        if(str[i] == c)
        {
            str.erase(str.begin()+i);
            size = str.size();
        }
        else
            i++;
    }
    //std::cout<<"after delete:"<<str<<std::endl;
}
void printLeastCharacter(std::string str)
{
    auto size = str.size();
    std::map<char,int> charCounter;
    for(int i=0;i<size;i++)
    {
        auto m = charCounter.size();
        //std::cout<<"char: "<<str[i]<<" ";
        if(charCounter.find(str[i])!=charCounter.end())
        {
            
            charCounter[str[i]]++;
            //std::cout<<" found :"<<charCounter[str[i]]<<std::endl;
        }
        else
        {
            charCounter[str[i]] = 1;
            //std::cout<<" not found :"<<charCounter[str[i]]<<std::endl;
        }
    }
    
    auto m = charCounter.size();
    //std::cout<<"charCounter size:"<<m<<std::endl;
    for(auto it:charCounter)
    {
        //std::cout<<it->first<<" "<<it->second<<std::endl;
        bool smallest = true;
        for(auto itt:charCounter)
        {
            //std::cout<<charCounter.at(i)<<" "<<charCounter[j]<<std::endl;
            if(it.second>itt.second)
            {
                smallest = false;
                break;
            }
        }
        if(smallest)
            deleteChar(it.first,str);
    }
    std::cout<<str<<std::endl;
    
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        printLeastCharacter(str);
    }
    return 0;
}
/*
case1 
input:
abcdd
aabcddd
output: 
a,1
b,1
c,1
d,2
1=1=1<2
delete a,b,c
result:dd

a,2
b,1
c,1
d,3
1=1<2<3
delete b,c
result: aaddd

string -> [char c - int numC, ...  ]
compare [numC]
select to delete from string
*/
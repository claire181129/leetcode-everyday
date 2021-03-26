#include <iostream>
#include <string>
#include <vector>
void sort(std::string &str)
{
    std::string chars;
    std::vector<int> counts;
    auto size = str.size();
    for(int i=0;i<size;i++)
    {
        #ifdef DEBUG
            std::cout<<"loop: "<<i;
        #endif
        auto index = chars.find(str.substr(i,1));
        if(index==std::string::npos)
        {
            chars.append(1,str[i]);
            counts.push_back(1);
            #ifdef DEBUG
                std::cout<<" push char:"<<str.substr(i,1)<<" counts size:"<<counts.size()<<std::endl;
            #endif
        }
        else
        {
            counts[index]++;
            #ifdef DEBUG
                std::cout<<" add count for index:"<<index<<" char:"<<chars.substr(index,1)<<std::endl;
            #endif
        }
    }
    #ifdef DEBUG
        for(int i=0;i<chars.size();i++)
        {
            std::cout<<chars.substr(i,1)<<" "<<counts[i]<<std::endl;
        }
    #endif
    for(int i=0;i<chars.size();i++)
    {
        for(int j=i+1;j<chars.size();j++)
        {
            if(counts[i]<counts[j])
            {
                char tempchar = chars[i];
                chars[i] = chars[j];
                chars[j] = tempchar;
                int tempint = counts[i];
                counts[i] = counts[j];
                counts[j] = tempint;
            }
            else if(counts[i] == counts[j])
            {
                if(chars[i]>chars[j])
                {
                    char tempchar = chars[i];
                    chars[i] = chars[j];
                    chars[j] = tempchar;
                }
            }
        }
    }
    str = chars;
}
int main()
{
    std::string str;
    while(std::cin>>str)
    {
        sort(str);
        std::cout<<str<<std::endl;
    }
    return 0;
}
/*
case:
aaddccdc
1b1bbbbbbbbb
anwser:
cda
b1
trace:
char c in [aaddccdc]
    c = a; a,1
    c = a; a,2
    c = d; a,2 d,1
    c = d; a,2 d,2
    c = c; a,2 d,2 c,1
    c = c; a,2 d,2 c,2
    c = d; c,2 d,3 c,2
    c = c; a,2 d,3 c,3
a,2 d,3 c,3
d,3 a,2 c,3
d,3 c,3 a,2

*/
#include <iostream>
#include <string>
std::string encryption(std::string key, std::string code)
{
    auto size = key.size();
    for(int i=0;i<size;i++)
    {
        if(key[i]>=97 && key[i]<=122)
            key[i] = key[i]-32;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(key[i] == key[j])
            {
                key.erase(j,1);
                j--;
                size--;
            }
        }
    }
    #ifdef DEBUG
        std::cout<<"\tduplicated removed key:"<<key<<std::endl;
    #endif
    char letter = 65;
    for(int i=0;i<26;i++)
    {
        if(key.find(std::string(1,letter)) == std::string::npos)
        {
            key.append(1,letter);
        }
        letter++;
    }
    #ifdef DEBUG
        std::cout<<"\tadded key:"<<key<<std::endl;
    #endif
    for(int i=0;i<code.size();i++)
    {
        if(code[i]>=65 && code[i]<=90)
        {
            int index = code[i]-65;
            #ifdef DEBUG
                std::cout<<"\ti:"<<i<<" "<<code[i]<<" "<<key[index]<<std::endl;
            #endif
            code[i] = key[index];
        }
        else if(code[i]>=97 && code[i]<=122)
        {
            int index = code[i]-32-65;
            #ifdef DEBUG
                std::cout<<"\ti:"<<i<<" "<<code[i]<<" "<<key[index]<<std::endl;
            #endif
            code[i] = key[index]+32;
        }
    }
    return code;
}
int main()
{
    std::string code,key;
    while(std::getline(std::cin,key))
    {
        std::getline(std::cin,code);
        #ifdef DEBUG
            std::cout<<"key:"<<key<<std::endl;
            std::cout<<"code:"<<code<<std::endl;
        #endif
        std::cout<<encryption(key,code)<<std::endl;
    }
    return 0;
}

/*
case:
nihao
ni
anwser:
le

case:
Attack AT DAWN
TRAILBLAZERS
anwser:
Tpptad TP ITVH

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
T R A I L B Z E S

NIHAOFGHIJKLMNOPQRSTUVWXYZ
*/
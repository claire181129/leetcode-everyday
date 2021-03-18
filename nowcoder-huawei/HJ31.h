#include <iostream>
#include <string>
#include <vector>
std::string traverse(std::string str)
{
    auto size = str.size();
    auto count = size/2;
    for(int i=0;i<count;i++)
    {
        char c = str[i];
        str[i] = str[size-i-1];
        str[size-i-1] = c;
    }
    return str;
}
int main()
{
    std::string str;
    std::getline(std::cin,str);
    auto size = str.size();
    std::vector<std::string> words;
    std::string word;
    for(int i=0;i<size;i++)
    {
        if((str[i]>=65 && str[i]<=90)or(str[i]>=97 && str[i]<=122))
        {
            word+= std::string(1,str[i]);
        }
        else
        {
            if(word.size()>0)
            {
                words.push_back(word);
                word = "";
            }
        }
    }
    if(word.size()>0)
    {
        words.push_back(word);
        word = "";
     }
    std::string result;
    auto count = words.size();
    for(int i=count-1;i>=0;i--)
    {
        result += words[i]+" ";//traverse(words[i])+" ";
    }
    result.erase(result.size()-1,1);
    std::cout<<result<<std::endl;
    return 0;
}
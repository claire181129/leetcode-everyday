#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string str;
    std::getline(std::cin,str);
    std::vector<std::string> words;
    std::string word;
    auto size = str.size();
    for(int i=0;i<size;i++)
    {
        if(str[i] == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word+=std::string(1, str[i]);
        }
    }
    words.push_back(word);
    str = "";
    size = words.size();
    for(int i=size-1;i>=0;i--)
    {
        str+=words[i]+" ";
    }
    str.erase(str.end()-1);
    std::cout<<str<<std::endl;
    return 0;
}
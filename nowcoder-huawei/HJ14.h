#include <iostream>
#include <string>
#include <vector>
void insert(std::vector<std::string> words,std::string word)
{
    auto size = words.size();

    if(words[0] > word)
    {
        words.insert(words.begin(),word);
        return;
    }
    else if(words[size-1] < word || size == 0)
    {
        words.push_back(word);
        return;
    }

    auto it = words.begin();
    for(int i=0;i<size;i++)
    {
        if(words[i]<word)
            it++;
    }
    words.insert(it,word);
}
int main()
{
    int n;
    std::vector<std::string> words;
    std::string str;
    while(std::cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            std::cin>>str;
            insert(words,str);
        }
    }
    for(auto word:words)
        std::cout<<word<<std::endl;
    return 0;
}
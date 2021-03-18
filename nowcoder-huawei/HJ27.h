#include <iostream>
#include <vector>
#include <string>

bool find_match(char a,std::string word, int* mark)
{
    int size = word.size();
    for(int i=0;i<size;i++)
        if((a == word[i]) &&(mark[i]==0))
        {
            mark[i] = 1;
            return true;
        }
    return false;
}
bool no_this_word(std::string word, std::vector<std::string> word_list)
{
    for(auto it:word_list)
    {
        if(word == it)
            return false;
    }
    return true;
}
void insert_in_sequence(std::string word, std::vector<std::string> &word_list)
{
    if(word_list.size() == 0)
    {
        word_list.push_back(word);
        return;
    }
        
    if(word<=word_list[0])
    {
        word_list.insert(word_list.begin(),word);
        return;
    } 
    size_t size = word_list.size();
    if(word>=word_list[size-1])
    {
        word_list.push_back(word);
        return;
    }
    for(int i=0;i<word_list.size()-1;i++)
    {
        if((word>word_list[i])&& (word<=word_list[i+1]))
        {
            word_list.insert(word_list.begin()+i+1,word);
            return;
        }
    }
        
}
int main()
{
    int word_num = 0, k = 0;
    std::string src_word;
    std::vector<std::string> word_list;
    
    std::cin>>word_num;
    std::string in_str;
    while(std::cin>>in_str)
    {
        word_list.push_back(in_str);
    }
    size_t word_count = word_list.size();
    
    if(word_count>1)
    {
        k = std::stoi(word_list[word_count-1]);
        src_word = word_list[word_count-2];
        word_list.pop_back();
        word_list.pop_back();
    }
    else
    {
        std::cout<<0<<std::endl;
        return 0;
    }
    size_t size = src_word.size();
    std::vector<std::string> in_sequence;
    for(auto it:word_list)
    {
        if((it.size() == size)and (it != src_word))
        {
            insert_in_sequence(it,in_sequence);
        }
    }
    std::vector<std::string> brother_list;
    int mark[in_sequence.size()][size];
    for(int i=0;i<in_sequence.size();i++)
        for(int j=0;j<size;j++)
            mark[i][j] = 0;
    for(int i=0;i<in_sequence.size();i++)
    {
        for(int j=0;j<size;j++)
        {
            if(!find_match(src_word[j],in_sequence[i],mark[i]))
                break;
        }
        bool flag = true;
        for(int j=0;j<size;j++)
        {
            if(mark[i][j]==0)
            {
                flag = false;
                break;
            }
        }
        if(flag)// and no_this_word(in_sequence[i],brother_list)
        {
            brother_list.push_back(in_sequence[i]);
        }
    }
    
    std::cout<<brother_list.size()<<std::endl;
    if(k<brother_list.size())
        std::cout<<brother_list[k-1]<<std::endl;
    return 0;
}
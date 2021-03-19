#include <iostream>
#include <vector>
#include <string>
/*
Command             Execute
reset               reset what
reset board         board fault
board add           where to add
board delete        no board at all
reboot backplane    impossible
backplane abort     install first          
he he               unknown command
input:
reset
reset board
board add
board delet
reboot backplane
backplane abort
output:
reset what
board fault
where to add
no board at all
impossible
install first

input:
r
res
reb
r b
ba
bo a
output:
reset what
reset what
unknown command
unknown command
unknown command
board add
*/
const std::vector<std::vector<std::string>> commandList{std::vector<std::string>{"reset"},
                                                    std::vector<std::string>{"reset","board"},
                                                    std::vector<std::string>{"board","add"},
                                                    std::vector<std::string>{"board","delete"},
                                                    std::vector<std::string>{"reboot","backplane"},
                                                    std::vector<std::string>{"backplane","abort"}
                                                };
const std::vector<std::string> executeCommands{"reset what","board fault","where to add","no board at all","impossible","install first"};

std::vector<std::string> splitKeywords(std::string str)
{
    std::string word;
    std::vector<std::string> words;
    auto size = str.size();
    for(int i=0;i<size;i++)
    {
        if(str[i] == ' ')
        {
            if(word.size()>0)
                words.push_back(word);
            word = std::string();
        }
        else
        {
            word.append(1,str[i]);
        }
    }
    if(word.size()>0)
        words.push_back(word);
    return words;
}
std::string matchCommands(std::vector<std::string> input)
{
    /*
range in keyword, index:i
    range in matched command list
        if ith keyword don't exist
            update matched command list
        if the ith keyword match
            match, continue
            no match, update matched command list
    end of range
    ith keyword have no match, END: record as unknown command
    check next keyword match situation
end of range
matched command list is empty, record as unkown command
matched command list is multi, record as unknown command
matched command list have only 1, record corespondng execute command*/
    auto size = input.size();
    std::vector<int> matchedCommand = {0,1,2,3,4,5};
    auto size2 = matchedCommand.size();

    for(int i=0;i<size;i++)
    {
        std::vector<int> updateMatchedCommand;
        for(int j=0;j<size2;j++)
        {
            int index = matchedCommand[j];
            auto command = commandList[index];
            if(i>=command.size())
            {
                //
                continue;
            }
            std::string keyword = command[i];
            if(keyword.find(input[i]) == std::string::npos)
                continue;
            else
            {
                updateMatchedCommand.push_back(index);
            }
        }
        matchedCommand = updateMatchedCommand;
        size2 = matchedCommand.size();
        std::cout<<"find "<<i<<"th keyword "<<input[i]<<" match:";
        for(auto it:matchedCommand)
            std::cout<<it<<" ";
        std::cout<<std::endl;
    }
    // note: remember to update size2
    if(size2 == 0 || size2>1)
        return "unknwon Command";
    else
        return executeCommands[matchedCommand[0]];

    return "null";
}
int main()
{
    std::string str;
    std::vector<std::string> output;
    while(std::getline(std::cin,str))
    {
        auto splited = splitKeywords(str);
        //for(auto it:splited)
        //    std::cout<<it<<",";
        //std::cout<<std::endl;
        auto temp = matchCommands(splited);
        output.push_back(temp);
    }
    //for(auto it:output)
    //    std::cout<<it<<std::endl;
    return 0;
}
/*
case:
reb
r

anwser:
unknown command
reset what

trace:
input: keywords backspace seperated
output: matched execute command, or uknown if no match
rule
1. keyword must be all matched, input keyword and command keyword
2. match must be unique

so first match first keyword, 
    if no match, END: unknown command
    if match, mark matched command
if have second keyword, find second keyword match in matched command
    if no match, END: unknown command
    if match, mark matched command
if have third keyword? ...
if no matched command, END: unknown command
if have multi matched command, END: unknown command
if only one matched command, return coresponding execute command

range in keyword, index:i
    range in matched command list
        if ith keyword don't exist
            update matched command list
        if the ith keyword match
            match, continue
            no match, update matched command list
    end of range
    ith keyword have no match, END: record as unknown command
    check next keyword match situation
end of range
matched command list is empty, record as unkown command
matched command list is multi, record as unknown command
matched command list have only 1, record corespondng execute command

input:
r
res
reb
r b
ba
bo a
output:
reset what
reset what
unknown command
unknown command
unknown command
board add

r, 
    match r, reset, reset board, reboot backplane
    delete 2 keyword command,
    left 1 command
    END: return reset what
res, 
    find command with 1 keyword, reset
    res match reset? Yes, END: return reset what
reb,
    find command with 1 keyword, 


Command             Execute
reset               reset what
reset board         board fault
board add           where to add
board delete        no board at all
reboot backplane    impossible
backplane abort     install first      
*/
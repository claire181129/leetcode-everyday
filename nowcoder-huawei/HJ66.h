#include <iostream>
#include <vector>
#include <string>
std::string matchCommands(std::vector<std::string> input)
{
    return "null";
}
int main()
{
    std::vector<std::string> input;
    std::vector<std::string> commands;
    std::string str;
    
    while(std::cin>>str)
    {
        if(str!="\n")
        {
            input.push_back(str);
        }
        else
        {
            std::string command = matchCommands(input);
            commands.push_back(command);
            for(auto it:input)
                std::cout<<it<<" ";
            std::cout<<std::endl;
            input.clear();
        }
    }
    for(auto it:commands)
        std::cout<<it<<std::endl;
    return 0;
}
/*
case:
reb
r

anwser:
unknown command
reset what
*/
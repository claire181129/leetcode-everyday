#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> parameterParser(std::string str)
{
    auto size = str.size();
    std::string para;
    std::vector<std::string> result;
    for(int i=0;i<size;i++)
    {
        if(str[i] == ' ')
        {
            if(para.size()>0)
                result.push_back(para);
            para = "";
        }
        else if(str[i] == '"')
        {
            para = "";
            for(int j=i+1;j<size;j++)
            {
                if(str[j] == '"')
                {
                    if(para.size()>0)
                        result.push_back(para);
                    para = "";
                    break;
                }
                else
                {
                    para+=std::string(1,str[i]);
                }
            }
        }
        else
        {
            para += std::string(1,str[i]);
        }
    }
    if(para.size()>0)
        result.push_back(para);
    return result;
}
int main()
{
    std::string line;
    std::getline(std::cin,line);
    auto parameters = parameterParser(line);
    for(auto it:parameters)
        std::cout<<it<<std::endl;
    return 0;
}

/*
case1:
xcopy /s c:\\ d:\\
trace:
xcopy
/s
c:\\
d:\\



*/
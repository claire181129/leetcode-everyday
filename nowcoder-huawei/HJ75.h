#include <iostream>
#include <string>
int maxPublicString(std::string s1, std::string s2)
{
    auto size1 = s1.size();
    auto size2 = s2.size();
    int max_count = 0;
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
            if(s2[j] == s1[i])
            {
                int count = 1;
                while(i+count<size1 && j+count<size2)
                {
                    if(s1[i+count] == s2[j+count])
                        count++;
                    else
                        break;
                }
                if(count>max_count)
                    max_count = count;
            }
    }
    return max_count;
}
int main()
{
    std::string str1,str2;
    std::cin>>str1>>str2;
    std::cout<<maxPublicString(str1,str2)<<std::endl;
    return 0;
}
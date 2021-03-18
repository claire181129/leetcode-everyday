#include <iostream>
#include <string>
std::string secureLevel(int score)
{
    if(score>=90)
        return "VERY_SECURE";
    else if(score>=80)
        return "SECURE";
    else if(score>=70)
        return "VERY_STRONG";
    else if(score>=60)
        return "STRONG";
    else if(score>=50)
        return "AVERAGE";
    else if(score>=25)
        return "WEAK";
    else if(score>=0)
        return "VERY_WEAK";
    else
        return "";
}
int getSecureScore(std::string str)
{
    std::cout<<"getSecureScore in"<<std::endl;
    int character_score = 0;
    int length_score = 0;
    int number_score = 0;
    int symbol_score = 0;
    int bonus = 0;

    auto size = str.size();
    if(size<=4)
        length_score = 5;
    else if(size<=7)
        length_score = 10;
    else if(size>=8)
    {
        length_score = 25;
    }
    int upperCase = 0, lowerCase = 0, number = 0, symbol = 0;
    for(int i=0;i<size;i++)
    {
        if(str[i]>=65 && str[i]<=90)
            upperCase ++;
        else if(str[i]>=97 && str[i]<=122)
            lowerCase ++;
        else if(str[i]>=48 && str[i]<=57)
            number++;
        else
            symbol++;
    }
    if(upperCase == size || lowerCase == size)
    {
        character_score=10;
    }
    else if(upperCase>0 && lowerCase>0)
    {
        character_score=20;
    }
    if(number == 0)
        number_score = 0;
    else if(number==1)
        number_score = 10;
    else if(number>1)
        number_score = 20;
    if(symbol == 0)
        symbol_score = 0;
    else if(symbol==1)
        symbol_score = 10;
    else if(symbol>1)
        symbol_score = 20;
    if(character_score && number_score)
    {
        bonus = 2;
    }
    else if(character_score&& number_score && symbol_score)
    {
        if(character_score == 20)
            bonus = 5;
        else
            bonus = 3;
    }
    
    int total = character_score+ length_score+number_score+symbol_score+bonus;
    std::cout<<"total: "<<total<<" char:"<<character_score<<" symbol:"<<symbol_score<<" number:"<<number_score<<" length:"<<length_score<<" bonus:"<<bonus<<std::endl;
    return total;
}
int main()
{
    std::string str;
    std::cout<<"hi"<<std::endl;
    while(std::getline(std::cin,str))
    {
        std::cout<<str<<std::endl;
        auto total = getSecureScore(str);
        std::cout<<secureLevel(total)<<std::endl;
    }
    return 0;
}
/*
case1:
38$@NoNoNo
123
trace:

anwser:
VERY_SECURE
WEAK
95
25
*/
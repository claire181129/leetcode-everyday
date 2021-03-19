#include <string>
#include <iostream>
#include <vector>
bool noIllegalCharacter(std::string expression)
{
    auto size = expression.size();
    for(int i=0;i<size;i++)
    {
        if((expression[i] == '+')||(expression[i] == '-')||(expression[i] == '*')||(expression[i] == '/'))
        {
            continue;
        }
        else if((expression[i] == ')')||(expression[i] == '(')||(expression[i] == '[')||(expression[i] == ']')||(expression[i] == '{')||(expression[i] == '}'))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
std::string resolveBrackets(std::string expression, bool& legal)
{
    std::string resultExpression;
    if(legal == false)
        resultExpression = "";
    else
    {
        size_t index = expression.find_last_of("([{");
        if(index == std::string::npos)
        {
            index = expression.find_first_of(")]}");
            if(index == std::string::npos)
            {
                //return expression;
                resultExpression = expression;
            }
            else
            {
                legal = false;
                //return "";
                resultExpression = "";
            }
        }
        else
        {
            size_t end = expression.find_first_of(")]}");
            if((end<=index)||(end == index+1))
            {
                legal = false;
                //return "";
                resultExpression = "";
            }
            std::string substr = expression.substr(index+1,end-index-1);
            int result = computeExpression(substr,legal);
            if(legal == false)
            {
                //return "";
                resultExpression = "";
            }
            else
            {
                std::string insertstr = std::to_string(result);
                expression.insert(index,insertstr);
                expression.erase(index+insertstr.size(),end-index+1);
                return resolveBrackets(expression,legal);
            }
        }
    }
    std::cout<<"expression: "<<expression<<" after resolve:"<<resultExpression<<std::endl;
    return resultExpression;
}
int computeExpression(std::string expression, bool& legal)
{
    if(legal == false)
        return 0;
    //size_t index = expression.find_first_of("*/");
    return 12;
}
int main()
{
    std::string expression;
    while(std::cin>>expression)
    {
        bool flag= noIllegalCharacter(expression);
        expression = resolveBrackets(expression,flag);
        int num = computeExpression(expression,flag);
        if(flag)
            std::cout<<num<<std::endl;
        else
            std::cout<<"illegal"<<std::endl;
    }
}
/*
case:
-4+-+35
1*-/4

anwser:
legal, -39
illegal

conclusion:
extra -+ will be seen as symbol not operator, it's legal
extra *,/ is illegal

what's legal?
contain only legal character, and every character is meaningful, together compose a value or expression.
expression made of a series of operator and operand
legal operator: +,-,*,/,(),[],{}
+,-,*,/ operator must have two operand, operand can be expression or value
(),[],{} operator must have one operand, operand can be expression or value

check expression till illegal or compute finished
check has priority as with compute priority
1. () [] {}
2. * /
3. + -
*/
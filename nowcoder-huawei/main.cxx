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
        else if((expression[i]>=48) && (expression[i]<=57))
        {
            continue;
        }
        else
        {
            std::cout<<"illegal character:"<<std::string(1,expression[i])<<" "<<i<<std::endl;
            return false;
        }
    }
    return true;
}
int computeExpression(std::string expression, bool& legal)
{
    //suppose expression contain just *, -, +, /, number character
    std::cout<<"expression: "<<expression<<std::endl;
    int result = 0;
    if(legal == false)
    {
        std::cout<<"\t"<<"illegal expression"<<std::endl;
        result = 0;
    }
    else
    {
        size_t index = expression.find_first_of("*/");
        auto size = expression.size();
        if(index == std::string::npos)
        {
            std::cout<<"\t"<<" no * or / to compute"<<std::endl;
            //compute + or -
            index = expression.find_first_of("+-");
            if(index == std::string::npos)
            {
                result = std::stoi(expression);
            }
            else
            {
                //1. it's a symbol
                //2. it's a operator
                result = 12;
            }
        }
        else
        {
            //take left operand
            //1. +,-, invalid
            //2. number character
            //3. it's out of range
            int leftIndex = index-1;
            if(leftIndex<0)
            {
                std::cout<<"\t"<<" * or / is the first character, no left operand"<<std::endl;
                legal = false;
                result = 0;
            }
            else
            {
                if((expression[leftIndex] == '+')||(expression[leftIndex] == '-'))
                {
                    std::cout<<"\t"<<" + or - before * or /"<<std::endl;
                    legal = false;
                    result = 0;
                }
                else
                {
                    //have at least one number character, so left operand is not empty
                    int leftoperand = 0;
                    while((leftIndex>=0)&&(expression[leftIndex] >=48) &&(expression[leftIndex]>=57))
                    {
                        leftIndex--;
                    }
                    //1. out of range
                    //2. leftIndex is a operator
                    if(leftIndex >= 0)
                    {
                        leftIndex++;
                        leftoperand = std::stoi(expression.substr(leftIndex,index-leftIndex));
                    }
                    else
                    {
                        leftIndex = 0;
                        leftoperand = std::stoi(expression.substr(leftIndex,index-leftIndex));
                    }
                    int rightIndex = index+1;
                    //take right operand
                    //1. it's operator, + or - or * or /
                    //2. it's number character
                    //3. it's out of range
                    if(rightIndex>=size)
                    {
                        std::cout<<"\t"<<"* or / is the last operator, no right operand"<<std::endl;
                        legal = false;
                        result = 0;
                    }
                    else
                    {
                        if((expression[rightIndex] == '*')||(expression[rightIndex] == '/'))
                        {
                            std::cout<<"\t"<<" two * or / in serial, illegal"<<std::endl;
                            legal = false;
                            result = 0;
                        }
                        else// if((expression[rightIndex] == '+')||(expression[rightIndex] == '-'))
                        {
                            int negative = 1;
                            while((rightIndex<size)&&((expression[rightIndex] == '+')||(expression[rightIndex] == '-')))
                            {
                                if(expression[rightIndex] == '-')
                                    negative*=-1;
                                rightIndex++;
                            }
                            //1. out of range
                            //2. meet operator
                            //3. meet number character
                            if(rightIndex>=size)
                            {
                                std::cout<<"\t"<<" no number right to * or /"<<std::endl;
                                legal = false;
                                result = 0;
                            }
                            else if(expression[rightIndex] == '*' || expression[rightIndex] == '/')
                            {
                                    std::cout<<"\t"<<" * or / after some + or - after + or -"<<std::endl;
                                    legal = false;
                                    result = 0;
                            }
                            else
                            {
                                std::string tempstr(1,expression[rightIndex]);
                                while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                                {
                                    tempstr.append(1,expression[rightIndex]);
                                    rightIndex++;
                                }
                                rightIndex--;
                                int rightOperand = std::stoi(tempstr);
                                rightOperand*=negative;
                                std::string substr;
                                if(expression[index] == '*')
                                    substr = std::to_string(leftoperand*rightOperand);
                                else
                                    substr = std::to_string(leftoperand/rightOperand);
                                expression.insert(leftIndex,substr);
                                expression.erase(leftIndex+substr.size()+1,rightIndex-leftIndex+1);
                                result = computeExpression(expression,legal);
                            }
                        }
                    }
                }
            }
            
        }
    }
    return result;
}
std::string resolveBrackets(std::string expression, bool& legal)
{
    std::cout<<"expression: "<<expression<<std::endl;
    std::string resultExpression;
    if(legal == false)
    {
        std::cout<<"\t"<<"illegal expression"<<std::endl;
        resultExpression = "";
    }
    else
    {
        size_t index = expression.find_last_of("([{");
        if(index == std::string::npos)
        {
            
            index = expression.find_first_of(")]}");
            if(index == std::string::npos)
            {
                //return expression;
                std::cout<<"\t"<<"no brackets at all"<<std::endl;
                resultExpression = expression;
            }
            else
            {
                std::cout<<"\t"<<"no ([{ but have )]}"<<std::endl;
                legal = false;
                //return "";
                resultExpression = "";
            }
        }
        else
        {
            size_t end = expression.substr(index+1).find_first_of(")]}");
            if(end == std::string::npos)
            {
                std::cout<<"\t"<<"have ([{ but no )]}"<<std::endl;
                resultExpression = "";
                legal = false;
            }
            else{
                end+=index+1;
                if((end<=index)||(end == index+1))
                {
                    std::cout<<"\t"<<")]} appear before ([{ or it's empty"<<std::endl;
                    legal = false;
                    //return "";
                    resultExpression = "";
                }
                std::string substr = expression.substr(index+1,end-index-1);
                int result = computeExpression(substr,legal);
                if(legal == false)
                {
                    //return "";
                    std::cout<<"\t"<<"expression in bracket is illegal"<<std::endl;
                    resultExpression = "";
                }
                else
                {
                    std::cout<<"\t"<<"expression in bracket is:"<<substr<<std::endl;
                    std::string insertstr = std::to_string(result);
                    expression.insert(index,insertstr);
                    expression.erase(index+insertstr.size(),end-index+1);
                    //return resolveBrackets(expression,legal);
                    resultExpression = resolveBrackets(expression,legal);
                }
            }
        }
    }
    std::cout<<"after resolve:"<<resultExpression<<std::endl;
    return resultExpression;
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

suppose have a operator /+-
left operand may be:
1. 
*/
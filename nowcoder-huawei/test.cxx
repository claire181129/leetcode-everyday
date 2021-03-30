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
    #ifdef DEBUG
        std::cout<<"expression: "<<expression<<std::endl;
    #endif
    int result = 0;
    if(legal == false)
    {
        #ifdef DEBUG
            std::cout<<"\t"<<"illegal expression"<<std::endl;
        #endif
        result = 0;
    }
    else
    {
        // compute * or /
        size_t index = expression.find_first_of("*/");
        auto size = expression.size();
        if(index == std::string::npos)
        {
            #ifdef DEBUG
                std::cout<<"\t"<<" no * or / to compute"<<std::endl;
            #endif
            //compute + or -, no * or / operator
            index = expression.find_first_of("+-");
            if(index == std::string::npos)
            {
                //no any operator, it's a number
                #ifdef DEBUG
                    std::cout<<"\t no + or - operator found, expression is pure number, expression:"<<expression<<std::endl;
                #endif
                result = std::stoi(expression);
            }
            else
            {
                #ifdef DEBUG
                    std::cout<<"\t found + or - operator, index:"<<index<<std::endl;
                #endif
                //1. it's a symbol
                //2. it's a operator
                int leftIndex = index-1;
                //1. leftIndex<0, index == 0, it must be a symbol
                //2. leftIndex>=0, index>=0, must be a operator
                if(leftIndex<0)
                {
                    //1. leftIndex<0, index == 0, it must be a symbol, no leftoperand
                    #ifdef DEBUG
                        std::cout<<"\t leftIndex < 0, + or - is the first character, no left operand, leftIndex:"<<leftIndex<<std::endl;
                    #endif
                    int rightIndex = index+1;
                    while((rightIndex<size)&&(expression[rightIndex] >= 48)&&(expression[rightIndex]<=57))
                    {
                        rightIndex++;
                    }
                    //rightIndex will point to:
                    //1. rightIndex >= size, out of range
                    //2. rightIndex < size, meet not number character
                    if(rightIndex<size)
                    {
                        #ifdef DEBUG
                            std::cout<<"\t meet non number character, rightIndex:"<<rightIndex<<std::endl;
                        #endif
                        //2. rightIndex < size, meet not number character
                        //the position is like
                        //1. index,rightIndex
                        //2. index,...,rightIndex
                        if(rightIndex == index+1)
                        {
                            //1. index,rightIndex, rightIndex point to non number character, in range
                            //index is a symbol
                            #ifdef DEBUG
                                std::cout<<"\t rightIndex == index+1"<<std::endl;
                            #endif
                            while((rightIndex<size)&&((expression[rightIndex] == '+')||(expression[rightIndex] == '-')))
                            {
                                rightIndex++;
                            }
                            //1. rightIndex is out of range
                            //2. rightIndex point to a number character
                            if(rightIndex >=size)
                            {
                                //1. rightIndex is out of range
                                #ifdef DEBUG
                                    std::cout<<"\t illegal, no right operand, all character after + or - is + or -, rightIndex out of range, rightIndex:"<<rightIndex<<std::endl;
                                #endif
                                legal = false;
                                result = 0;
                            }
                            else
                            {
                                //2. rightIndex point to a number character
                                //remove extra symbol
                                #ifdef DEBUG
                                    std::cout<<"\t from index:"<<index<<" to rightIndex-1:"<<rightIndex-1<<" is all symbol:"<<expression<<std::endl;
                                #endif
                                int negative = 1;
                                for(int i=index;i<rightIndex;i++)
                                {
                                    if(expression[i] == '-')
                                        negative*=-1;
                                }
                                #ifdef DEBUG
                                    std::cout<<"\tnegative:"<<negative<<std::endl;
                                #endif
                                std::string substr;
                                if(negative == 1) 
                                    substr = "";
                                else
                                    substr = "-";
                                expression.insert(index,substr);
                                expression.erase(index+substr.size(),rightIndex-index);
                                #ifdef DEBUG
                                    std::cout<<"\tafter remove symbol, expression:"<<expression<<" substr:"<<substr<<std::endl;
                                #endif
                                result = computeExpression(expression,legal);
                            }
                        }
                        else
                        {
                            //leftIndex<0, index == 0, it must be a symbol, no leftoperand
                            //rightIndex < size, meet not number character
                            //2. index, ..., rightIndex, there is number between index and rightIndex
                            leftIndex = index;
                            index = rightIndex;
                            #ifdef DEBUG
                                std::cout<<"\t has left operand, leftIndex:"<<leftIndex<<std::endl;
                            #endif
                            int leftOperand = std::stoi(expression.substr(leftIndex+1,index-leftIndex-1));
                            if(expression[leftIndex] == '-')
                                leftOperand = -leftOperand;
                            rightIndex = index+1;
                            if(rightIndex>=size)
                            {
                                //1. rightIndex>=size, out of range, no right operand
                                #ifdef DEBUG
                                    std::cout<<"\t no right operand"<<std::endl;
                                #endif
                                result = leftOperand;
                            }
                            else
                            {
                                //2. rightIndex<size, in range, try take right operand
                                #ifdef DEBUG
                                    std::cout<<"\t rightIndex<size"<<std::endl;
                                #endif
                                while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                                {
                                    rightIndex++;
                                }
                                if(rightIndex>=size)
                                {
                                    //1. rightIndex out of range
                                    rightIndex--;
                                    int rightOperand = std::stoi(expression.substr(index+1,rightIndex-index));
                                    if(expression[index] == '+')
                                    {
                                        result = leftOperand + rightOperand;
                                    }
                                    else
                                    {
                                        result = leftOperand - rightOperand;
                                    }
                                    #ifdef DEBUG
                                        std::cout<<"\t"<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<std::endl;
                                    #endif
                                    std::string substr = std::to_string(result);
                                    expression.insert(index,substr);
                                    expression.erase(index+substr.size(),rightIndex-leftIndex);
                                    #ifdef DEBUG
                                        std::cout<<"\tafter compute, expression:"<<expression<<std::endl;
                                    #endif
                                }
                                else
                                {
                                    //2. rightIndex in range
                                    #ifdef DEBUG
                                        std::cout<<"\trightIndex in range, rightIndex:"<<rightIndex<<std::endl;
                                    #endif
                                    if(rightIndex == index+1)
                                    {
                                        //may be a signed number
                                        int tempIndex = rightIndex;
                                        while((tempIndex<size)&&((expression[tempIndex]=='+')||(expression[tempIndex]=='-')))
                                        {
                                            tempIndex++;
                                        }
                                        if(tempIndex>=size)
                                        {
                                            #ifdef DEBUG
                                                std::cout<<"\tillegal, noright number, tempIndex:"<<tempIndex<<std::endl;
                                            #endif
                                            legal = false;
                                            result = 0;
                                        }
                                        else
                                        {
                                            #ifdef DEBUG
                                                std::cout<<"\t right operand is a signed number"<<std::endl;
                                            #endif
                                            int negative = 1;
                                            for(int i=index+1;i<tempIndex;i++)
                                            {
                                                if(expression[i] == '-')
                                                    negative*=-1;
                                            }
                                            rightIndex = tempIndex;
                                            while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                                            {
                                                rightIndex++;
                                            }
                                            int rightOperand = std::stoi(expression.substr(tempIndex,rightIndex-tempIndex));
                                            rightOperand*=negative;
                                            if(expression[index] == '+')
                                                result = leftOperand+rightOperand;
                                            else
                                                result = leftOperand-rightOperand;
                                            std::string substr = std::to_string(result);
                                            expression.insert(leftIndex,substr);
                                            expression.erase(leftIndex+substr.size(),rightIndex-leftIndex);
                                            #ifdef DEBUG
                                                std::cout<<"\tcompute "<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<" substr:"<<substr<<" after compute expression"<<expression<<std::endl;
                                            #endif
                                        }
                                    }
                                    else
                                    {
                                        int rightOperand = std::stoi(expression.substr(index+1,rightIndex-index));
                                        if(expression[index] == '+')
                                            result = leftOperand+rightOperand;
                                        else
                                        {
                                            result = leftOperand-rightOperand;
                                        }
                                        #ifdef DEBUG
                                            std::cout<<"\tleftIndex:"<<leftIndex<<" rightIndex:"<<rightIndex<<std::endl;
                                            std::cout<<"\t"<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<std::endl;
                                        #endif
                                        std::string substr = std::to_string(result);
                                        expression.insert(leftIndex,substr);
                                        expression.erase(leftIndex+substr.size(),rightIndex-leftIndex);
                                        #ifdef DEBUG
                                            std::cout<<"\tfdfdafter compute, expression:"<<expression<<std::endl;
                                        #endif
                                        return computeExpression(expression,legal);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //1. rightIndex >=size, out of range
                        //the position is like
                        //1. index,rightIndex
                        //2. index, ..., rightIndex
                        if(index == size-1)
                        {
                            //1. index,rightIndex
                            #ifdef DEBUG
                                std::cout<<"\tillegal, index == size-1, operator has no right number:"<<rightIndex<<std::endl;
                            #endif
                            legal = false;
                            result = 0;
                        }
                        else
                        {
                            //2. index, ..., rightIndex
                            #ifdef DEBUG
                                std::cout<<"\tindex,...,rightIndex, rightIndex:"<<rightIndex<<std::endl;
                            #endif
                            if(expression[index] == '+')
                                result = std::stoi(expression.substr(index+1));
                            else
                                result = std::stoi(expression);
                            #ifdef DEBUG
                                std::cout<<"\tit's a number, no expression to compute, expression:"<<expression<<std::endl;
                            #endif
                            return result;
                        }
                    }
                }
                else
                {
                    //2. leftIndex>=0, index>=0, must be a operator
                    //std::cout<<"\tleftIndex >=0 index>=0, must be a operator, leftIndex:"<<leftIndex<<std::endl;
                    while((leftIndex>=0)&&(expression[leftIndex]>=48)&&(expression[leftIndex<=57]))
                    {
                        leftIndex--;
                    }
                    leftIndex++;
                    int leftOperand = std::stoi(expression.substr(leftIndex,index-leftIndex));
                    if(index == size-1)
                    {
                        #ifdef DEBUG
                            std::cout<<"\tillegal, operator is the last char, index:"<<index<<std::endl;
                        #endif
                        legal= false;
                        result = 0;
                    }
                    else
                    {
                        int rightIndex = index+1;
                        while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                        {
                            rightIndex++;
                        }
                        if(rightIndex<size)
                        {
                            if(rightIndex == index+1)
                            {
                                int tempIndex = rightIndex;
                                while((tempIndex<size)&&((expression[tempIndex]=='+')||(expression[tempIndex]=='-')))
                                {
                                    tempIndex++;
                                }
                                if(tempIndex>=size)
                                {
                                    #ifdef DEBUG
                                        std::cout<<"\tillegal, all operator, no number"<<std::endl;
                                    #endif
                                    legal = false;
                                    result = 0;
                                }
                                else{
                                    int negative = 1;
                                    for(int i=rightIndex;i<tempIndex;i++)
                                        if(expression[i]=='-')
                                            negative*=-1;
                                    #ifdef DEBUG
                                        std::cout<<"\trightIndex:"<<rightIndex<<" tempIndex:"<<tempIndex<<" negative:"<<negative<<std::endl;
                                    #endif
                                    rightIndex = tempIndex;
                                    while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                                    {
                                        rightIndex++;
                                    }
                                    if(rightIndex > size)
                                        rightIndex--;
                                    int rightOperand = std::stoi(expression.substr(tempIndex,rightIndex-tempIndex));
                                    rightOperand*=negative;
                                    if(expression[index] == '+')
                                        result = leftOperand+rightOperand;
                                    else
                                        result = leftOperand-rightOperand;
                                    #ifdef DEBUG
                                        std::cout<<"\t"<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<std::endl;
                                    #endif
                                    std::string substr = std::to_string(result);
                                    expression.insert(leftIndex,substr);
                                    expression.erase(leftIndex+substr.size(),rightIndex-leftIndex);
                                    #ifdef DEBUG
                                        std::cout<<"\tafter compute expression:"<<expression<<std::endl;
                                    #endif
                                    result = computeExpression(expression,legal);
                                }
                            }
                            else
                            {
                                int rightOperand = std::stoi(expression.substr(index+1,rightIndex-index));
                                if(expression[index] == '+')
                                    result = leftOperand+rightOperand;
                                else
                                    result = leftOperand-rightOperand;
                                #ifdef DEBUG
                                    std::cout<<"\t "<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<std::endl;
                                #endif
                                std::string substr = std::to_string(result);
                                expression.insert(leftIndex,substr);
                                expression.erase(leftIndex+substr.size(),rightIndex-leftIndex);
                                #ifdef DEBUG
                                    std::cout<<"\tafter compute, expression:"<<expression<<std::endl;
                                #endif
                                return computeExpression(expression,legal);
                            }
                        }
                        else
                        {
                            int rightOperand = std::stoi(expression.substr(index+1,rightIndex-index));
                            if(expression[index] == '+')
                                result = leftOperand+rightOperand;
                            else
                                result = leftOperand-rightOperand;
                            std::string substr = std::to_string(result);
                            #ifdef DEBUG
                                std::cout<<"\tindex:"<<index<<" leftIndex:"<<leftIndex<<" rightIndex:"<<rightIndex<<std::endl;
                                std::cout<<"\t"<<leftOperand<<std::string(1,expression[index])<<rightOperand<<"="<<result<<std::endl;
                            #endif
                            expression.insert(leftIndex,substr);
                            expression.erase(leftIndex+substr.size(),rightIndex-leftIndex);
                            #ifdef DEBUG
                                std::cout<<"\tafter compute, expression:"<<expression<<std::endl;
                            #endif
                            return computeExpression(expression,legal);
                        }
                    }
                }
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
                #ifdef DEBUG
                    std::cout<<"\t"<<" * or / is the first character, no left operand"<<std::endl;
                #endif
                legal = false;
                result = 0;
            }
            else
            {
                if((expression[leftIndex] == '+')||(expression[leftIndex] == '-'))
                {
                    #ifdef DEBUG
                        std::cout<<"\t"<<" + or - before * or /"<<std::endl;
                    #endif
                    legal = false;
                    result = 0;
                }
                else
                {
                    //have at least one number character, so left operand is not empty
                    #ifdef DEBUG
                        std::cout<<"\t* or /'s leftoperand not empty, * or / index:"<<index<<std::endl;
                    #endif
                    int leftoperand = 0;
                    while((leftIndex>=0)&&(expression[leftIndex] >=48) &&(expression[leftIndex]<=57))
                    {
                        leftIndex--;
                    }
                    leftIndex++;
                    //1. out of range
                    //2. leftIndex is a operator
                    #ifdef DEBUG
                        std::cout<<"\t"<<"leftIndex:"<<leftIndex<<std::endl;
                    #endif
                    if(leftIndex >= 0)
                    {
                        leftoperand = std::stoi(expression.substr(leftIndex,index-leftIndex));
                        //leftIndex++;
                    }
                    else
                    {
                        leftIndex = 0;
                        leftoperand = std::stoi(expression.substr(leftIndex,index-leftIndex));
                    }
                    #ifdef DEBUG
                        std::cout<<"\t"<<"leftoperand:"<<leftoperand<<std::endl;
                    #endif
                    int rightIndex = index+1;
                    //take right operand
                    //1. it's operator, + or - or * or /
                    //2. it's number character
                    //3. it's out of range
                    if(rightIndex>=size)
                    {
                        #ifdef DEBUG
                            std::cout<<"\t"<<"* or / is the last operator, no right operand"<<std::endl;
                        #endif
                        legal = false;
                        result = 0;
                    }
                    else
                    {
                        if((expression[rightIndex] == '*')||(expression[rightIndex] == '/'))
                        {
                            #ifdef DEBUG
                                std::cout<<"\t"<<" two * or / in serial, illegal"<<std::endl;
                            #endif
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
                                #ifdef DEBUG
                                    std::cout<<"\t"<<" no number right to * or /"<<std::endl;
                                #endif
                                legal = false;
                                result = 0;
                            }
                            else if(expression[rightIndex] == '*' || expression[rightIndex] == '/')
                            {
                                #ifdef DEBUG
                                    std::cout<<"\t"<<" * or / after some + or - after + or -"<<std::endl;
                                #endif
                                legal = false;
                                result = 0;
                            }
                            else
                            {
                                std::string tempstr;//(1,expression[rightIndex]);
                                #ifdef DEBUG
                                    std::cout<<"\tmeet rightOperand's first number, index:"<<rightIndex<<" char:"<<tempstr<<std::endl;
                                #endif
                                while((rightIndex<size)&&(expression[rightIndex]>=48)&&(expression[rightIndex]<=57))
                                {
                                    tempstr.append(1,expression[rightIndex]);
                                    rightIndex++;
                                }
                                rightIndex--;
                                int rightOperand = std::stoi(tempstr);
                                #ifdef DEBUG
                                    std::cout<<"\trightOperand:"<<rightOperand<<std::endl;
                                #endif
                                rightOperand*=negative;
                                std::string substr;
                                if(expression[index] == '*')
                                    substr = std::to_string(leftoperand*rightOperand);
                                else
                                {
                                    if(rightOperand == 0)
                                    {
                                        substr = "0";
                                        legal = false;
                                    }
                                    else
                                        substr = std::to_string(leftoperand/rightOperand);
                                }
                                #ifdef DEBUG
                                    std::cout<<"\tsub expression result:"<<substr<<std::endl;
                                #endif
                                expression.insert(leftIndex,substr);
                                expression.erase(leftIndex+substr.size(),rightIndex-leftIndex+1);
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
    #ifdef DEBUG
        std::cout<<"expression: "<<expression<<std::endl;
    #endif
    std::string resultExpression;
    if(legal == false)
    {
        #ifdef DEBUG
            std::cout<<"\t"<<"illegal expression"<<std::endl;
        #endif
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
                #ifdef DEBUG
                    std::cout<<"\t"<<"no brackets at all"<<std::endl;
                #endif
                resultExpression = expression;
            }
            else
            {
                #ifdef DEBUG
                    std::cout<<"\t"<<"no ([{ but have )]}"<<std::endl;
                #endif
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
                #ifdef DEBUG
                    std::cout<<"\t"<<"have ([{ but no )]}"<<std::endl;
                #endif
                resultExpression = "";
                legal = false;
            }
            else{
                end+=index+1;
                if((end<=index)||(end == index+1))
                {
                    #ifdef DEBUG
                        std::cout<<"\t"<<")]} appear before ([{ or it's empty"<<std::endl;
                    #endif
                    legal = false;
                    //return "";
                    resultExpression = "";
                }
                std::string substr = expression.substr(index+1,end-index-1);
                int result = computeExpression(substr,legal);
                if(legal == false)
                {
                    //return "";
                    #ifdef DEBUG
                        std::cout<<"\t"<<"expression in bracket is illegal"<<std::endl;
                    #endif
                    resultExpression = "";
                }
                else
                {
                    #ifdef DEBUG
                        std::cout<<"\t"<<"expression in bracket is:"<<substr<<std::endl;
                    #endif
                    std::string insertstr = std::to_string(result);
                    expression.insert(index,insertstr);
                    expression.erase(index+insertstr.size(),end-index+1);
                    //return resolveBrackets(expression,legal);
                    resultExpression = resolveBrackets(expression,legal);
                }
            }
        }
    }
    #ifdef DEBUG
        std::cout<<"after resolve:"<<resultExpression<<std::endl;
    #endif
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
#include <string>
#include <iostream>
#include <vector>

int computeExpression(std::string expression, bool& legal)
{
    // version 0: suppose expression contain only + - * / number, not contain () [] {}
    auto size = expression.size();
    int index = expression.find("*/");
    if(index != std::string::npos)
    {
        int i=1;
        std::string lv,rv;
        // index->left detect
        // out of range,stop
        // number, save to lv
        // operator(+-*/),stop
        while((index-i<=0) && (expression[index-i]>=48) && (expression[index-i]<=57))
        {
            lv = std::string(1,expression[index-i])+lv;
            i++;
        }
        if(lv.size() == 0)
        {
            legal = false;
            return 0;
        }
        int a = std::stoi(lv);
        int j = 1;
        int negative = 1;
        // index->right detect
        // out of range, stop
        // +,ignore
        // -,save to negative
        // number, save to rv
        // *,/,stop
        while((index+j<size) && (expression[index+j]!='*') && (expression[index+j]!='/'))
        {
            if(expression[index+j] == '+')
            {
                if(rv.size() == 0)
                    continue;
                else
                    break;
            }
            else if(expression[index+j] == '-')
            {
                if(rv.size() == 0)
                    negative *=-1;
                else
                    break;
            }
            else
            {
                rv = std::string(1,expression[index+j])+rv;
            }
            j++;
        }
        if(rv.size() == 0)
        {
            legal = false;
            return 0;
        }
        int b = std::stoi(rv);
        b*=negative;
        std::string substr;
        if(expression[index] = '*')
            substr = std::to_string(a*b);
        else
            substr = std::to_string(a/b);
        expression.insert(index-i+1,substr);
        expression.erase(index-i+1+substr.size(),i+j+1);
    }
}
int main()
{
    std::string expression;
    while(std::cin>>expression)
    {
        bool flag= true;
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
value or expression
expression made of a series of operator and operand
legal operator: +,-,*,/,(),[],{}
+,-,*,/ operator must have two operand, operand can be expression or value
(),[],{} operator must have one operand, operand can be expression or value

what is difficult?
make sure the expression is fully checked.

example:
1+(3+2)
has two operator, first operator is +, operand is 1 and (3+2)
second operator is +, operand is 3 and 2

for a illegal expression, there's no priority law to use, 
so shouldn't suppose a wait to detect expression is legal and use prioity law to decide detect order.

-3+-3*[-2+-3]
((2*3))-4*[(3)+7]
-4+-+35-1*-/4
-4+-+35-(1*)-/4

with expression
case 0-1: expression is empty,
    END: (0,illegal)
case 0-2: expression not empty
    case 0-2-1: expression contain illegal character
        END: (0,illegal)
    case 0-2-2: expression not empty, contain only legal character
        case 0-2-2-1: expression contain ( or [ or {
            case 0-2-2-1-1: ( or [ or { have match ) or ] or }
                case 0-2-2-1-1-1: expression in () or [] or {} is legal
                    END: (new expression, legal)
                case 0-2-2-1-1-2: expression in () or [] or {} is illegal
                    END: (0, illegal)
            case 0-2-2-1-2: ( or [ or { have no match ) or ] or }
                END: (0,illegal)
        case 0-2-2-2: expression contain no ( or [ or {
            case 0-2-2-2-1: expression contain ) or ] or }
                END: (0,illegal)
            case 0-2-2-2-2: expression contain no () or [] or {}
            (may contain number, +, -, *, /)
                case 0-2-2-2-2-1: contain * or /
                    left operand
                    right operand
                    END: (new expression)
                case 0-2-2-2-2-2: contain no * or /
                (may contain number + -)
                    case 0-2-2-2-2-2-1: contain + or -
                    (contain + -, may contain number)
                    case 0-2-2-2-2-2-2: contain no + or -
                    (contain only number)
                        END: (std::stoi(expression),legal)

expression only contain + - * / number, how to compute legal and result
- + may be symbol or operator, as symbol it has two operator in serial   
+ symbol operator is useless, erase directly
- symbol operator only save one  
operator's operand may be symbol operand
left symbol operand, 
*/
#include <string>
#include <iostream>
#include <vector>
int computeExpression(std::string expression)
{
    auto size = expression.size();
    std::string::size_type index = expression.find_first_of("(");
    
    if(index!=std::string::npos)
    {
        std::string::size_type end = expression.find_first_of(")");
        if(end!=std::string::npos)
        {
            //std::cout<<"found () "<<index<<" "<<end<<std::endl;
            std::string substr = expression.substr(index+1,end-index-1);
            int a = computeExpression(substr);
            //std::cout<<"compute ("<<substr<<")="<<a<<std::endl;
            substr = std::to_string(a);
            expression.insert(index,substr);
            expression.erase(index+substr.size(),end-index+substr.size());
            //std::cout<<"new expression:"<<expression<<std::endl;
            return computeExpression(expression);
        } 
    }
    index = expression.find_first_of("[");
    if(index!=std::string::npos)
    {
        std::string::size_type end = expression.find_first_of("]");
        if(end!=std::string::npos)
        {
            //std::cout<<"found [] "<<index<<" "<<end<<std::endl;
            std::string substr = expression.substr(index+1,end-index-1);
            int a = computeExpression(substr);
            //std::cout<<"compute ["<<substr<<"]="<<a<<std::endl;
            substr = std::to_string(a);
            expression.insert(index,substr);
            expression.erase(index+substr.size(),end-index+substr.size());
            return computeExpression(expression);
        } 
    }
    index = expression.find_first_of("{");
    if(index!=std::string::npos)
    {
        std::string::size_type end = expression.find_first_of("}");
        if(end!=std::string::npos)
        {
            //std::cout<<"found {} "<<index<<" "<<end<<std::endl;
            std::string substr = expression.substr(index+1,end-index-1);
            int a = computeExpression(substr);
            //std::cout<<"compute {"<<substr<<"}="<<a<<std::endl;
            substr = std::to_string(a);
            expression.insert(index,substr);
            expression.erase(index+substr.size(),end-index+substr.size());
            return computeExpression(expression);
        } 
    }
    index = expression.find_first_of("*");
    if(index!=std::string::npos)
    {
        unsigned int left = 1, right = 1;
        while((index>=left)&&(expression[index-left]!='+' && expression[index-left]!='-' && expression[index-left]!='*' &&expression[index-left]!='/'))
        {
            left++;
            //std::cout<<"left++:"<<left<<std::endl;
        }
        //std::cout<<"left:"<<left<<std::endl;
        if(index>=left && expression[index-left] == '-')
            if((index>=left+1)&&(expression[index-left-1] == '+' &&expression[index-left-1] == '-' &&expression[index-left-1] == '*'&&expression[index-left-1] == '/'))
            {
                left++;
                //std::cout<<"left:"<<left<<std::endl;
            }
            else if(index == left)
                left++;
        left--;
        while((index+right+1<=size)&&(expression[index+right]!='+' && expression[index+right]!='-' && expression[index+right]!='*' &&expression[index+right]!='/'))
        {
            right++;
            //std::cout<<"right:"<<right<<std::endl;
        }
        right--;
        //std::cout<<"left:"<<left<<" right:"<<right<<std::endl;
        std::string substr = expression.substr(index-left,right+left+1);
        int a = std::stoi(expression.substr(index-left,left));
        int b = std::stoi(expression.substr(index+1,right));
        //std::cout<<a<<"*"<<b<<std::endl;
        substr = std::to_string(a*b);
        expression.insert(index-left,substr);
        expression.erase(index-left+substr.size(),right+left+1);
        return computeExpression(expression);
    }
    index = expression.find_first_of("/");
    if(index!=std::string::npos)
    {
        unsigned int left = 1, right = 1;
        while((index>=left)&&(expression[index-left]!='+' && expression[index-left]!='-' && expression[index-left]!='*' &&expression[index-left]!='/'))
        {
            left++;
            //std::cout<<"left++:"<<left<<std::endl;
        }
        //std::cout<<"left:"<<left<<std::endl;
        if(index>=left && expression[index-left] == '-')
            if((index>=left+1)&&(expression[index-left-1] == '+' &&expression[index-left-1] == '-' &&expression[index-left-1] == '*'&&expression[index-left-1] == '/'))
            {
                left++;
                //std::cout<<"left:"<<left<<std::endl;
            }
            else if(index == left)
                left++;
        left--;
        while((index+right+1<=size)&&(expression[index+right]!='+' && expression[index+right]!='-' && expression[index+right]!='*' &&expression[index+right]!='/'))
        {
            right++;
            //std::cout<<"right:"<<right<<std::endl;
        }
        right--;
        //std::cout<<"left:"<<left<<" right:"<<right<<std::endl;
        std::string substr = expression.substr(index-left,right+left+1);
        int a = std::stoi(expression.substr(index-left,left));
        int b = std::stoi(expression.substr(index+1,right));
        
        substr = std::to_string(a/b);
        //std::cout<<a<<"/"<<b<<"="<<substr<<std::endl;
        expression.insert(index-left,substr);
        expression.erase(index-left+substr.size(),right+left+1);
        return computeExpression(expression);
    }
    index = expression.find_first_of("+");
    if(index!=std::string::npos)
    {
        //std::cout<<"found + "<<index<<std::endl;
        unsigned int left = 1, right = 1;
        while((index>=left)&&(expression[index-left]!='+' && expression[index-left]!='-' && expression[index-left]!='*' &&expression[index-left]!='/'))
        {
            left++;
            //std::cout<<"left:"<<left<<std::endl;
        }
        
        //std::cout<<"left:"<<left<<std::endl;
        if((index>=left)&&(expression[index-left] == '-'))
            if((index+1>=left)&&(expression[index-left-1] == '+' &&expression[index-left-1] == '-' &&expression[index-left-1] == '*'&&expression[index-left-1] == '/'))
            {
                left++;
                //std::cout<<"left:"<<left<<std::endl;
            }
            else if(index == left)
                left++;
        left--;
        while((index+right+1<=size)&&(expression[index+right]!='+' && expression[index+right]!='-' && expression[index+right]!='*' &&expression[index+right]!='/'))
        {
            right++;
            //std::cout<<"right:"<<right<<std::endl;
        }
        right--;
        std::string substr = expression.substr(index-left,right+left+1);
        int a = std::stoi(expression.substr(index-left,left));
        int b = std::stoi(expression.substr(index+1,right));
        //std::cout<<a<<"+"<<b<<std::endl;
        substr = std::to_string(a+b);
        expression.insert(index-left,substr);
        expression.erase(index-left+substr.size(),right+left+1);
        return computeExpression(expression);
    }
    index = expression.find_first_of("-");
    if(index!=std::string::npos)
    {
        if(index == 0)
        {
            auto another = expression.find_last_of("-");
            if(another == index)
                return std::stoi(expression);
            else
                index = another;
        }
        //std::cout<<"found - "<<index<<std::endl;
        unsigned int left = 1, right = 1;
        while((index>=left)&&(expression[index-left]!='+' && expression[index-left]!='-' && expression[index-left]!='*' &&expression[index-left]!='/'))
        {
            left++;
            //std::cout<<"left++:"<<left<<std::endl;
        }
        //std::cout<<"left:"<<left<<std::endl;
        if(index>=left && expression[index-left] == '-')
            if((index>=left+1)&&(expression[index-left-1] == '+' &&expression[index-left-1] == '-' &&expression[index-left-1] == '*'&&expression[index-left-1] == '/'))
            {
                left++;
                //std::cout<<"left:"<<left<<std::endl;
            }
            else if(index == left)
                left++;
        left--;
        while((index+right+1<=size)&&(expression[index+right]!='+' && expression[index+right]!='-' && expression[index+right]!='*' &&expression[index+right]!='/'))
        {
            right++;
            //std::cout<<"right:"<<right<<std::endl;
        }
        right--;
        //std::cout<<"left:"<<left<<" right:"<<right<<std::endl;
        std::string substr = expression.substr(index-left,right+left+1);
        int a = std::stoi(expression.substr(index-left,left));
        int b = std::stoi(expression.substr(index+1,right));
        //std::cout<<a<<"-"<<b<<std::endl;
        substr = std::to_string(a-b);
        expression.insert(index-left,substr);
        expression.erase(index-left+substr.size(),right+left+1);
        return computeExpression(expression);
    }
    
    else{
        int a = std::stoi(expression);
        return a;
    }

}
int main()
{
    std::string expression;
    while(std::cin>>expression)
    {
        std::cout<<computeExpression(expression)<<std::endl;
    }
}
/*
case:
3+2*{1+2*[-4/(8-6)+7]}

(8-6) = 2
expression = 3+2*{1+2*[-4/2+7]}
-4/2 = -2
expression = 3+2*{1+2*[-2+7]}

*/
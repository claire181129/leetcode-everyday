#include <iostream>
#include <string>
#include <vector>

bool valid_direction(char c, int &dx, int& dy)
{
    switch(c)
    {
        case 'A':
        dx = -1;
        dy = 0;
        break;
        case 'D':
        dx = 1;
        dy = 0;
        break;
        case 'W':
        dx = 0;
        dy = 1;
        break;
        case 'S':
        dx = 0;
        dy = -1;
        break;
        default:
        dx = 0;
        dy = 0;
        return false;
    }
    return true;
}
void move_coordinate(int& x, int& y, std::string str)
{
    auto size = str.size();
    char directX, directY;
    int moveX, moveY;
    for(int i=0;i<size;i++)
    {
        int dx = 0,dy = 0;
        if(valid_direction(str[i],dx,dy))
        {
            std::string num;
            i++;
            for(int j=i;j<size;j++)
            {
                if(str[j]>=48 && str[j]<=57)
                {
                    num += std::string(1, str[j]);
                    i++;
                    //std::cout<<dx<<","<<dy<<" "<<num<<std::endl;
                }
                else
                    break;
            }
            if(num.size()>0)
            {
                if(dx != 0)
                {
                    dx *= std::stoi(num);
                    //std::cout<<"x move:"<<dx<<std::endl;
                }
                else if(dy !=0)
                {
                    dy *= std::stoi(num);
                    //std::cout<<"y move:"<<dy<<std::endl;
                }
            }
            if(str[i] == ';'&& (dx||dy))
            {
                x+=dx;
                y+=dy;
                //std::cout<<"1 index:"<<i<<" ("<<x<<","<<y<<") ("<<dx<<","<<dy<<")"<<std::endl;
                //i++;
            }
            if(valid_direction(str[i],dx,dy))
            {
                num = "";
                i++;
                for(int j=i;j<size;j++)
                {
                    if(str[j]>=48 && str[j]<=57)
                    {
                        num += std::string(1, str[j]);
                        i++;
                        //std::cout<<dx<<","<<dy<<" "<<num<<std::endl;
                    }
                    else
                        break;
                }
                if(num.size()>0)
                {
                    if(dx != 0)
                    {
                        dx *= std::stoi(num);
                        //std::cout<<"x move:"<<dx<<std::endl;
                    }
                    else if(dy !=0)
                    {
                        dy *= std::stoi(num);
                        //std::cout<<"y move:"<<dy<<std::endl;
                    }
                    if(str[i] == ';'&& (dx||dy))
                    {
                        x+=dx;
                        y+=dy;
                        //std::cout<<"index:"<<i<<" ("<<x<<","<<y<<") ("<<dx<<","<<dy<<")"<<std::endl;
                        i++;
                    }
                }
            }
            while(str[i]!=';')
                i++;
            //std::cout<<"i: "<<i<<" "<<str[i]<<std::endl;
        }
        else
        {
            while(str[i]!=';')
                i++;
        }
    }
}
int main()
{
    std::string line;
    while(std::getline(std::cin,line))
    {
        int x = 0, y = 0;
        move_coordinate(x,y,line);
        std::cout<<x<<","<<y<<std::endl;
    }
    return 0;
}
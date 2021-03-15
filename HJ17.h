#include <iostream>
#include <string>
#include <vector>

bool valid_direction(char c, int &d)
{
    if(c == 'A' || c == 'S')
        d = -1;
    else if(c == 'W' || c == 'D')
        d = 1;
    else
        return false;
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
        if(valid_direction(str[i],dx))
        {
            std::string strX;
            for(int j=i+1;j<size;j++)
            {
                if(str[j]>=48 || str[j]<=57)
                {
                    strX += std::string(1, str[j]);
                    i++;
                }
                else
                    break;
            }
            if(strX.size()>0)
                dx *= std::stoi(strX);
            x += dx;
            if(valid_direction(str[i],dy))
            {
                std::string strY;
                for(int j=i+1;j<size;j++)
                {
                    if(str[j]>=48 || str[j]<=57)
                    {
                        strY += std::string(1, str[j]);
                        i++;
                    }
                    else
                        break;
                }
                if(strY.size()>0)
                    dy *= std::stoi(strY);
                y += dy;
            }
            if(str[i] == ';')
            {
                x+=dx;
                y+=dy;
                return;
            }
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
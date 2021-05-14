#include <iostream>
#include <vector>

// version 1
std::vector<std::vector<int>> generate_ND_snake_matrix(unsigned int n)
{
    std::vector<std::vector<int>> matrix(n,std::vector<int>(n));
    unsigned int number = 1;
    for (int i = 0; i < n; i++)
    {
        int x = i,y = 0;
        while (x >= 0 && x < n && y >= 0 && y < n)
        {
            matrix[x][y] = number;
            x -= 1;
            y += 1;
            number++;
        }
    }
    return matrix;
}
void print_upper_rectangle_matrix(std::vector<std::vector<int>> matrix)
{
    auto n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n)
                std::cout << matrix[i][j];
            else
                std::cout << " ";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
void main_version1()
{
    unsigned int n;
    while (std::cin >> n)
    {
        std::vector<std::vector<int>> matrix = generate_ND_snake_matrix(n);
        print_upper_rectangle_matrix(matrix);
    }
}
// version 2
// it's a serial of number, just arranged in specified shape
// from 1 to what? 1+2+3+... +n = n*(n+1)/2
// for n=4, it's 4*(4+1)/2 = 10
// and each number has it's position
// in form of (line,nth)
// limited by the std::cout, the shape's print turn into 
struct Snake_Element {
    unsigned int value;
    unsigned int line;
    unsigned int nth;
};
unsigned int do_change(unsigned int value, unsigned int change)
{
    return value + change;
}
std::vector<Snake_Element> generate_snake(unsigned int n)
{
    std::vector<Snake_Element> snake;
    unsigned int start_value = 1;
    unsigned int value = start_value;
    unsigned int line = 0;
    unsigned int change = 1;
    while (line < n)
    {
        for (int i = 0; i <= line; i++)
        {
            Snake_Element element;
            element.value = value;
            element.line = line;
            element.nth = i;
            snake.push_back(element);
            value = do_change(value,change);
        }
        line += 1;
    }
    return snake;
}
void print_snake_in_rectangle(std::vector<Snake_Element> snake)
{

}
void print_snake_in_matrix(std::vector<Snake_Element> snake)
{

}
void main_version2()
{
    unsigned int n;
    while (std::cin >> n)
    {
        std::vector<Snake_Element> snake;
        snake = generate_snake(n);
        print_snake_in_matrix(snake);
    }
}
// version 3
/*
*
* so called N line snake matrix is a set of numbers( size: N*(N+1)/2 ), start from specific value(1), change in specific function(+1).
* this is a 1 dimension number list. 
* for print purpose, each element has position attribute, in 2 dimension form.
* the rule of how to turn 1 dimension position to 2 dimension position in this case, is the position move like a snake
* nth number's position is ?
* 0, 0,0
* 1, 1,0
* 2, 0,1
* 3, 
*/
void generate_list(unsigned int n, unsigned int* &plist)
{
    unsigned int number_count = n * (n + 1) / 2;
    plist = (unsigned int*)malloc(sizeof(unsigned int) * number_count);
    unsigned int start_value = 1;
    unsigned int change_unit = 1;
    unsigned int value = start_value;
    for (int i = 0; i < number_count; i++)
    {
        plist[i] = value;
        value = do_change(value, change_unit);
    }
}
void print_list(unsigned int* plist, int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<plist[i]<<" ";
    }
    std::cout<<std::endl;
}
void down_up_snake_move(int& x, int& y, unsigned int n)
{
    if(x<0 || x>=n || y<0 || y>=n)
    {
        return;
    }
    else if (x > 0 && y<n-1)
    {
        x -= 1;
        y += 1;
    }
    else if (y== n-1)
    {
        x = n-1;
        y = x+1;
    }
    else if(x == 0)
    {
        x = y+1;
        y = 0;
    }
    else
    {
        return;
    }
}
void turn_list_to_matrix_by_down_up_snake_move(unsigned int* plist, unsigned int** &pmatrix, unsigned int n)
{
    pmatrix = (unsigned int**)malloc(sizeof(unsigned int*) * n);
    for (unsigned int i = 0; i < n; i++)
    {
        pmatrix[i] = (unsigned int*)malloc(sizeof(unsigned int) * n);
    }
    int x = 0;
    int y = 0;
    unsigned int list_size = n * (n + 1) / 2;
    for (int i = 0; i < n * n; i++)
    {
        if (i < list_size)
        {
            pmatrix[x][y] = plist[i];
        }
        else
        {
            pmatrix[x]+y = nullptr;
        }
        down_up_snake_move(x, y,n);
    }
}
void print_matrix(unsigned int** pmatrix, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pmatrix[i]+j == NULL)
            {
                std::cout<<"  ";
            }
            else
            {
                std::cout<<pmatrix[i][j]<<" ";
            }
        }
        std::cout<<std::endl;
    }
}
void main_version3()
{
    unsigned int n;
    while (std::cin >> n)
    {
        unsigned int* plist = NULL;
        generate_list(n, plist);
        unsigned int** pmatrix = NULL;
        turn_list_to_matrix_by_down_up_snake_move(plist, pmatrix,n);
        print_matrix(pmatrix,n);
    }
}
int main()
{
    unsigned int n;
    while (std::cin >> n)
    {
        unsigned int* plist = NULL;
        generate_list(n, plist);
        //print_list(plist,n);
        unsigned int** pmatrix = NULL;
        turn_list_to_matrix_by_down_up_snake_move(plist, pmatrix,n);
        print_matrix(pmatrix,n);
    }
}
/*
      0 1 2 3
    0 1 3 6 10
    1 2 5 9
    2 4 8
    3 7

    */
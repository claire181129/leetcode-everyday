#include <iostream>

int validInitialize(int m, int n)
{
    if(m>9 || n>9)
        return -1;
    else
        return 0;
}
int validswitch(int x1,int y1,int x2,int y2, int m, int n)
{
    if(x1>0 && x1<m && x2>0 && x2<m && y1>0 && y1<n && y2>0 && y2<n)
    {
        return 0;
    }
    else
        return -1;
}
int validInsertLine(int l, int m)
{
    if(l<0 || l>=m)
        return -1;
    else if(m+1>9)
        return -1;
    else
        return 0;
}
int validFindData(int x, int y, int m, int n)
{
    if(x>0 && x<m && y>0 && y<n)
        return 0;
    else
        return -1;
}
int main()
{
    int m=0, n=0;
    while(std::cin>>m>>n)
    {
        std::cout<<validInitialize(m,n)<<std::endl;
        //int *table;
        int x1,y1,x2,y2;
        std::cin>>x1>>y1>>x2>>y2;
        std::cout<<validswitch(x1,y1,x2,y2,m,n)<<std::endl;
        int l,c;
        std::cin>>l>>c;
        std::cout<<validInsertLine(l,m)<<std::endl;
        std::cout<<validInsertLine(c,n)<<std::endl;
        int x,y;
        std::cin>>x>>y;
        std::cout<<validFindData(x,y,m,n)<<std::endl;

    }
    return 0;
}
/*
有一个大小的数据表，你会依次进行以下5种操作：
1.输入和，初始化大小的表格。
2.输入x_1x 
3.输入，在第行左边添加一行。//怎么在行的左边添加行？行的左边是什么东西？
4.输入，在第列上方添加一列。//列的上方又是什么鬼？


本组样例共有2组样例输入。
第一组样例：
1.初始化数据表为4行9列，成功
2.交换第5行1列和第2行6列的数据，失败。因为行的范围应该是(0,3)，不存在第5行。
3.在第0行左边添加一行，成功。
4.在第8列上方添加一列，失败。因为列的总数已经达到了9的上限。// 
5.查询第2行第3列的值，成功。
第二组样例：
1.初始化数据表为4行7列，成功
2.交换第4行2列和第3行2列的数据，失败。因为行的范围应该是(0,3)，不存在第4行。
3.在第3行左边添加一行，成功。
4.在第3列上方添加一列，成功。
5.查询第4行7列的值，失败。因为虽然添加了一行一列，但数据表会在添加后恢复成4行7列的形态，所以行的区间仍然在[0,3]，列的区间仍然在[0,6]，无法查询到(4,7)坐标。  
*/
#include <iostream> 
#include <vector>
  
using namespace std; 
int putapples(int m,int n) 
{ 
    //std::cout<<"m:"<<m<<" n:"<<n<<std::endl;
    if(m<0)
        return 0;
    if(m==1||n==1) 
        return 1; 
    return putapples(m,n-1)+putapples(m-n,n); 

} 

int main() 
{ 
    //m*n
    int m,n; 
    std::vector<int> nums;
    while(cin>>m>>n)
    { 
        cout<<putapples(m,n)<<endl;
    } 
    return 0; 

} 
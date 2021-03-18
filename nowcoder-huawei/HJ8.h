#include <iostream>
#include <vector>

struct KeyVal{
    int key;
    int val;
};
int findKey(int k, std::vector<KeyVal> input)
{
    auto size = input.size();
    for(int i=0;i<input.size();i++)
        if(input[i].key == k)
            return i;
    return -1;
}
void sort(std::vector<KeyVal> &input)
{
    auto size = input.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(input[i].key>input[j].key)
            {
                KeyVal temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}
int main()
{
    int n =0;
    while(std::cin>>n)
    {
        std::vector<KeyVal> input;
        for(int i=0;i<n;i++)
        {
            int k,v;
            std::cin>>k>>v;
            int index = findKey(k,input);
            //std::cout<<"index:"<<index<<" "<<k<<std::endl;
            if(index>=0)
            {
                input[index].val+=v;
            }
            else
            {
                KeyVal temp;
                temp.key = k;
                temp.val = v;
                input.push_back(temp);
            }
        }
        sort(input);
        for(auto i:input)
            std::cout<<i.key<<" "<<i.val<<std::endl;
    }
    return 0;
}
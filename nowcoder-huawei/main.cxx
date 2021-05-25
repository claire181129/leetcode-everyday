#include <iostream>
struct NODE{
    int value;
    NODE* next_node = NULL;
};
struct LIST{
    NODE* pnode;
};
void insert_node_to_list(LIST &list,int target_node,int insert_node)
{
    NODE* pnode = list.pnode;
    while(pnode != NULL)
    {
        if(pnode->value == target_node)
        {
            NODE new_node;
            new_node.value = insert_node;
            new_node.next_node = pnode->next_node;
            pnode->next_node = &new_node;
            return;
        }
        pnode = pnode->next_node;
    }
}
void delete_node_from_list(LIST &list,int target_node)
{
    NODE* &pnode = list.pnode;
    NODE* last_node = NULL;
    while(pnode != NULL)
    {
        if(pnode->value == target_node)
        {
            if(last_node != NULL)
            {
                last_node->next_node = pnode->next_node;
            }
            else
            {
                pnode = pnode->next_node;
            }
        }
        last_node = pnode;
        pnode = pnode->next_node;
    }
}
void print_list(LIST list)
{
    if(list.pnode == NULL)
    {
        std::cout<<"NULL"<<std::endl;
    }
    else{
        NODE* the_node = list.pnode;
        while(the_node != NULL)
        {
            std::cout<<the_node->value<<" ";
            the_node = the_node->next_node;
        }
    }
}
int list_size(LIST list)
{
    NODE* pnode = list.pnode;
    int counter = 0;
    while(pnode != NULL){
        counter+=1;
        pnode = pnode->next_node;
    }
    return counter;
}
int main()
{
    int count;
    while(std::cin>>count)
    {
        int first_node;
        std::cin>>first_node;
        NODE node;
        node.value = first_node;
        node.next_node = NULL;
        LIST list;
        list.pnode = &node;
        while(count>1)
        {
            int previous_node, new_node;
            std::cin>>new_node>>previous_node;
            std::cout<<"insert: "<<new_node<<" after:"<<previous_node<<std::flush;   
            auto& pnode = list.pnode;   
            while(pnode != NULL)    
            {
                if(pnode->value == previous_node)
                {
                    NODE* temp_node;
                    temp_node->value = new_node;
                    temp_node->next_node = pnode->next_node;
                    pnode->next_node = temp_node;
                    std::cout<<temp_node->value<<"    inserted"<<std::endl;
                    print_list(list);
                    break;
                }
                pnode = pnode->next_node;
            }
            count-=1;
        }
        //int delete_node;
        //std::cin>>delete_node;
        //delete_node_from_list(list,delete_node);
        //std::cout<<"List Size:"<<std::flush;
        //std::cout<<list_size(list)<<std::endl;
        //print_list(list);
    }
    return 0;
}
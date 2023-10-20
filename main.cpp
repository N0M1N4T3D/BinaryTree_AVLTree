#include "class.h"

void print_array_main();
uint32_t array_main[ar_size];

int main()
{
    pavl root = new avl_node(45);
    pavl l1 = new avl_node(39);
    pavl r1 = new avl_node(51);
    pavl l1r1 = new avl_node(40);
    pavl l2 = new avl_node(37);
    pavl l2r1 = new avl_node(38);
    root->set_left(l1);
    root->set_right(r1);
    l1->set_left(l2);
    l1->set_right(l1r1);
    l2->set_right(l2r1);


    return 0;
}
void print_array_main()
{
    for(int i=0;i<ar_size;i++)
    {
        printf("%d",array_main[i]);
    }
    printf("%s","\nArray generated");
}
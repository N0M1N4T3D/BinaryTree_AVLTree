#include "class.h"

void print_array_main();
uint32_t array_main[ar_size];

int main()
{
    //print_array_main();
	node::generate_new_array(array_main);
	pnode root = new node();
	root = node::maketree(array_main, ar_size,1);
	node::print_tree_for_debugging(root, 0);

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
#include "class.h"

uint32_t array_main[ar_size];

int main()
{
	node::generate_new_array(array_main);
//    for(int i=0;i<1000000;i++)
//    {
//        printf("%d",array_main[i]);
//    }
//    printf("%s","\nArray generated");
	//строки для тестирования функции создания

	pnode root = new node();
	root = node::maketree(array_main, ar_size);
	node::print_tree_for_debugging(root, 0);
}
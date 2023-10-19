#include "class.h"
uint32_t array_main[1000000];

int main()
{
	node::generate_new_array(array_main);
    for(int i=0;i<1000000;i++)
    {
        printf("%d",array_main[i]);
    }
    printf("%s","\nArray generated");
	//строки для тестирования функции создания
	uint32_t arr[] = {50,4,3,8,9,5,0,12,76,234,876};
	pnode root = new node();
	root = node::maketree(arr, 11);
	node::print_tree_for_debugging(root, 0);
}
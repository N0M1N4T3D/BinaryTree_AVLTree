#include <iostream>
#include "making_search_tree.h"
#include "class.h"

int main()
{
	
	//строки для тестирования функции создания
	int arr[] = {50,4,3,8,9,5,0,12,76,234,876};
	pnode root = new node();
	root = maketree(arr, 11);
	print_tree_for_debugging(root, 0);
}
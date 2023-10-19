#include "making_search_tree.h"
pnode maketree(int* arr, int size)
{
	if (size == 0)
	{
		printf("ERROR! Invalid count!!!\n");
		return nullptr;
	}
	pnode root = new node(arr[0]);
	int arr_ind = 1;
	pnode new_node = new node();
	pnode now_node = root;
	while (arr_ind < size)
	{
		if (arr[arr_ind] < now_node->get_key()) 
		{

		}
		else
		{

		}


	}
	return root;
}
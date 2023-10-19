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
	

	pnode now_node = root;
	while (arr_ind < size)
	{
		pnode new_node = new node(arr[arr_ind]);
		insert_to_tree(root, new_node);
		arr_ind++;

	}
	return root;
}
void insert_to_tree(pnode root, pnode new_node)
{
	while (1)
	{
		pnode now = root;
		if (new_node->get_key() < now->get_key())
		{
			now = now->get_left();
			if (now == NULL)
			{
				now = new_node;
				printf("Insertion of %d succesful! \n", new_node->get_key());
				return;
			}
		}
		else if (new_node->get_key() > now->get_key())
		{
			now = now->get_right();
			if (now == NULL)
			{
				now = new_node;
				printf("Insertion of %d succesful! \n", new_node->get_key());
				return;
			}
		}
		else
			return;
	}

}
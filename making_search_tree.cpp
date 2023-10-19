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
	pnode now = root;
	while (1)
	{
		
		if (new_node->get_key() < now->get_key())
		{
			
			if (now->get_left() == NULL)
			{
				now->set_left(new_node);
				//printf("Insertion of %d succesful! \n", new_node->get_key());
				return;
			}
			now = now->get_left();
		}
		else if (new_node->get_key() > now->get_key())
		{
			if (now->get_right() == NULL)
			{
				now->set_right(new_node);
				//printf("Insertion of %d succesful! \n", new_node->get_key());
				return;
			}
			now = now->get_right();
		}
		else
			return;
	}
}
void print_tree_for_debugging(pnode root, int n)
{
	if (!root)
		return;
	if (root->get_right()!=nullptr);
		print_tree_for_debugging(root->get_right(),n+5);

	for (int i = 0; i < n; i++)
	{
		printf("%s", " ");
	}
	printf("%d", root->get_key());
	printf("%s", "\n");
	
	if (root->get_left()!=nullptr);
		print_tree_for_debugging(root->get_left(),n+5);
}
#include "class.h"
node::node()
{
	this->key = -1;
	this->left = nullptr;
	this->right = nullptr;
}
node::node(int k)
{
	this->key = k;
	this->left = nullptr;
	this->right = nullptr;
}
uint32_t node::get_key()
{
	return this->key;
}
node* node::get_left()
{
	return this->left;
}
node* node::get_right()
{
	return this->right;
}
void node::set_key(uint32_t num)
{
	this->key = num;
}
void node::set_left(node *left)
{
	this->left = left;
}
void node::set_right(node *right)
{
	this->right = right;
}

void node::print_tree_for_debugging(node *root, int n) {
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
void node::insert_to_tree(pnode root, pnode new_node) {
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

pnode node::maketree(int *arr, int size) {
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
        node::insert_to_tree(root,new_node);
        arr_ind++;

    }
    return root;
}

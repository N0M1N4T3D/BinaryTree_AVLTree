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
void node::print_tree_for_debugging(pnode root, int n) {
    if (!root)
        return;
    if (root->right!=nullptr);
    print_tree_for_debugging(root->right,n+5);

    for (int i = 0; i < n; i++)
    {
        printf("%s", " ");
    }
    printf("%d", root->key);
    printf("%s", "\n");

    if (root->left!=nullptr);
    print_tree_for_debugging(root->left,n+5);
}

void node::insert_to_tree(pnode root, pnode new_node) {
    pnode now = root;
    while (1)
    {

        if (new_node->key < now->key)
        {

            if (now->left == NULL)
            {
                now->left=new_node;
                //printf("Insertion of %d succesful! \n", new_node->get_key());
                return;
            }
            now = now->left;
        }
        else if (new_node->key > now->key)
        {
            if (now->right == NULL)
            {
                now->right=new_node;
                //printf("Insertion of %d succesful! \n", new_node->get_key());
                return;
            }
            now = now->right;
        }
        else
            return;
    }
}

pnode node::maketree_search(uint32_t *arr, int size, int iter_show_flag) {
    if (size == 0)
    {
        printf("ERROR! Invalid count!!!\n");
        return nullptr;
    }
    pnode root = new node(arr[size/2]);
    int arr_ind = 0;


    pnode now_node = root;
    while (arr_ind < size)
    {
        if (iter_show_flag) {
            if (arr_ind != size / 2) {
                pnode new_node = new node(arr[arr_ind]);
                node::insert_to_tree(root, new_node);
                if (arr_ind%5000==0)
                    printf("%s %d \n", "Iteration: ", arr_ind+1);
            }
        }
        else
        {
            if (arr_ind != size / 2) {
                pnode new_node = new node(arr[arr_ind]);
                node::insert_to_tree(root, new_node);
            }
        }
        arr_ind++;
    }
    printf("%s %d","Tree created succesfully, number of elements: ",arr_ind);
    return root;
}

uint32_t *node::generate_new_array(uint32_t * arr) {
    for (int i=0;i<ar_size;i++)
    {
        arr[i] = i+1;
    }
    srand(time(NULL));
    for(int i=0;i<100*ar_size;i++) {

        int ind1 = rand() % (ar_size+1), ind2 = rand() % (ar_size+1);
        if (ind1!=ind2) {
            uint32_t tmp = arr[ind1];
            arr[ind1] = arr[ind2];
            arr[ind2] = tmp;
        }
    }
    return arr;
}



#include "class.h"
int counter_write=0;
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
int node::get_key()
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
void node::set_key(int num)
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

pnode node::maketree_search(int *arr, int size, int iter_show_flag) {
    if (size == 0)
    {
        printf("ERROR! Invalid count!!!\n");
        return nullptr;
    }
    pnode root = new node(arr[size/2]);
    int arr_ind = 0;


    pnode now_node = root;
    printf("Making tree with %d elements \n",ar_size);
    while (arr_ind < size)
    {
        if (iter_show_flag) {
            if (arr_ind != size / 2) {
                pnode new_node = new node(arr[arr_ind]);
                node::insert_to_tree(root, new_node);
                if (arr_ind%5000==0)
                    printf("%s %d \n", "Iteration: ", arr_ind);
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
    printf("%s %d \n","Tree created succesfully, number of elements: ",arr_ind);
    return root;
}

int *node::generate_new_array(int * arr) {
    for (int i=0;i<ar_size;i++)
    {
        arr[i] = i+1;
    }
    srand(time(NULL));
    for(int i=0;i<100*ar_size;i++) {

        int ind1 = rand() % (ar_size+1), ind2 = rand() % (ar_size+1);
        if (ind1!=ind2) {
            int tmp = arr[ind1];
            arr[ind1] = arr[ind2];
            arr[ind2] = tmp;
        }
    }
    return arr;
}
int node::char_to_digit(char ch) {
        return (int)(ch)%48;
}
void node::init_dfs_bin_to_f(pnode root) {
    FILE * f;
    fopen_s(&f,bin_file_way,"wb");
    dfs_bin_to_f(root,f);
    fclose(f);
}
void node::dfs_bin_to_f(pnode root, FILE *f) {
    if (counter_write%5000==0)
    {
        printf("%s %d \n", "Went data count: ", counter_write);
    }
    char tmp1[10] = "#";
    only_str_10bytes s2;
    strcpy_s(s2.key,tmp1);
    if (!root)
    {
        fwrite(&s2,1,sizeof(s2),f);
        counter_write++;
        return;
    }
    else {
        only_str_10bytes s1;
        char tmp[10];
        char num[10];
        _itoa_s(root->key, num, 10);
        strcpy_s(s1.key, num);
        fwrite(&s1, 1, sizeof(s1), f);
        counter_write++;
        dfs_bin_to_f(root->left, f);
        dfs_bin_to_f(root->right, f);
    }
}
pnode node::dfs_bin_from_f(pnode root, FILE *f) {
    char octothorpe[10] = "#";
    root = new node;
    char buf_for_readen_key[10];
    only_str_10bytes buf_for_struct;
    if (!feof(f)){
        fread(&buf_for_struct,1,sizeof(buf_for_struct),f);
        strcpy_s(buf_for_readen_key,buf_for_struct.key);
        if (!strcmp(buf_for_readen_key, octothorpe)) {
            return nullptr;
        } else {

            root->key = atoi(buf_for_readen_key);
            root->left = dfs_bin_from_f(root->left, f);
            root->right = dfs_bin_from_f(root->right, f);
        }
    }
    return root;
}
pnode node::init_dfs_bin_from_f(pnode root) {
    FILE * f;
    fopen_s(&f,bin_file_way,"rb");
    root = new node;
    root = dfs_bin_from_f(root,f);
    fclose(f);
    return root;
}
void node::KLP(pnode root) {
    if (root!=NULL) {
        printf("%d", root->key);
        KLP(root->left);
        KLP(root->right);
    }
}

node* search(node* n, int a) {
    if (n == NULL){
        return NULL;
    }
    else if (a < n->get_key()){
        return search(n->get_left(), a);
    }
    else if (a > n->get_key()) {
        return search(n->get_right(), a);
    }
    return n;
}
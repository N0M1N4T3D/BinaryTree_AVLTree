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
    while (arr_ind < size-1)
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
    printf("%s %d \n","Tree created succesfully, number of elements: ",arr_ind+1);
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

//нужно переделать в запись в бинарный файл по структурам
void node::put_tree_into_file_txt() {
    std::ofstream out(file_way,std::ios_base::app);
    help_insert_recurse_func_txt(this,out);

}

pnode node::get_tree_from_file_txt() {
    //не получилось, нужно наверное заносить в бинарный файл и считывать структурами с ключами
    std::ifstream in(file_way);
    pnode root = new node;
    root = help_read_recurse_func_txt(root,in);
    in.close();
    return root;
}

int node::char_to_digit(char ch) {

        return (int)(ch)%48;

    return -1;
}

pnode node::help_read_recurse_func_txt(pnode root, std::ifstream &in) {
    char ch;
    root=new node;
    if (in >> std::noskipws >> ch)
    {
        if (ch=='#')
        {
            return nullptr;
        }
        else if (ch=='/') {
            int num=0;
            while (in >> std::noskipws >> ch)
            {
                if (ch=='/')
                    break;
                else
                    num = num*10 + char_to_digit(ch);
            }
            root->key=num;
            root->left=help_read_recurse_func_txt(root->left,in);
            root->right=help_read_recurse_func_txt(root->right,in);
        }
    }
    return root;
}

void node::help_insert_recurse_func_txt(pnode root, std::ofstream &out) {
    if (out.is_open())
    {
        if (!root)
        {
            out << "#";
            return;
        }
        out << "/" + std::to_string(root->key) +"/";
        help_insert_recurse_func_txt(root->left,out);
        help_insert_recurse_func_txt(root->right, out);
    }
    else
    {
        printf("%s \n","Error occured!");
    }
}

void node::put_tree_into_file_bin() {
    FILE * f;
    f = fopen(bin_file_way,"wb");
    file_struct a1, a2;
    char tmp[8] = "abcde";
    char tmp2[8] = "abcdefg";
    strcpy(a1.key, tmp);
    strcpy(a2.key, tmp2);
    fwrite(reinterpret_cast<char*> (&a1),sizeof(file_struct),1,f);
    fwrite(reinterpret_cast<char*> (&a2),sizeof(file_struct),1,f);
    fclose(f);
}

pnode node::get_tree_from_file_bin() {
    pnode root = new node();
    FILE * f;
    f = fopen(bin_file_way,"rb");
    file_struct a1;
    fread(reinterpret_cast<char*> (&a1),sizeof(file_struct),1,f);
    printf("%s \n",a1.key);
    file_struct a2;
    fread(reinterpret_cast<char*> (&a2),sizeof(file_struct),1,f);
    printf("%s \n",a2.key);
    return root;
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
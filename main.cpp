#include "class.h"

void print_array_main();
int array_main[ar_size];

int main()
{
    std::ofstream outf(file_way);
    outf.close();
    pnode root = new node();
    pnode root1 = new node();
    node::generate_new_array(array_main);
    root = node::maketree_search(array_main,ar_size,1);
    root->put_tree_into_file();
    node::print_tree_for_debugging(root,0);
    printf("\n\n\n");

    root1 = root->get_tree_from_file();
    node::print_tree_for_debugging(root1,0);
    return 0;
}
void print_array_main()
{
    for(int i=0;i<ar_size;i++)
    {
        printf("%d",array_main[i]);
    }
}
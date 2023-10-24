#include "class.h"

void print_array_main();
int array_main[ar_size];

int main()
{
    node::generate_new_array(array_main);
    pnode root = new node();
    root = node::maketree_search(array_main, ar_size, 1);
    node::printTree(root);
    node::search(root, 5);
    printf("Ending of programm");
    return 0;
}

void print_array_main()
{
    for (int i = 0; i < ar_size; i++)
    {
        printf("%d", array_main[i]);
    }
}
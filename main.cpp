#include "class.h"
/*
 * краткое руководство что да как:
 * все функции работы с деревом расположены в классе, некоторые как статические, например создание дерева
 * значения глобальных переменных, таких как путь до файлика, размер элементов лежат в заголовочном файле
 * класса
 */

void print_array_main();
int array_main[ar_size];

int main()
{
    node::generate_new_array(array_main);
    //создание дерева и запихивание его в файл
    pnode root = new node();
    root = node::maketree_search(array_main,ar_size,1);
    //root->KLP(root);
    //node::print_tree_for_debugging(root,ar_size);
    node::init_dfs_bin_to_f(root);
    //node::print_tree_for_debugging(root,ar_size);
    //pnode new_root = node::init_dfs_bin_from_f(new_root);
    //printf("\n\n\n\n\n\n");
    //node::print_tree_for_debugging(new_root,ar_size);

    printf("Ending of programm");
    return 0;
}

void print_array_main()
{
    for(int i=0;i<ar_size;i++)
    {
        printf("%d",array_main[i]);
    }
}

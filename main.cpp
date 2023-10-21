#include "class.h"
/*
 * краткое руководство что да как:
 * все функции работы с деревом расположены в классе, некоторые как статические, например создание дерева
 * значения глобальных переменных, таких как путь до файлика, размер элементов лежат в заголовочном файле
 * класса
 */
//функция для удобства, посмотреть на то, что сгенерировалось
void print_array_main();

int array_main[ar_size];

void bfs_bin_to_f(pnode root)
{
    struct only_str_10bytes{
        char key[10];
    };
    FILE * f;
    f = fopen(bin_file_way,"wb");
    if (root)
    {
        std::queue <pnode> q;
        q.push(root);
        while (!q.empty())
        {
            pnode node = q.front();
            q.pop();
            only_str_10bytes s1;
            char tmp[10];
            strcpy(s1.key,itoa(node->get_key(),tmp,10));
            fwrite(&s1,1,sizeof(s1),f);
            if (!node->get_left())
            {
                char tmp1[10] = "#########";
                only_str_10bytes s2;
                strcpy(s2.key,tmp1);
                fwrite(&s2,1,sizeof(s2),f);
            }
            else
            {
                q.push(node->get_left());
            }
            if (!node->get_right())
            {
                char tmp1[10] = "#########";
                only_str_10bytes s2;
                strcpy(s2.key,tmp1);
                fwrite(&s2,1,sizeof(s2),f);
            }
            else
            {
                q.push(node->get_right());
            }
        }
    }
    fclose(f);
}
void dfs_bin_to_f(pnode root, FILE * f){
    struct only_str_10bytes{
        char key[10];
    };
    char tmp1[10] = "#########";
    only_str_10bytes s2;
    strcpy(s2.key,tmp1);
    if (!root)
    {
        fwrite(&s2,1,sizeof(s2),f);
        return;
    }
    only_str_10bytes s1;
    char tmp[10];
    strcpy(s1.key,itoa(root->get_key(),tmp,10));
    fwrite(&s1,1,sizeof(s1),f);
    dfs_bin_to_f(root->get_left(),f);
    dfs_bin_to_f(root->get_right(), f);
}
void init_dfs_bin_to_f(pnode root){
    FILE * f;
    f = fopen(bin_file_way,"wb");
    dfs_bin_to_f(root,f);
}
pnode dfs_bin_from_f(pnode root, FILE *f)
{
    struct only_str_10bytes{
        char key[10];
    };
    char tmp1[10] = "#########";
    only_str_10bytes s2;
    strcpy(s2.key,tmp1);
    root = new node;
    char read_new[10];
    only_str_10bytes readen;
    while (!feof(f)){
        fread(&readen,1,sizeof(readen),f);
        strcpy(read_new,readen.key);
        if (!strcmp(read_new,tmp1))
        {
            return nullptr;
        }
        else
        {
            root->set_key(atoi(read_new));
            root->set_left(dfs_bin_from_f(root->get_left(),f));
            root->set_right(dfs_bin_from_f(root->get_left(),f));
//            root->right=help_read_recurse_func_txt(root->right,in);
        }
    }
    return root;
}
pnode init_dfs_bin_from_f(pnode root){
    FILE * f;
    f= fopen(bin_file_way,"rb");
    dfs_bin_from_f(root,f);
}
pnode bfs_bin_from_f()
{
    FILE * f;
    f = fopen(bin_file_way,"rb");
    struct only_str_10bytes{
        char key[10];
    };
    std::queue <pnode> q;
    only_str_10bytes tmp1;
    fread(&tmp1,1,sizeof(tmp1),f);
    pnode root = new node(atoi(tmp1.key));
    pnode now_knot =root;
    while (!feof(f)) {
        q.push(root);
        if (fread(&tmp1, 1, sizeof(tmp1), f)) {
            char cmp[10] = "#########";
            if (strcmp(tmp1.key, cmp) == 0) {
                fread(&tmp1, 1, sizeof(tmp1), f);
                pnode newnode = new node(atoi(tmp1.key));
            }

        }
    }
}
int main()
{


    //эти 2 строки для прочистки файла, поэтому если не надо прочищать, то уберите
    //но перед запуском, где будет информация запихиваться в файл надо чистить
    std::ofstream outf(file_way);
    outf.close();

    //генерация массива псевдослучайных чисел
    node::generate_new_array(array_main);

    //тестовая функция для бинарного файла...
    //root->put_tree_into_file_bin();

    //создание дерева и запихивание его в файл
    pnode root = new node();
    root = node::maketree_search(array_main,ar_size,1);
    init_dfs_bin_to_f(root);
    //root->put_tree_into_file_txt();
    //node::print_tree_for_debugging(root,0);


    //Доставание дерева (убирайте очистку дерева, если только это запускаете)
    //pnode root1 = new node();
    //root1 = root1->get_tree_from_file_txt();
    //node::print_tree_for_debugging(root1,0);

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
//разбираюсь с бинарниками сишными
//    struct tmp{
//        char str[8];
//    };
//
//    FILE * f;
//    f = fopen(bin_file_way, "wb");
//    char ch_str[8]="drdrdrd";
//    tmp ns;
//    strcpy(ns.str, ch_str);
//    for (int i=0;i<1000000;i++) {
//        fwrite(&ns, 1, sizeof(ns), f);
//    }
//    fclose(f);
//
//    f= fopen(bin_file_way,"rb");
//    tmp l;
//    for (int i=0;i<1000000;i++) {
//        fread(&l, 1, sizeof(l), f);
//        printf("%s \n", l.str);
//    }
//    fclose(f);
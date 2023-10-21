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

int main()
{
    //разбираюсь с бинарниками сишными

    struct tmp{
        char str[8];
    };

    FILE * f;
    f = fopen(bin_file_way, "wb");
    char ch_str[8]="drdrdrd";
    tmp ns;
    strcpy(ns.str, ch_str);
    for (int i=0;i<1000000;i++) {
        fwrite(&ns, 1, sizeof(ns), f);
    }
    fclose(f);

    f= fopen(bin_file_way,"rb");
    tmp l;
    for (int i=0;i<1000000;i++) {
        fread(&l, 1, sizeof(l), f);
        printf("%s \n", l.str);
    }
    fclose(f);

    return 0;





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
    root->put_tree_into_file_txt();
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
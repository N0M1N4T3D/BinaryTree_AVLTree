#include "class.h"
/*
 * ������� ����������� ��� �� ���:
 * ��� ������� ������ � ������� ����������� � ������, ��������� ��� �����������, �������� �������� ������
 * �������� ���������� ����������, ����� ��� ���� �� �������, ������ ��������� ����� � ������������ �����
 * ������
 */
//������� ��� ��������, ���������� �� ��, ��� ���������������
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

int main()
{


    //��� 2 ������ ��� ��������� �����, ������� ���� �� ���� ���������, �� �������
    //�� ����� ��������, ��� ����� ���������� ������������ � ���� ���� �������
    std::ofstream outf(file_way);
    outf.close();

    //��������� ������� ��������������� �����
    node::generate_new_array(array_main);

    //�������� ������ � ����������� ��� � ����
    pnode root = new node();
    root = node::maketree_search(array_main,ar_size,1);
    node::init_dfs_bin_to_f(root);
    node::print_tree_for_debugging(root,ar_size);
    //pnode new_root = node::init_dfs_bin_from_f(root);
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
//���������� � ����������� �������
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
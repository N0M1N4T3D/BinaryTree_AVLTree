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

int main()
{
    //��� 2 ������ ��� ��������� �����, ������� ���� �� ���� ���������, �� �������
    //�� ����� ��������, ��� ����� ���������� ������������ � ���� ���� �������
    std::ofstream outf(file_way);
    outf.close();

    //��������� ������� ��������������� �����
    node::generate_new_array(array_main);

    //�������� ������� ��� ��������� �����...
    //root->put_tree_into_file_bin();

    //�������� ������ � ����������� ��� � ����
//    pnode root = new node();
//    root = node::maketree_search(array_main,ar_size,1);
//    root->put_tree_into_file_txt();
//    node::print_tree_for_debugging(root,0);


    //���������� ������ (�������� ������� ������, ���� ������ ��� ����������)
//    pnode root1 = new node();
//    root1 = root1->get_tree_from_file();
//    node::print_tree_for_debugging(root1,0);

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
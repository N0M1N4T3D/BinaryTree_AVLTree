#pragma once
#include <cstdint>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <fstream>
#include <string>

#define ar_size 80000
//сюда свой файл напишите, где создаваться ему...
#define file_way "C:\\Codes_progr\\tree.txt"
#define bin_file_way "C:\\Codes_progr\\tree_b.bin"

struct only_str_10bytes{
    char key[6];
};

class node;
typedef node* pnode;

class node {
public:
	node();
	node(int k);
	int get_key();
	node* get_left();
	node* get_right();

	static void print_tree_for_debugging(pnode root, int n);
    static pnode maketree_search(int * arr, int size, int iter_show_flag=0);
    static int * generate_new_array(int * arr);

    node* search(node* n, int a);
	void set_key(int num);
	void set_left(node * left);
	void set_right(node * right);
    void KLP(pnode root);

    static pnode init_dfs_bin_from_f(pnode root);
    static void init_dfs_bin_to_f(pnode root);

private:
    static pnode dfs_bin_from_f(pnode root, FILE *f);
    static void dfs_bin_to_f(pnode root, FILE * f);

    static void insert_to_tree(pnode root, pnode new_node);
    static int char_to_digit(char ch);
    node* left;
    int key;
    node* right;
};
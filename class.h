#pragma once
#include <cstdint>
#include <string>
#include <cstdio>
#include <time.h>
#include <fstream>

#define ar_size 1000
#define file_way "C:\\Codes_progr\\tree.txt"

class node;
class avl_node;
typedef avl_node* pavl;
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

	void set_key(int num);
	void set_left(node * left);
	void set_right(node * right);
    void put_tree_into_file();
    pnode get_tree_from_file();

private:
    static void insert_to_tree(pnode root, pnode new_node);
    node* left;
    int key;
    node* right;
};
#pragma once
#include <cstdint>
#include <string>
#include <cstdio>
#include <time.h>
#include <fstream>

#define ar_size 1000000

class node;
class avl_node;
typedef avl_node* pavl;
typedef node* pnode;

class node {
public:
	node();
	node(int k);
	uint32_t get_key();
	node* get_left();
	node* get_right();

	static void print_tree_for_debugging(pnode root, int n);
    static pnode maketree_search(uint32_t * arr, int size, int iter_show_flag=0);
    static uint32_t * generate_new_array(uint32_t * arr);

	void set_key(uint32_t num);
	void set_left(node * left);
	void set_right(node * right);

private:
    static void insert_to_tree(pnode root, pnode new_node);
    node* left;
    uint32_t key;
    node* right;
};
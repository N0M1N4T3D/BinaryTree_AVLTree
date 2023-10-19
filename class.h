#pragma once
#include <cstdint>
#include <string>
#include <cstdio>
#include <time.h>

class node {
    typedef node* pnode;
public:
	node();
	node(int k);
	uint32_t get_key();
	node* get_left();
	node* get_right();

	static void print_tree_for_debugging(node* root, int n);
    static pnode maketree(uint32_t * arr, int size);
    static uint32_t * generate_new_array(uint32_t * arr);

	void set_key(uint32_t num);
	void set_left(node * left);
	void set_right(node * right);
private:
    static void insert_to_tree(pnode root, pnode new_node);
	node* left;
	node* right;
	uint32_t key;
};
typedef node* pnode;
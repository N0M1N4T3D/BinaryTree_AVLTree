#pragma once
#include <cstdint>
#include <string>
#include <cstdio>
#include <time.h>

#define ar_size 10000

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

class avl_node:public node{

    pavl left;
    pavl right;
    uint32_t key;
    int8_t balance_factor;

    static pavl  right_rotation(pavl pivot);
    static pavl left_rotation(pavl pivot);

public:
    void set_balance_factor(int8_t x);
    int8_t get_balance_factor();
    avl_node();
    avl_node(uint32_t num);

    static void insert_element(pavl root, pavl node);

};
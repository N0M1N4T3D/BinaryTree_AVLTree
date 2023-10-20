#pragma once
#include <cstdint>
#include <string>
#include <cstdio>
#include <time.h>

#define ar_size 10000

class node {
    typedef node* pnode;
public:
	node();
	node(int k);
	uint32_t get_key();
	node* get_left();
	node* get_right();
    int8_t get_balance_factor();

	static void print_tree_for_debugging(pnode root, int n);
    static pnode maketree_search(uint32_t * arr, int size, int iter_show_flag=0);



    static uint32_t * generate_new_array(uint32_t * arr);

	void set_key(uint32_t num);
	void set_left(node * left);
	void set_right(node * right);
    void set_balance_factor(int8_t x);
private:
    static void insert_to_tree(pnode root, pnode new_node);

    static void right_rotation(pnode pivot);
    //эти данные для обычного дерева поиска и бинарного дерева поиска
	node* left;
	node* right;
	uint32_t key;
    //это для бинарного дерева поиска
    int8_t balance_factor;
};
typedef node* pnode;
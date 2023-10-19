#pragma once
#include <cstdint>
#include <string>
class node {
public:
	//std::string data;
	node();
	node(int k);
	uint32_t get_key();
	node* get_left();
	node* get_right();
	
	void set_key(uint32_t num);
	void set_left(node * left);
	void set_right(node * right);

private:
	node* left;
	node* right;
	uint32_t key;
};
typedef node* pnode;
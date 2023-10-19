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
private:
	node* left;
	node* right;
	uint32_t key;
};
typedef node* pnode;
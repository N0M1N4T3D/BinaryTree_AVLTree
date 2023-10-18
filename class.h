#include <cstdint>
#include <string>
class node {
	node* left;
	node* right;
	uint32_t key;
	std::string data;
};
typedef node* pnode;
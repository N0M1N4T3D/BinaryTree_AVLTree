#include "class.h"
node::node()
{
	this->key = -1;
	this->left = nullptr;
	this->right = nullptr;
}
node::node(int k)
{
	this->key = k;
	this->left = nullptr;
	this->right = nullptr;
}
uint32_t node::get_key()
{
	return this->key;
}
node* node::get_left()
{
	return this->left;
}
node* node::get_right()
{
	return this->right;
}
void node::set_key(uint32_t num)
{
	this->key = num;
}
void node::set_left(node *left)
{
	this->left = left;
}
void node::set_right(node *right)
{
	this->left = right;
}
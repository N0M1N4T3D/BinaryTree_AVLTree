#pragma once
#include "class.h"
pnode maketree(int* arr, int size);
void insert_to_tree(pnode root, pnode new_node);
void print_tree_for_debugging(pnode root, int n);
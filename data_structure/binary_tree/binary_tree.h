#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#endif

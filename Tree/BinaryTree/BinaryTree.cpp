#include <iostream>
#include "BinaryTree.h"

Node::Node() {}

Node::Node(int _val) {
	val = _val;
	left = NULL;
	right = NULL;
}

Node::Node(int _val, Node* _left, Node* _right) {
	val = _val;
	left = _left;
	right = _right;
}

/*
           0
         /    \
        1      8
      /   \     \
     2     3     9
    / \   / \   /
   4   5 6   7 10
*/
Node* makeBinaryTree() {
	Node* root = new Node(0);
	root->left = new Node(1);
	root->left->left = new Node(2);
	root->left->right = new Node(3);
	root->left->left->left = new Node(4);
	root->left->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);

	root->right = new Node(8);
	root->right->right = new Node(9);
	root->right->right->left = new Node(10);
	return root;
}

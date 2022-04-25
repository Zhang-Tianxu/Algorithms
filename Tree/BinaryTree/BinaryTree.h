#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

class Node {
	public:
		int val;
		Node* left;
		Node* right;

		Node();
		Node(int _val);
		Node(int _val, Node* _left, Node* _right);
};

/*
           0
         /    \
        1      8
      /   \     \
     2     3     9
    / \   / \   /
   4   5 6   7 10

pre order: [0, 1, 2, 4, 5, 3, 6, 7, 8, 9, 10]
in order: [4, 2, 5, 1, 6, 3, 7, 0, 8, 10 ,9]
post order: [4, 5, 2, 6, 7, 3, 1, 10, 9 , 8, 0]
level: [0, 1, 8, 2, 3, 9, 4, 5, 6, 7, 10]
*/
Node* makeBinaryTree();

#endif

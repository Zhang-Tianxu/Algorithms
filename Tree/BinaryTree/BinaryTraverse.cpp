#include <iostream>
#include <stack>
#include <queue>
#include "BinaryTree.h"

using namespace std;

void pre_order_traverse_recursive(Node* root) {
	if(root == nullptr)
		return;
	cout << root->val << " ";
	pre_order_traverse_recursive(root->left);
	pre_order_traverse_recursive(root->right);
}

void pre_order_traverse_non_recursive(Node* root) {
	stack<Node*> s;
	Node* p = root;
	while(p || !s.empty()) {
		while(p) {
			cout << p->val << " ";
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		p = p->right;
	}

}

void in_order_traverse_recursive(Node* root) {
	if(root == nullptr)
		return;
	in_order_traverse_recursive(root->left);
	cout << root->val << " ";
	in_order_traverse_recursive(root->right);
}

void in_order_traverse_non_recursive(Node* root) {
	stack<Node*> s;
	Node* p = root;
	while(p || !s.empty()) {
		while(p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		cout << p->val << " ";
		p = p->right;
	}
}

void post_order_traverse_recursive(Node* root) {
	if(root == nullptr)
		return;
	post_order_traverse_recursive(root->left);
	post_order_traverse_recursive(root->right);
	cout << root->val << " ";
}

void post_order_traverse_non_recursive(Node* root) {
	stack<Node*> s;
	Node* p = root;
	Node* last_visit_node = root;
	while(p || !s.empty()) {
		while(p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		if(p->right == nullptr || p->right == last_visit_node) {
			cout << p->val << " ";
			last_visit_node = p;
			p = nullptr;
			s.pop();
		} else {
			p = p->right;
		}
	}
}

void level_traverse(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* p = q.front();
		q.pop();
		cout << p->val << " ";
		if(p->left)
			q.push(p->left);
		if(p->right)
			q.push(p->right);
	}
}

void level_traverse_seperate(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int len = q.size();
		for(int i = 0;i < len;i++) {
			Node* p = q.front();
			q.pop();
			cout << p->val << " ";
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
		cout << " | ";
	}
}

int main() {
	Node *binaryTreeRoot = makeBinaryTree();

	cout << "pre order recursive traverse: ";
	pre_order_traverse_recursive(binaryTreeRoot);
	cout << endl;

	cout << "pre order non recursive traverse: ";
	pre_order_traverse_non_recursive(binaryTreeRoot);
	cout << endl;


	cout << "in order recursive traverse: ";
	in_order_traverse_recursive(binaryTreeRoot);
	cout << endl;

	cout << "in order non recursive traverse: ";
	in_order_traverse_non_recursive(binaryTreeRoot);
	cout << endl;


	cout << "post order recursive traverse: ";
	post_order_traverse_recursive(binaryTreeRoot);
	cout << endl;

	cout << "post order recursive non traverse: ";
	post_order_traverse_non_recursive(binaryTreeRoot);
	cout << endl;


	cout << "level traverse: ";
	level_traverse(binaryTreeRoot);
	cout << endl;

	cout << "level traverse seperate: ";
	level_traverse_seperate(binaryTreeRoot);
	cout << endl;
}

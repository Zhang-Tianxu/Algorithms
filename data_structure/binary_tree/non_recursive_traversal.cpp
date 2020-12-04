/*
 * 将递归改为非递归，需要用到栈。
 *
 */

#include <stack>

#include "binary_tree.h"


using namespace std;
void preorder_traversal(TreeNode* root) {
    stack<TreeNode*> tree_stack;
    TreeNode* p = root;
    while(p || !tree_stack.empty()) {
        while(p) {
            cout << p->val << endl;
            tree_stack.push(p);
            p = p->left;
        }
        if(!tree_stack.empty()) {
            p = tree_stack.top();
            tree_stack.pop();
            p = p->right;
        }
    }
}
void inorder_traversal(TreeNode* root) {
    stack<TreeNode*> tree_stack;
    TreeNode* p = root;
    while(p|| !tree_stack.empty()) {
        while(p) {
            tree_stack.push(p);
            p = p->left;
        }
        if(!tree_stack.empty()) {
            p = tree_stack.top();
            tree_stack.pop();
            cout << p->val <<endl;
            p = p->right;
        }
    }
}
void postorder_traversal(TreeNode* root) {
    stack<TreeNode*> tree_stack;
    TreeNode* p = root;
    TreeNode* last_visit = root;
    while(p|| !tree_stack.empty()) {
        while(p) {
            tree_stack.push(p);
            p = p->left;
        }
        p = tree_stack.top();
        if(p->right == NULL || p->right == last_visit) {
            cout << p->val << endl;
            tree_stack.pop();
            last_visit = p;
            p = NULL;
        }
        else {
            p = p->right;
        }
    }
}

TreeNode* array2btree(int* array,int len) {

}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    preorder_traversal(root);
    cout << "============================" <<endl;
    inorder_traversal(root);
    cout << "============================" <<endl;
    postorder_traversal(root);
}

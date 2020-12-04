#include "binary_tree.h"

using namespace std;
void preorder_traversal(TreeNode* root) {
    cout << root->val << endl;
    if(root->left) {
        preorder_traversal(root->left);
    }
    if(root->right) {
        preorder_traversal(root->right);
    }
}
void inorder_traversal(TreeNode* root) {
    if(root->left) {
        inorder_traversal(root->left);
    }
    cout << root->val << endl;
    if(root->right) {
        inorder_traversal(root->right);
    }
}
void postorder_traversal(TreeNode* root) {
    if(root->left) {
        postorder_traversal(root->left);
    }
    if(root->right) {
        postorder_traversal(root->right);
    }
    cout << root->val << endl;
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

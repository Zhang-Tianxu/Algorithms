#include "binary_tree.h"
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || p == root || q == root) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    if(!right) return left;
    return root;
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
    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right->right;
    TreeNode* res = lowestCommonAncestor(root,p,q);
    std::cout << res->val << std::endl;
}

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int node1, int node2) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->val == node1 || root->val == node2) {
        return root;
    }
    
    TreeNode* leftLCA = findLCA(root->left, node1, node2);
    TreeNode* rightLCA = findLCA(root->right, node1, node2);
    
    if (leftLCA && rightLCA) {
        return root;
    }
    
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    int node1 = 5;
    int node2 = 1;
    
    TreeNode* lca = findLCA(root, node1, node2);
    std::cout << "LCA of " << node1 << " and " << node2 << " is " << lca->val << std::endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode *left, *right;

	TreeNode(int val) {
		data = val;
		left = right = NULL;
	}
};

class BST {
private:
	TreeNode* root;

	TreeNode* insertNode(TreeNode* node, int val) {
		if(node == NULL) return new TreeNode(val);
		if(val < node->data) node->left = insertNode(node->left, val);
		else if(val > node->data) node->right = insertNode(node->right, val);
		return node;
	}
	
	TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

	TreeNode* deleteNode(TreeNode* node, int val) {
		if(node == NULL) return node;
		if (node->data > val) {
	        node->left = deleteNode(node->left, val);
	    } else if (node->data < val) {
	        node->right = deleteNode(node->right, val);
	    } else {
	        if (node->left == NULL) {
	            TreeNode* temp = node->right;
	            delete node;
	            return temp;
	        } else if (node->right == NULL) {
	            TreeNode* temp = node->left;
	            delete node;
	            return temp;
	        }

	        TreeNode* minRight = findMin(node->right);
	        node->data = minRight->data;
	        node->right = deleteNode(node->right, minRight->data);
	    }
	    return node;
	} 

	void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void storeNodes(TreeNode* node, vector<TreeNode*> &nodes) {
    	if(node == NULL) return ;
    	storeNodes(node->left, nodes);
    	nodes.push_back(node);
    	storeNodes(node->right, nodes);
    }

    TreeNode* buildTree(vector<TreeNode*> nodes, int left, int right) {
    	if(left > right) return NULL;
    	int mid = (left + right) / 2;
    	TreeNode* node = nodes[mid];
    	node->left = buildTree(nodes, left, mid - 1);
    	node->right = buildTree(nodes, mid + 1, right);
    	return node;
    }

public:
	BST() {
		root = NULL;
	}

	void insert(int val) {
		root = insertNode(root, val);
	}

	void delNode(int val) {
		root = deleteNode(root, val);
	}

	void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void buildBST() {
    	vector<TreeNode*> nodes;
    	storeNodes(root, nodes);
    	int n = nodes.size();
    	root = buildTree(nodes, 0, n - 1);
    }
};

int main() {
	BST bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(2);
	bst.insert(4);
	bst.insert(10);
	bst.inorder();
	bst.delNode(5);
	bst.buildBST();
	bst.inorder();
	return 0;
}
#include<iostream>
using namespace std;

struct TreeNode {
public:
	int data;
	int height;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		data = val;
		height = 1;
		left = right = NULL;
	}
};

int height(TreeNode* root) {
	if (root == nullptr) return 0;
	return root->height;
}

int getBal(TreeNode* root) {
	if (root == nullptr) return 0;
	return height(root->left) - height(root->right);
}

TreeNode* minValueNode(TreeNode* root) {
	TreeNode* cur = root;
	while (cur->left != nullptr) {
		cur = cur->left;
	}
	return cur;
}

TreeNode* leftRotate (TreeNode* root) {
	TreeNode* newNode = root->right;
	TreeNode* temp = newNode->left;
	root->right = temp;
	newNode->left = root;
	root->height = 1 + max(height(root->left), height(root->right));
	newNode->height = 1 + max(height(newNode->left), height(newNode->right));
	return newNode;
}

TreeNode* rightRotate (TreeNode* root) {
	TreeNode* newNode = root->left;
	TreeNode* temp = newNode->right;
	root->left = temp;
	newNode->right = root;
	root->height = 1 + max(height(root->left), height(root->right));
	newNode->height = 1 + max(height(newNode->left), height(newNode->right));
	return newNode;
}

TreeNode* insert(TreeNode* root, int val) {
	if (root == nullptr) return new TreeNode(val);
	if (val < root->data) root->left = insert(root->left, val);
	else if (val > root->data) root->right = insert(root->right, val);
	else return root;

	root->height = 1 + max(height(root->left), height(root->right));
	int Balance = getBal(root);

	if (Balance > 1) {
		if (val < root->left->data) {
			return rightRotate(root);
		} else if(val > root->left->data) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}

	if (Balance < -1) {
		if (val > root->right->data) {
			return leftRotate(root);
		} else if(val < root->right->data) {
			root->left = rightRotate(root->left);
			return leftRotate(root);
		}
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) return root;
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            TreeNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp; 
        } else {
            TreeNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) return nullptr;

    root->height = 1 + max(height(root->left), height(root->right));
    int Balance = getBal(root);

    if (Balance > 1 && getBal(root->left) >= 0) return rightRotate(root);
    if (Balance > 1 && getBal(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (Balance < -1 && getBal(root->right) <= 0) return leftRotate(root);
    if (Balance < -1 && getBal(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder (TreeNode* root) {
	if (root == nullptr) return ;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder (TreeNode* root) {
	if (root == nullptr) return ;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void preorder (TreeNode* root) {
	if (root == nullptr) return ;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main() {
	TreeNode* root = nullptr;
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);
	preorder(root);
	root = deleteNode(root, 10);
	cout << endl;
	preorder(root);
}
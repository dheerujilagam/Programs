#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class TreeNode {
    Node<T>* root;

public:
    TreeNode() : root(nullptr) {}

    void insert(T data) {
        root = insertNode(root, data);
    }

    void inOrder() {
        inOrderTraversal(root);
    }

private:
    Node<T>* insertNode(Node<T>* node, T data) {
        if (node == nullptr) return new Node<T>(data);
        if (data < node->data) node->left = insertNode(node->left, data);
        else if (data > node->data) node->right = insertNode(node->right, data);
        return node;
    }

    void inOrderTraversal(Node<T>* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
};

int main() {
    TreeNode<int> intTree;
    intTree.insert(2);
    intTree.insert(1);
    intTree.insert(3);
    intTree.inOrder();
    cout << endl;

    TreeNode<string> strTree;
    strTree.insert("Hello");
    strTree.insert("Subhash");
    strTree.insert("Jilagam");
    strTree.inOrder();
    cout << endl;
}

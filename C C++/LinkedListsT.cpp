#include<iostream>
using namespace std;

template <typename T> class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        next = nullptr;
    }

    // Node(T data) : data(data), next(nullptr) {}
};

template <typename T> class LinkedList {
    Node<T>* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // LinkedList() : head(nullptr) {}

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node<T>* cur = head;
        while (cur != nullptr) {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList<string> intList;
    intList.push("abc");
    intList.display();
    intList.push("xyz");
    intList.display();
    intList.push("mno");
    intList.display();
}
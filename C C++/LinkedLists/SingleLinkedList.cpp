#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtBegin(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insertAtPosition(int data, int pos) {
        if(pos <= 0) {
            cout << "Invalid Position\n";
            return ;
        }
        Node* new_node = new Node(data);
        if (pos == 1) {
            new_node->next = head;
            head = new_node;
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if(temp == nullptr) {
            cout << "Invalid Position\n";
            return ;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void deleteAtBegin() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if (pos <= 0 || head == nullptr) {
            cout << "Invalid Position or List is empty. Cannot delete.\n";
            return;
        }
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid Position. Cannot delete.\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList* list = new LinkedList();
    list->insertAtBegin(10);
    list->insertAtBegin(9);
    list->insertAtBegin(8);
    list->insertAtBegin(7);
    list->insertAtBegin(6);
    list->insertAtPosition(7, 4);
    list->insertAtEnd(11);

    cout << "Original List: ";
    list->PrintList();

    list->deleteAtEnd();
    cout << "List after deleting at the end: ";
    list->PrintList();

    list->deleteAtPosition(3);
    cout << "List after deleting at position 3: ";
    list->PrintList();

    list->deleteAtBegin();
    cout << "List after deleting at the beginning: ";
    list->PrintList();

    delete list;
    return 0;
}

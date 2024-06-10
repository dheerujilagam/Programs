#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBegin(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    void insertAtPosition(int data, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }
        Node* new_node = new Node(data);
        if (pos == 1) {
            if (head != nullptr) {
                new_node->next = head;
                head->prev = new_node;
            }
            head = new_node;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }
        new_node->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteAtBegin() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
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
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        }
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
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid Position. Cannot delete.\n";
            return;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList* list = new DoublyLinkedList();
    list->insertAtBegin(10);
    list->insertAtBegin(9);
    list->insertAtBegin(8);
    list->insertAtBegin(7);
    list->insertAtBegin(6);
    list->insertAtEnd(11);
    list->insertAtPosition(7, 4);

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

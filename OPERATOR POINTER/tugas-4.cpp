#include <iostream>

using namespace std;

// Node class untuk merepresentasikan elemen dalam linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Method untuk menambahkan elemen baru ke linked list
    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // Method untuk mencetak isi linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Method untuk membalikkan linked list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        head = prev;
    }
};

int main() {
    // Membuat objek linked list
    LinkedList llist;

    // Menambahkan elemen ke linked list
    llist.push(1);
    llist.push(2);
    llist.push(3);
    llist.push(4);
    llist.push(5);

    // Mencetak linked list sebelum dibalik
    cout << "Linked List asli:" << endl;
    llist.printList();

    // Memanggil method reverseList untuk membalikkan linked list
    llist.reverseList();

    // Mencetak linked list setelah dibalik
    cout << "Linked List setelah dibalik:" << endl;
    llist.printList();

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Insert Variations:

    void insert(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
            return;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
            return;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtAnyPosition(int pos, int val) {
        if (pos == 0) {
            insertAtStart(val);
            return;
       }
        Node* temp = head;
        for (int i = 0; i < pos-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position Out of Bonds !" << endl;
            return;
        }
        if (temp == tail) {
            insert(val);
            return;
        }


        Node* newNode = new Node(val);

        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete Variations:

    void deleteAtStart() {
        if (isEmpty()) {
            cout << "List is already empty!" << endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
     
        if (head) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete toDelete;
    }

    void deleteAtEnd() {
        if (isEmpty()) {
            cout << "List is already empty!" << endl;
            return;
        }
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }
        delete toDelete;
    }

    void deleteAtIndex( int pos) {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos == 0) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Pos Out of Bonds !" << endl;
            return;
        }
        if (temp == tail) {
            deleteAtEnd();
            return;
        }
        Node* toDelete = temp;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete toDelete;
    }

    // others:
    int count() {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void sort() {
        if (head == NULL || head->next == NULL)
            return; 

        bool swapped;
        Node* current;
        Node* last = NULL;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current; 
        } while (swapped);
    }


    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = NULL;
    }
};


int main() {
    DoublyLinkedList list;

    cout << "=== INSERT OPERATIONS ===" << endl;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayForward();

    cout << "\nInsert at Start (5):" << endl;
    list.insertAtStart(5);
    list.displayForward();

    cout << "\nInsert at Position 2 (15):" << endl;
    list.insertAtAnyPosition(2, 15);
    list.displayForward();

    cout << "\nInsert at End (40):" << endl;
    list.insert(40);
    list.displayForward();

    cout << "\n=== DELETE OPERATIONS ===" << endl;
    cout << "Delete at Start:" << endl;
    list.deleteAtStart();
    list.displayForward();

    cout << "\nDelete at End:" << endl;
    list.deleteAtEnd();
    list.displayForward();

    cout << "\nDelete at Index 1:" << endl;
    list.deleteAtIndex(1);
    list.displayForward();

    cout << "\n=== OTHER OPERATIONS ===" << endl;
    cout << "Node count: " << list.count() << endl;

    int val = 20;
    cout << "Search " << val << ": ";
    if (list.search(val))
        cout << "Found!" << endl;
    else
        cout << "Not Found!" << endl;

    cout << "\nUnsorted List: ";
    list.displayForward();
    list.insert(25);
    list.insert(5);
    list.insert(50);

    cout << "\nList before sorting: ";
    list.displayForward();
    list.sort();
    cout << "List after sorting: ";
    list.displayForward();

    cout << "\nDisplay backward: ";
    list.displayBackward();

    cout << "\n=== PROGRAM END ===" << endl;
    return 0;
}

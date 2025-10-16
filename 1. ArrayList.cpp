#include <iostream>
using namespace std;

class ArrayList {
    int* arr;
    int capacity;
    int size;

public:
    ArrayList(int initialCapacity = 5) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void insertAtEnd(int value) {
        if (size == capacity)
            resize();
        arr[size++] = value;
    }

    void insertAtBeginning(int value) {
        if (size == capacity)
            resize();
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insertAtPosition(int value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Position out of bounds" << endl;
            return;
        }
        if (size == capacity)
            resize();
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void deleteFromStart() {
        if (isEmpty()) {
            cout << "ArrayList is empty" << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "ArrayList is empty" << endl;
            return;
        }
        size--;
    }

    void deleteAtPosition(int pos) {
        if (isEmpty()) {
            cout << "ArrayList is empty" << endl;
            return;
        }
        if (pos < 0 || pos >= size) {
            cout << "Position out of bounds" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    bool search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return true;
        }
        return false;
    }

    void display() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    ~ArrayList() {
        delete[] arr;
    }
};


int main() {
    ArrayList list;

    list.insertAtEnd(30);
    list.insertAtEnd(10);
    list.insertAtEnd(50);
    list.insertAtBeginning(5);
    list.insertAtPosition(20, 2);

    cout << "ArrayList after insertions: ";
    list.display();

    list.sort();
    cout << "After sorting: ";
    list.display();

    cout << "Searching for 10: " << (list.search(10) ? "Found" : "Not Found") << endl;

    list.deleteFromStart();
    list.deleteAtPosition(1);
    list.deleteFromEnd();

    cout << "After deletions: ";
    list.display();

    return 0;
}

#include <iostream>
using namespace std;


class Node {

public:
	Node* nextNode;
	int data;

	Node() {
		data = 0;
		nextNode = NULL;
	}
	Node(int val) {
		data = val;
		nextNode = NULL;
	}
};


class List {
	Node* headPtr;

	public:
		List() {
			headPtr = NULL;
		}

	// Insertion Variants:
		void insert(int val) {
			Node* newNode = new Node(val);
			if (isEmpty()) {
				headPtr = newNode;
			}
			else {
				Node* temp = headPtr;
				while (temp->nextNode != NULL) {
					temp = temp->nextNode;
				}
				temp->nextNode = newNode;
			}
		}

		void insertAtBeginning(int value) {
			Node* newNode = new Node(value);
			newNode->nextNode = headPtr;
			headPtr = newNode;
			return;
		}

		void insertAtAnyPosition(int value, int position) {
			Node* newNode = new Node(value);
			if (position == 0) {
				insertAtBeginning(value);
				delete newNode;
				return;
			}
			Node* temp = headPtr;
			for (int i = 0; i < position - 1 && temp != NULL; i++) {
				temp = temp->nextNode;
			}
			if (temp == NULL) {
				cout << "Position out of bounds" << endl;
				delete newNode;
				return;
			}
			if (temp->nextNode == NULL) {
				insert(value);
				delete newNode;
				return;
			}
			newNode->nextNode = temp->nextNode;
			temp->nextNode = newNode;
		}

		// Deletion Variants:
		void deleteFromStart() {
			if (isEmpty()) {
				cout << "List is empty" << endl;
				return;
			}
			Node* toDelete = headPtr;
			headPtr = headPtr->nextNode;
			delete toDelete;
		}

		void deleteFromEnd() {
			if (isEmpty()) {
				cout << "List is empty" << endl;
				return;
			}
			if (headPtr->nextNode == NULL) {
				delete headPtr;
				headPtr = NULL;
				return;
			}
			Node* temp = headPtr;
			while (temp->nextNode->nextNode != NULL) {
				temp = temp->nextNode;
			}
			delete temp->nextNode;
			temp->nextNode = NULL;
		}

		void deleteAtAnyPosition(int position) {
			if (isEmpty()) {
				cout << "List is empty" << endl;
				return;
			}
			if (position == 0) {
				deleteFromStart();
				return;
			}
			Node* temp = headPtr;
			for (int i = 0; i < position - 1 && temp != NULL; i++) {
				temp = temp->nextNode;
			}
			if (temp == NULL || temp->nextNode == NULL) {
				cout << "Position out of bounds" << endl;
				return;
			}
			Node* toDelete = temp->nextNode;
			temp->nextNode = toDelete->nextNode;
			delete toDelete;
		}

		void deleteByValue(int value) {
			if (isEmpty()) {
				cout << "List is empty" << endl;
				return;
			}
			if (headPtr->data == value) {
				deleteFromStart();
				return;
			}
			Node* temp = headPtr;
			while (temp->nextNode != NULL && temp->nextNode->data != value) {
				temp = temp->nextNode;
			}
			if (temp->nextNode == NULL) {
				cout << "Value not found" << endl;
				return;
			}
			Node* toDelete = temp->nextNode;
			temp->nextNode = toDelete->nextNode;
			delete toDelete;
		}
		
	//Others:
		bool isEmpty() {
			return headPtr == NULL;
		}

		void display() {
			Node* temp = headPtr;
			while (temp != NULL) {
				cout << temp->data << " -> ";
				temp = temp->nextNode;
			}
			cout << "NULL" << endl;
		}

		bool search(int value) {
			Node* temp = headPtr;
			while (temp != NULL) {
				if (temp->data == value) {
					return true;
				}
				temp = temp->nextNode;
			}
			return false;
		}

		int countNodes() {
			int count = 0;
			Node* temp = headPtr;
			while (temp != NULL) {
				count++;
				temp = temp->nextNode;
			}
			return count;
		}

		void reverse() {
			Node* prev = NULL;
			Node* current = headPtr;
			Node* next = NULL;
			while (current != NULL) {
				next = current->nextNode;
				current->nextNode = prev;
				prev = current;
				current = next;
			}
			headPtr = prev;
		}

		void sort() {
			if (isEmpty() || headPtr->nextNode == NULL) {
				return;
			}
			for (Node* i = headPtr; i != NULL; i = i->nextNode) {
				for (Node* j = i->nextNode; j != NULL; j = j->nextNode) {
					if (i->data > j->data) {
						int temp = i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
			}
		}

	// Clear:
		~List() {
			Node* temp = headPtr;
			while (temp != NULL) {
				Node* toDelete = temp;
				temp = temp->nextNode;
				delete toDelete;
			}
		}


};


int main() {

	List myList;
	myList.insert(10);
	myList.insert(20);
	myList.insert(30);



	
	myList.display();

}
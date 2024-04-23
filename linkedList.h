#pragma once

#pragma once


#include<iostream>
using namespace std;


template <typename T>
class LinkedList {
private:
	struct node {
		T data;
		node* nxt;
	};
	typedef node* nodePtr;

	nodePtr head;
	int size;

public:
	LinkedList();
	~LinkedList();

	// Add a node onto the front of the linked list.
	void push(T x_data);

	// Delete the first node found with the value x, if one exists.
	void removeData(T x_data);

	// Return the first node found in the list
	T firstNode();

	// Output the values in the nodes, one integer per line.
	void print();

	// Return true if there is a node with the value x.
	bool isInList(T x_data);

	// Return a count of the number of nodes in the list.
	int getSize();

	T popFront(); //remove and return value of head
	T popBack();  //remove and return value of tail
	void insert(int index, T val); //insert val based on index
	bool isEmpty();
	T getVal(int index);
	void assign(int index, T val);


};


template <typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	nodePtr p = head, n;
	while (p != NULL)
	{
		n = p;
		p = p->nxt;
		delete n;
	}
	head = NULL;
	size = 0;
}

// Add a node onto the front of the linked list.
template <typename T>
void LinkedList<T>::push(T x_data) {
	nodePtr n;
	// allocate new node
	n = new node;
	n->data = x_data;
	n->nxt = NULL;
	size++;

	if (head == NULL) {
		head = n;
	}
	else {
		nodePtr temp = head;
		while (temp->nxt != NULL) {
			temp = temp->nxt;
		}
		temp->nxt = n;
	}

}

// Delete the first node found with the value x, if one exists.
template <typename T>
void LinkedList<T>::removeData(T x_data) {
	nodePtr prev = head;
	nodePtr curr = head;

	if (isInList(x_data)) {
		while (curr != NULL && curr->data != x_data) {
			prev = curr;
			curr = curr->nxt;
		}

		if (curr != NULL && curr->data == x_data) {
			if (curr == head) {
				head = curr->nxt;
			}
			else {
				prev->nxt = curr->nxt;
			}
			delete curr;
			size--;
		}
	}
	else {
		cout << "ERROR::LinkedList::deleteNode: X_DATA VALUE NOT FOUND" << endl;
	}

}

// Return the first node found in the list
template <typename T>
T LinkedList<T>::firstNode() {
	return head->data;
}

// Output the values in the nodes, one integer per line.
template <typename T>
void LinkedList<T>::print() {
	nodePtr p = head;
	if (p != NULL) {
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->nxt;
		}
	}
	else {
		cout << "ERROR CANNOT PRINT EMPTY LIST" << endl;
	}
}

// Return true if there is a node with the value x.
template <typename T>
bool LinkedList<T>::isInList(T x_data) {
	nodePtr ptr = head;
	while (ptr != NULL) {
		if (ptr->data == x_data) {
			return true;
		}
		ptr = ptr->nxt;
	}
	return false;
}

// Return a count of the number of nodes in the list.
template <typename T>
int LinkedList<T>::getSize() {
	return size;
}


template <typename T>
T LinkedList<T>::popFront() {
	nodePtr temp = head;
	T val = temp->data;

	head = temp->nxt;
	delete temp;

	size--;
	return val;
}


template <typename T>
T LinkedList<T>::popBack() {
	nodePtr prev = head;

	//find node before the one we want to delete
	while (prev->nxt->nxt != NULL) {
		prev = prev->nxt;
	}

	nodePtr delNode = prev->nxt;
	T val = delNode->data;
	prev->nxt = NULL;
	delete delNode;

	size--;
	return val;
}

template <typename T>
void LinkedList<T>::insert(int index, T val) {
	if (index > size) {
		cout << "INDEX IS GREATER THAN SIZE OF LIST; ERROR>>LINKEDLIST<T>::INSERT()" << endl;
	}
	else {
		nodePtr temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->nxt;
		}
		nodePtr newNode;
		newNode = new node;
		newNode->data = val;
		newNode->nxt = temp->nxt;
		temp->nxt = newNode;

		size++;
	}
}


template <typename T>
bool LinkedList<T>::isEmpty() {
	if (size == 0)
		return 1;
	return 0;
}

template<typename T>
T LinkedList<T>::getVal(int index) {
	nodePtr temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->nxt;
	}
	return temp->data;
}


template <typename T>
void LinkedList<T>::assign(int index, T val) {
	nodePtr temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->nxt;
	}
	temp->data = val;
}
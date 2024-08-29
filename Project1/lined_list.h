#pragma once
#include <iostream>
struct Node {
	int data;
	Node* next;
	Node* previous;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void addTOStart(int lvalue);
	void addTOEnd(int value);
	void addAtPos(int value, int index);
	void deleteAtStart();
	void deleteAtEnd();
	void deleteAtPos(int index);
	void display();
private:
	Node* head;
	int length;
};

LinkedList::LinkedList() : head(nullptr), length(0)
{
	
}

LinkedList::~LinkedList()
{
}

void LinkedList::addTOStart(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	newNode->previous = nullptr;
	if (length > 0) {
		head->previous = newNode;
		length++;
		return;
	}
	length++;
	return;
}

void LinkedList::addTOEnd(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (length == 0) {
		newNode->previous = nullptr;
		head = newNode;
		length++;
		return;
	}
	Node* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->previous = temp;
	length++;
}

void LinkedList::display() {
	if (length == 0) {
		std::cout << "List is empty!\n";
	}
	Node* temp = head;
	while (temp) {
		std::cout << temp->data;
		temp = temp->next;
	}
	return;
}

void LinkedList::addAtPos(int value, int pos) {
	if (pos == 1) {
		addTOStart(value);
		return;
	}
	if (pos > length) {
		std::cout << "Invalid position\n";
		return;
	}
	Node* newNode = new Node;
	newNode->data = value;
	Node* temp = head;
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next->previous = newNode;
	temp->next = newNode;
	newNode->previous = temp;
	return;
}

void LinkedList::deleteAtStart() {
	if (length == 0) {
		std::cout << "List is empty, nothing to delete\n";
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	if (!head) {
		head->previous = nullptr;
	}
	length--;
	return;
}

void LinkedList::deleteAtEnd() {
	if (length == 0) {
		std::cout << "List is empty, nothing to delete\n";
		return;
	}
	Node* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->previous->next = nullptr;
	delete temp;
	length--;
	return;
}

void LinkedList::deleteAtPos(int pos) {
	if (pos > length) {
		std::cout << "invalid position given for deletion\n";
	}
	if (length == 1) {
		deleteAtStart();
	}
	Node* temp = head;
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
	}

}
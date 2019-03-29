#include "StringDLinkedList.h"
#include "exceptions.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;

StringDLinkedList::StringDLinkedList() {
	head = nullptr;
	tail = nullptr;
}
//*******************************************************************************************************
//front function. This function will return a constant reference to the first value in the list.		*
//*******************************************************************************************************
const string& StringDLinkedList::front() const {
	if (head == nullptr && tail == nullptr)
		throw EmptyList("No value to show. The list is empty.");
	else
		return head->data;
}

//*******************************************************************************************************
//back function. This function will return a constant reference to the last value in the list.			*
//*******************************************************************************************************
const string& StringDLinkedList::back() const {
	if (head == nullptr && tail == nullptr)
		throw EmptyList("No value to show. The list is empty.");
	else
		return tail->data;
}

//*******************************************************************************************************
//push_front function. This function will add a new value to the beginning of the list.					*
//*******************************************************************************************************
void StringDLinkedList::push_front(const string& data_in) {
	Node* tempPtr;
	tempPtr = new Node;

	if (head == nullptr && tail == nullptr) {
		head = tempPtr;
		tail = tempPtr;
		tempPtr->data = data_in;
		tempPtr->next = nullptr;
		tempPtr->prev = nullptr;
	}

	else {
		tempPtr->data = data_in;
		tempPtr->prev = nullptr;
		tempPtr->next = head;
		head->prev = tempPtr;
		head = tempPtr;
	}
}

//*******************************************************************************************************
//push_back function. This function will add a new value to the end of the list.						*
//*******************************************************************************************************
void StringDLinkedList::push_back(const string& data_in) {
	Node* tempPtr;
	tempPtr = new Node;

	if (head == nullptr && tail == nullptr) {
		head = tempPtr;
		tail = tempPtr;
		tempPtr->data = data_in;
		tempPtr->next = nullptr;
		tempPtr->prev = nullptr;
	}

	else {
		tempPtr->data = data_in;
		tempPtr->next = nullptr;
		tempPtr->prev = tail;
		tail->next = tempPtr;
		tail = tempPtr;
	}
}

//*******************************************************************************************************
//pop_front function. This function will remove the first value of the list.							*
//*******************************************************************************************************
void StringDLinkedList::pop_front() {
	//case if the list is empty.
	if (head == nullptr && tail == nullptr) {
		throw EmptyList("The list is empty. There are no values to delete.");
	}

	//case if the list has only one node.
	else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	
	//case if there's more than one node on the list.
	else {
		Node* tempPtr;
		tempPtr = head;
		head = head->next;
		head->prev = nullptr;
		delete tempPtr;
	}
}

//*******************************************************************************************************
//pup_back function. This function will remove the last value of the list.								*
//*******************************************************************************************************
void StringDLinkedList::pop_back() {
	//case if the list is empty.
	if (head == nullptr && tail == nullptr) {
		throw EmptyList("The list is empty. There are no values to delete.");
	}
	
	//case if the list has only one node.
	else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	//case if there's more than one node in the list.
	else {
		Node* tempPtr;
		tempPtr = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete tempPtr;
	}
}

//*******************************************************************************************************
//remove_inst function. This function will remove all instances of a specific value.					*
//*******************************************************************************************************
void StringDLinkedList::remove_inst(const string& data_in) {
	Node* curr;

	//case if head is an instance to be removed.
	while (head->data == data_in) {
		pop_front();
	}

	//case if tail is an insatnce to be removed. 
	while (tail->data == data_in) {
		pop_back();
	}

	//Update all the info because by this point we know that at this point, neither head or tail
	//are instances to be removed.
	curr = head;

	//case that will deal with all the nodes that are within head and tail.
	while (curr != nullptr) {
		Node* next = curr->next;;
		if (curr->data == data_in) {
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;

			delete curr;
		}
		curr = next;
	}
}

//*******************************************************************************************************
//front_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a foward order.																				*
//*******************************************************************************************************
ostream& StringDLinkedList::front_print(ostream& out) const {
	Node* tempPtr = head;
	out << "{ ";

	if (head == nullptr && tail == nullptr) {
		out << "List is empty. ";
	}
	while (tempPtr != nullptr) {
			out << tempPtr->data << " ";
			tempPtr = tempPtr->next;
	}

	out << "}";
	
	return out;
}

//*******************************************************************************************************
//back_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a backwards order.																			*
//*******************************************************************************************************
ostream& StringDLinkedList::back_print(ostream& out) const {
	Node* tempPtr = tail;
	
	out << "{ ";

	if (head == nullptr && tail == nullptr) {
		out << "List is empty. ";
	}

	while (tempPtr != nullptr)// && repeat) {
	{
		out << tempPtr->data << " ";
		tempPtr = tempPtr->prev;
	}

	out << "}";

	return out;
}

//Default deconstructor.
StringDLinkedList::~StringDLinkedList() {
	
}
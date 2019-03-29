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
	return head->data;
}

//*******************************************************************************************************
//back function. This function will return a constant reference to the last value in the list.			*
//*******************************************************************************************************
const string& StringDLinkedList::back() const {
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
	Node* tempPrev;
	Node* tempCurr;
	Node* tempNext;

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
	tempPrev= head;
	tempCurr = head->next;
	tempNext = tempCurr->next;

	//case that will deal with all the nodes that are within head and tail.
	while (tempCurr->next != tail) {
		if (tempCurr->data == data_in) {
			tempPrev->next = tempNext;
			tempNext->prev = tempPrev;

			delete tempCurr;
			tempCurr = tempNext;
			tempNext = tempNext->next;
		}
		else {
			tempPrev = tempCurr;
			tempCurr = tempNext;
			tempNext = tempNext->next;
		}
	}
}

//*******************************************************************************************************
//front_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a foward order.																				*
//*******************************************************************************************************
ostream& StringDLinkedList::front_print(ostream& out) const {
	bool repeat = true;
	Node* tempPtr = head;
	out << "{ ";

	while (repeat) {
		if (head == nullptr && tail == nullptr) {
			out << "List is empty. ";
			repeat = false;
		}

		else if (tempPtr != nullptr) {
			out << tempPtr->data << " ";
			tempPtr = tempPtr->next;
			repeat = true;
		}
	}

	out << "}";
	
	return out;
}

//*******************************************************************************************************
//back_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a backwards order.																			*
//*******************************************************************************************************
ostream& StringDLinkedList::back_print(ostream& out) const {
	bool repeat = true;
	Node* tempPtr = tail;
	
	out << "{ ";

	while (repeat) {
		if (head == tail) {
			out << "List is empty. ";
			repeat = false;
		}

		else if (tempPtr != nullptr) {
			out << tempPtr->data << " ";
			tempPtr = tempPtr->prev;
			repeat = true;
		}
	}

	out << "}";

	return out;
}

//Default deconstructor.
StringDLinkedList::~StringDLinkedList() {
	
}
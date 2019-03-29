#include "StringDLinkedList.h"
#include <string>
using std::string;

StringDLinkedList::StringDLinkedList() {
	head = nullptr;
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
void StringDLinkedList::push_front(int) {

}

//*******************************************************************************************************
//push_back function. This function will add a new value to the end of the list.						*
//*******************************************************************************************************
void StringDLinkedList::push_back(int) {

}

//*******************************************************************************************************
//pop_front function. This function will remove the first value of the list.							*
//*******************************************************************************************************
void StringDLinkedList::pop_front() {

}

//*******************************************************************************************************
//pup_back function. This function will remove the last value of the list.								*
//*******************************************************************************************************
void StringDLinkedList::pop_back() {

}

//*******************************************************************************************************
//remove_inst function. This function will remove all instances of a specific value.					*
//*******************************************************************************************************
void StringDLinkedList::remove_inst(int) {

}

//*******************************************************************************************************
//front_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a foward order.																				*
//*******************************************************************************************************
ostream& StringDLinkedList::front_print(ostream&) const {

}

//*******************************************************************************************************
//back_print. This function accepts an ostream reference which will be responsible of printing the		*
//list in a backwards order.																			*
//*******************************************************************************************************
ostream& StringDLinkedList::back_print(ostream&) const {

}

//Default deconstructor.
StringDLinkedList::~StringDLinkedList(){

}

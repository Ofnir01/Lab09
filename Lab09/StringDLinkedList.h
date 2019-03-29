#ifndef STRINGD_H_
#define STRINGD_H_
#include <sstream>
#include <string>
using std::string;
using std::ostream;

class StringDLinkedList {
private:
	struct Node {
		string data;
		struct Node* next;
		struct Node* prev;
	};

	Node* head;
	Node* tail;

public:
	//Default constructor.
	StringDLinkedList();

	//*******************************************************************************************************
	//front function. This function will return a constant reference to the first value in the list.		*
	//*******************************************************************************************************
	const string& front() const;

	//*******************************************************************************************************
	//back function. This function will return a constant reference to the last value in the list.			*
	//*******************************************************************************************************
	const string& back() const;

	//*******************************************************************************************************
	//push_front function. This function will add a new value to the beginning of the list.					*
	//*******************************************************************************************************
	void push_front(const string&);

	//*******************************************************************************************************
	//push_back function. This function will add a new value to the end of the list.						*
	//*******************************************************************************************************
	void push_back(const string&);

	//*******************************************************************************************************
	//pop_front function. This function will remove the first value of the list.							*
	//*******************************************************************************************************
	void pop_front();

	//*******************************************************************************************************
	//pup_back function. This function will remove the last value of the list.								*
	//*******************************************************************************************************
	void pop_back();

	//*******************************************************************************************************
	//remove_inst function. This function will remove all instances of a specific value.					*
	//*******************************************************************************************************
	void remove_inst(const string&);

	//*******************************************************************************************************
	//front_print. This function accepts an ostream reference which will be responsible of printing the		*
	//list in a foward order.																				*
	//*******************************************************************************************************
	ostream& front_print(ostream&) const;

	//*******************************************************************************************************
	//back_print. This function accepts an ostream reference which will be responsible of printing the		*
	//list in a backwards order.																			*
	//*******************************************************************************************************
	ostream& back_print(ostream&) const;

	//Default deconstructor.
	~StringDLinkedList();
};

#endif
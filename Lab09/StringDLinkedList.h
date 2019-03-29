#ifndef STRINGD_H_
#define STRINGD_H_
#include <sstream>
using std::ostream;
class StringDLinkedList
{
public:
	//Default constructor.
	StringDLinkedList();

	//*******************************************************************************************************
	//front function. This function will return a constant reference to the first value in the list.		*
	//*******************************************************************************************************
	const StringDLinkedList& front() const;

	//*******************************************************************************************************
	//back function. This function will return a constant reference to the last value in the list.			*
	//*******************************************************************************************************
	const StringDLinkedList& back() const;

	//*******************************************************************************************************
	//push_front function. This function will add a new value to the beginning of the list.					*
	//*******************************************************************************************************
	void push_front(int);

	//*******************************************************************************************************
	//push_back function. This function will add a new value to the end of the list.						*
	//*******************************************************************************************************
	void push_back(int);

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
	void remove_inst(int);

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
#ifndef EXCEPTIONS_H_
#define EXEPTIONS_H_
#include <exception>
using std::exception;

//***************************************************************************************
//This exeption will be thrown if the user tryes to delete a node of an empty list.		*
//***************************************************************************************
class EmptyList : public exception {
public:
	EmptyList(const char* message) : exception(message) { };
};

#endif


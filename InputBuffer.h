#ifndef INPUTBUFFER_H_
#define INPUTBUFFER_H_
#include "Node.h"

class InputBuffer
{
	private :
		Node *start;
		Node *end;
		size_t size;
	public :
		InputBuffer(Node *start = NULL, Node *end = NULL, size_t size = 0);
		~InputBuffer(void);
		bool addBuffer(char buffer);
		char readBuffer(void);
		bool printBuffer(void);
		size_t bufferSize(void);
};

#endif
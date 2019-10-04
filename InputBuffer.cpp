#include "InputBuffer.h"

InputBuffer::InputBuffer(Node *start, Node *end, size_t size) : size(size)
{
	this->start = new Node;
	if (this->start == NULL)
	{
		return;
	}
	this->end = new Node;
	if (this->end == NULL)
	{
		delete this->start;
		this->start = NULL;
		return;
	}
	this->start->head = this->start;
	this->start->tail = this->end;
	this->end->head = this->start;
	this->end->tail = this->end;
	return;
}

InputBuffer::~InputBuffer(void)
{
	Node *np = this->start->tail;
	for (int i = 0; i < size; ++i)
	{
		np = np->tail;
		delete np->head;
	}
	delete this->start;
	delete this->end;
	this->start = NULL;
	this->end = NULL;
	this->size = 0;
}

bool InputBuffer::addBuffer(char buffer)
{
	Node *np = new Node;
	if (np == NULL)
	{
		return false;
	}
	np->buffer = buffer;
	np->head = this->end->head;
	this->end->head->tail = np;
	np->tail = this->end;
	this->end->head = np;
	++this->size;
	return true;
}

char InputBuffer::readBuffer(void)
{
	char buffer = 0;
	buffer = this->start->tail->buffer;
	this->start->tail = this->start->tail->tail;
	delete this->start->tail->head;
	this->start->tail->head = this->start;
	--this->size;
	return buffer;
}

bool InputBuffer::printBuffer(void)
{
	Node *np = this->start->tail;

	for (int i = 0; i < size; ++i)
	{
		if (np->buffer == '\0')
		{
			return false;
		}
		else if (np->buffer != '\n')
		{
			printf("\'%c\' ", np->buffer);
		}
		else
		{
			printf("\'\\n\' ");
		}
		np = np->tail;
	}

	return true;
}

size_t InputBuffer::bufferSize(void)
{
	return this->size;
}
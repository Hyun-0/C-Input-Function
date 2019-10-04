#ifndef NODE_H_
#define NODE_H_
#include <iostream>

struct Node
{
	Node *head;
	Node *tail;
	char buffer;
	Node(Node *head = NULL, Node *tail = NULL, char buffer = 0)
		: head(head), tail(tail), buffer(buffer) {};
};

#endif
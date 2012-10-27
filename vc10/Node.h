#pragma once
#include "Starbucks.h";

class Node
{
public:
	Node(Entry* c);
	~Node(void);
	static bool addNode(Node* paren, Node* n, bool isX);

	Node* left;
	Node* right;
	Entry* c;
};


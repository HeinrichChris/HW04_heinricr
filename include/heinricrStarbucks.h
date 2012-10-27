#pragma once
#include "Starbucks.h"
#include "Node.h"

class heinricrStarbucks: public Starbucks
{
public:
	heinricrStarbucks(void);
	~heinricrStarbucks(void);
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	Entry* getNearest(double x, double y, bool isX, Node* n);

	int size;
	Node* root;
	vector<Entry> starbucks;
};

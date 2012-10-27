#pragma once
#include "Starbucks.h"
#include "Node.h"

class heinricrStarbucks: public Starbucks
{
public:
	heinricrStarbucks(double x, double y);
	~heinricrStarbucks(void);
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	Entry* getNearest(double x, double y, bool isX, Node* n);

	int size;
	Node* root;
	vector<Entry> starbucks;
};

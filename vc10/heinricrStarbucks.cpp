#include "heinricrStarbucks.h"
#include "Starbucks.h"
#include "Node.h"
#include <fstream>;
#include <vector>;
#include <iostream>;


heinricrStarbucks::heinricrStarbucks(void)
{
	ifstream in("Starbucks_2006.csv");
	int index = 0;

	starbucks.resize(2);

	while(!in.eof()){
		if(starbucks.size() == index){
			starbucks.resize(starbucks.size()*2);
		}

		Entry* e = new Entry();
		getline(in, e->identifier, ',');
		in.get();
		in>>e->x;
		in.get();
		in>>e->y;

		starbucks[index] = e;

		index++;
	}

	size = index;

	build(starbucks[0], size);
}


heinricrStarbucks::~heinricrStarbucks(void)
{
}

void heinricrStarbucks::build(Entry* c, int n){
	int random = rand() % n;
	this->root = new Node(starbucks[random]);
	bool isX = true;
	bool change;

	for(int i = 0; i<n; i++){
		if(i != random){
			Node* n = new Node(starbucks[i]);
			change = Node::addNode(root, n, isX);
			if(change)
				isX = !isX;
		}
	}
}

Entry* heinricrStarbucks::getNearest(double x, double y){
	return getNearest(x,y,true, root);
}

Entry* heinricrStarbucks::getNearest(double x, double y, bool isX, Node* n){
	bool isRight = false;

	if(isX){
		if(x > n->c->x){
			isRight = true;
		}
		else if(abs(x - n->c->x) <= 0.00001){
			if(y > n->c->y){
				isRight = true;
			}
		}
		else if(abs(y - n->c->y) <= 0.00001){
			return n->c;
		}
	}
	else{
		if(y > n->c->y){
			isRight = true;
		}
		else if(abs(y - n->c->y) <= 0.00001){
			if(x > n->c->x){
				isRight = true;
			}
		}
		else if(abs(x - n->c->x) <= 0.00001){
			return n->c;
		}
	}

	if(isRight){
		if(n->right == NULL){
			return n->c;
		}
		else{
			return getNearest(x,y,!isX, n->right);
		}
	}
	else{
		if(n->left == NULL){
			return n->c;
		}
		else{
			return getNearest(x,y,!isX, n->left);
		}
	}
}
#include "Node.h"


Node::Node(Entry* c)
{
	this->c = c;
	this->left = NULL;
	this->right = NULL;
}


Node::~Node(void)
{
}

bool Node::addNode(Node* paren, Node* n, bool isX){
	bool isRight = false;
	bool changed = false;
	if(isX){
		if(paren->c->x < n->c->x){
			isRight = true;
			changed = true;
		}
		else if(abs(paren->c->x - n->c->x) <= 0.00001){
			if(paren->c->y < n->c->y){
				isRight = true;
				changed = true;
			}
			else if(abs(paren->c->y - n->c->y) <= 0.00001){
				return false;
			}
		}
	}
	else{
		if(paren->c->y < n->c->y){
			isRight = true;
			changed = true;
		}
		else if(abs(paren->c->y - n->c->y) <= 0.00001){
			if(paren->c->x < n->c->x){
				isRight = true;
				changed = true;
			}
			else if(abs(paren->c->x - n->c->x) <= 0.00001){
				return false;
			}
		}
	}
	if(isRight){
		if(paren->right == NULL){
			paren->right = n;
		}
		else{
			addNode(paren->right, n, isX);
		}
	}
	else{
		if(paren->left == NULL){
			paren->left = n;
		}
		else{
			addNode(paren->left, n, isX);
		}
	}
	return changed;
}
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *create_node(DATA d)
{
	node *n = (node *) malloc(sizeof(node));
	n->data = d;
	n->next = NULL;
	return n;
}

void remove_node(node *n)
{
	if(n->next == NULL){
		free(n);
	}
}
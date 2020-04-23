#ifndef NODE_H
#define NODE_H

#include <stdio.h>

typedef int DATA;

typedef struct _node node;

struct _node
{
	DATA data;
	node *next;
};

node *create_node(DATA d);
void remove_node(node *n);
#endif
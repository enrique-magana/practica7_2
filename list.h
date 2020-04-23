#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <stdbool.h>

typedef struct _list{
	node *head;
	node *tail;
	int num;
} list;

list *create_list();
void remove_list(list *l);
void add_head(list *l, DATA dato);
void add_tail(list *l,DATA dato);
void add_pos(list *l,int pos,DATA dato);
void remove_head(list *l);
void remove_tail(list *l);
void remove_pos(list *l, int pos);
void mostrar_head(list *l);
void mostrar_tail(list *l);
void mostrar_pos(list *l,int pos);
void buscar_dato(list *l, DATA dato);
void print_list(list *l);
void empty(list *l);
bool is_empty(list *l);
void cuantos(list *l);
#endif

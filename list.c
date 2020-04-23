#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include"node.h"

list *create_list()
{
	list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;
	l->num = 0;
	printf("Lista creada\n");
	printf("Pulse enter para continuar");
	getchar();
	getchar();
	return l;
}

void remove_list(list *l)
{
	if(!is_empty(l)) empty(l);
	free(l);
	l = NULL;
	printf("Lista eliminada\n");
	printf("Pulse enter para continuar");
	getchar();
	getchar();
}
void empty(list *l){
	if(is_empty(l)){
		printf("La lista está vacía\n");
		printf("Pulse enter para continuar");
        getchar();
	    getchar();
	    return;
	}
	while(!is_empty(l))
	{
		remove_head(l);
	}

	l->head = l->tail =NULL;
	l->num=0;
	printf("Lista vaciada\n");
	printf("Pulse enter para continuar");
	getchar();
	getchar();
	return;
}

bool is_empty(list *l){
	if(l->head == NULL) return true;
	return false;
}

void remove_head(list *l){
	if(is_empty(l)){
		printf("La lista está vacía\n");
		return;
	    }
	if(l->head==l->tail){
		remove_node(l->head);
		l->head=l->tail=NULL;
		return;
	}	
	node *t = l->head;
	l->head = l->head->next;
	l->tail->next=l->head;
	free(t);
	l->num--;
	return;
 }
	

void remove_tail(list *l){
	if(is_empty(l)){
		printf("La lista está vaciía\n");
		printf("Pulse enter para continuar");
    	getchar();
	    getchar();
        return;
	}
	if(l->head==l->tail){
		remove_node(l->head);
		l->head=l->tail=NULL;
		l->num--;
		printf("Elemento eliminado\n");
    	printf("Pulse enter para continuar");
 		getchar();
	    getchar();
		return;
	}
	node *t;
	for(t=l->head; t->next!= l->tail; t = t->next);
	free(l->tail);
	l->tail = t;
	l->tail->next=l->head;
	l->num--;
	printf("Elemento eliminado\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
}

void remove_pos(list *l,int pos){
	if(is_empty(l)){
		printf("La lista está vaciía\n");
		printf("Pulse enter para continuar");
    	getchar();
	    getchar();
        return;
	}
	if(pos==1){
	  remove_head(l);
	  return;
	}
	if(pos==l->num){
		remove_tail(l);
		return;
    }
	if(pos>l->num||pos<0){
	   printf("Posición inválida\n");
       printf("Pulse enter para continuar");
	   getchar();
	   getchar();
       return;

	}
	node *t1=l->head;
	node *t2=l->head;
	for(int i=1;i<pos-1;i++,t1=t1->next);
	t2=t1->next;
	t1->next=t2->next;
	free(t2);
	l->num--;
    printf("Elemento eliminado\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
    return;
}	

void add_head(list *l,DATA dato){
	if(is_empty(l)){
		node *n=create_node(dato);
		l->head=n;
		l->tail=l->head;
		l->num++;
		printf("Se agregó el nuevo elemento\n");
		printf("Pulse enter para continuar");
    	getchar();
	    getchar();
		return;
	}
	node *n=create_node(dato);
	n->next=l->head;
	l->head=n;
    l->tail->next=l->head;
	l->num++;
	printf("Se agregó el nuevo elemento\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
    return;
}

void add_tail(list *l,DATA dato){
	if (is_empty(l)){
		node *n=create_node(dato);
		l->head=l->tail=n;
		l->num++;
		printf("Se agregó el nuevo elemento\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
	node *n=create_node(dato);
	l->tail->next=n;
	l->tail=n;
	l->tail->next=l->head;
	l->num++;
	printf("Se agregó el nuevo elemento\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
    return;
}

void add_pos(list *l,int pos, DATA dato){
	if(is_empty(l)|| pos==1){
		add_head(l,dato);
		return;
	}
	if(pos==l->num){
		add_tail(l,dato);
		return;
	}
	if(pos>l->num||pos<1){
	   printf("Posición inválida\n");
       printf("Pulse enter para continuar");
	   getchar();
	   getchar();
	   return;
	} 
	node *t=l->head;
	for(int i=1;i<pos-1;i++,t=t->next);
	node *n=create_node(dato);
	n->next=t->next;
	t->next=n;
	l->num++;
	printf("Se agregó el nuevo elemento\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
    return;
}

void mostrar_head(list *l){
	if(is_empty(l)){
		printf("Lista vacía\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
	printf("El primer elmento es: %d\n",l->head->data);
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
}

void mostrar_tail(list *l){

	if(is_empty(l)){
		printf("Lista vacía\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
	printf("El último elmento es: %d\n",l->tail->data);
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
	
}

void mostrar_pos(list *l, int pos){

	if(is_empty(l)){
		printf("Lista vacía\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
    if(pos==1){
		mostrar_head(l);
		return;
	}
	if(pos==l->num){
		mostrar_tail(l);
		return;
	}
	if(pos>l->num||pos<1){
	   printf("Posición inválida\n");
       printf("Pulse enter para continuar");
       getchar();
	   getchar();
	   return;
	}
	node *t=l->head;
	for(int i=1;i<pos;i++,t=t->next);
	printf("El elemento en la posición %d es: %d\n",pos,t->data);
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
}

void buscar_dato(list *l, int dato){
	if(is_empty(l)){
		printf("Lista vacía\n");
		getchar();
	    getchar();
     	printf("Pulse enter para continuar");
		return;
		}
	
    node *t=l->head;
	int i;
	for(i=1;i<=l->num && t->data!=dato;i++,t=t->next);
	if(i>l->num){
		printf("El valor no se encuengtra en la lista\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
	printf("El valor %d se encuentra en la posición %d\n",dato,i); 
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
}
 
 void print_list(list *l){

	 if(is_empty(l)){
		printf("La lista está vacía\n");
    	printf("Pulse enter para continuar");
		getchar();
	    getchar();
		return;
	}
	node *t;
	printf("[ ");
    for(t = l->head;t->next != l->head; t = t->next )
             printf("%d ",t->data); 
    printf("%d ",t->data);			 
	printf("]\n");
	printf("Pulse enter para continuar");
	getchar();
    getchar();
	return;
}
 
void cuantos(list *l){
	if(l->head==NULL){
	   printf("La lista está vacía\n");
       printf("Pulse enter para continuar");
       getchar();
	   getchar();
	   return;
	}
	printf("La lista tiene %d elementos\n",l->num);
	printf("Pulse enter para continuar");
	getchar();
	getchar();
	return;
}


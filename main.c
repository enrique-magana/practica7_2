#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include"node.h"

int main(){
    short op, pos;
    int dato;
    list *l;
    do{
		system("clear");
		printf("Elija la opción:\n");
		printf("1.-Crear lista\n");
		printf("2.-Vaciar lista.\n");
		printf("3.-Eliminar lista.\n");
        printf("4.-Agregar al inicio de la lista.\n");
        printf("5.-Agregar al final de la lista.\n");
        printf("6.-Agregar en una posición específica\n");
        printf("7.-Eliminar al inicio de la lista.\n");
        printf("8.-Eliminar al final de lista.\n");
        printf("9.-Eliminar una posición específica de la lista.\n");
        printf("10.-Mostrar el primer elemento de la lista.\n");
        printf("11.-Mostrar el último elemento de la lista .\n");
        printf("12.-Mostrar el elemento de una posición específica de la lista.\n");
        printf("13.Buscar la posición de un dato\n");
        printf("14.-Mostrar lista.\n");
        printf("15.-Saber cuantos elementos tiene la lista.\n");
        printf("16.-Salir.\n");
        scanf("%hd",&op);
		switch (op)
		{
		case 1:
		    l=create_list();
			break;
		case 2:
		    empty(l);
			break;
		
		case 3:
		    remove_list(l);
            break;
		case 4:
            printf("Ingrese el dato:\n");
            scanf(" %d", &dato);
            add_head(l,dato);
            break;
        case 5:
            printf("Ingrese el dato:\n");
            scanf(" %d", &dato);
            add_tail(l,dato);
            break;
        case 6:
            printf("Ingrese el dato:\n");
            scanf(" %d", &dato);
            printf("Ingrese la posición donde desea agregar el dato\n");
            scanf(" %hd", &pos);
            add_pos(l,pos,dato);
            break;
        case 7:
            remove_head(l);
            printf("Elemento eliminado\n");
            printf("Pulse enter para continuar\n");
            getchar();
            getchar();
            break;
        case 8:
            remove_tail(l);
            break;        
        case 9:
            printf("Ingrese la posición que desee eliminar\n");
            scanf(" %hd", &pos);
            remove_pos(l,pos);
		    printf("Opción inválida.\n");
			break;
        case 10:
            mostrar_head(l);
            break;
        case 11:
            mostrar_tail(l);
            break;
        case 12:
            printf("Ingrese la posición que desee mostrar\n");
            scanf(" %hd", &pos);
            mostrar_pos(l,pos);
            break;
        case 13:
            printf("Ingrese el dato que desee buscar\n");
            scanf(" %d",&dato);
            buscar_dato(l,dato);
            break;
        case 14:
            print_list(l);
            break;
        case 15:
            cuantos(l);
            break;
        case 16:
            printf("Saliendo.\n");
			break;
		default:
		    printf("Opción inválida.\n");
			getchar();
			getchar();
			break;        
                                    
		}
	}
	while(op!=16);
	return 0;
}
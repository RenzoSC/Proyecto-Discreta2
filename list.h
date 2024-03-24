#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>
#include "vertice.h"

typedef struct list_st * list;

typedef unsigned int u32;
typedef u32 color;

/*CONSTRUCTORES: */

list empty();

list add_elemnt(vertice elem, list lista);

/*Agrega un elemento a la izquierda de la lista*/

/*OPERACIONES: */

list pop_element(list lista);

u32 list_len(list lista);

bool is_empty(list lista);

vertice list_index(list lista, u32 index);

vertice list_tail(list lista);

list list_delete_index(list lista, u32 index);

/*DESTROY: */

list destroy(list l);
#endif
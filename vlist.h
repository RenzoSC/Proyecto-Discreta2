#ifndef _VLIST_H
#define _VLIST_H
#include <stdbool.h>
#include "vertice.h"

typedef struct list_st * list;

typedef unsigned int u32;
typedef u32 color;

/*CONSTRUCTORES: */

list empty();

list add_elemnt(u32 id_elem, list lista);

/*Agrega un elemento a la izquierda de la lista*/

/*OPERACIONES: */

list pop_element(list lista);

u32 list_len(list lista);

bool is_empty(list lista);

u32 list_index(list lista, u32 index);

u32 list_tail(list lista);

u32 list_head(list lista);
/*DESTROY: */

list destroy(list l);
#endif
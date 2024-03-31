#ifndef _VERTICE_H
#define _VERTICE_H

#include "vlist.h"

typedef unsigned int color;
typedef unsigned int u32;

struct vertice_st{
    u32 id;
    color col;
    struct list_st * vecinos;
};

typedef struct vertice_st * vertice;


/*CONSTRUCTORES*/
vertice create_vertice(u32 id);

/*OPERACIONES: getters*/
u32 get_vertice_id(vertice v);

u32 get_grado_vertice(vertice v);

u32 get_color_vertice(vertice v);

u32 get_first_vecino(vertice v);

u32 get_last_vecino(vertice v);

u32 get_vecino_index(vertice v, u32 index);

/*OPERACIONES: setters*/

void set_color(vertice v, color colorv);

void add_grado(vertice v);

void add_vecino(vertice v, u32 vec);

void pop_vecino(vertice v);

/*DESTRUCTOR*/
vertice destroy_vertice(vertice v);

#endif
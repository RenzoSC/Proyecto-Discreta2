#ifndef _VERTICE_H
#define _VERTICE_H

typedef unsigned int color;
typedef unsigned int u32;

struct vertice_st{
    u32 id;
    color col;
    u32 *vecinos_id;
    u32 grado;
    u32 maxlen;
};

typedef struct vertice_st * vertice;


/*CONSTRUCTORES*/
vertice create_vertice(u32 id);

vertice add_vecino(vertice v, u32 vecino);

/*OPERACIONES: getters*/
u32 get_vertice_id(vertice v);

u32 get_vecino_by_index(vertice v, u32 index);

u32 get_grado_vertice(vertice v);

u32 get_color_vertice(vertice v);

/*OPERACIONES: setters*/
vertice change_vecino_by_index(vertice v, u32 index, u32 new_vecino);

vertice set_color(vertice v, color colorv);

vertice pop_vecino(vertice v);

/*DESTRUCTOR*/
vertice destroy_vertice(vertice v);

#endif
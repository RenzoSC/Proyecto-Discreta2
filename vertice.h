#ifndef _VERTICE_H
#define _VERTICE_H

typedef unsigned int color;
typedef unsigned int u32;

struct vertice_st{
    u32 id;
    color col;
    u32 grado;
};

typedef struct vertice_st * vertice;


/*CONSTRUCTORES*/
vertice create_vertice(u32 id);

/*OPERACIONES: getters*/
u32 get_vertice_id(vertice v);

u32 get_grado_vertice(vertice v);

u32 get_color_vertice(vertice v);

/*OPERACIONES: setters*/

vertice set_color(vertice v, color colorv);

vertice set_grado(vertice v, u32 new_grado);

/*DESTRUCTOR*/
vertice destroy_vertice(vertice v);

#endif
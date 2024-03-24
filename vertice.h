#ifndef _VERTICE_H
#define _VERTICE_H

typedef unsigned int color;
typedef unsigned int u32;

struct vertice_st{
    color col;
    struct list_st  *vecinos;
};

typedef struct vertice_st * vertice;

vertice create_vertice();

vertice destroy_vertice(vertice v);

u32 grado_verdice(vertice v);

u32 color_vertice(vertice v);



#endif
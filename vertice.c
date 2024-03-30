#include <stdlib.h>
#include <assert.h>

#include "vertice.h"

vertice create_vertice(u32 id){
    vertice v = malloc(sizeof(struct vertice_st));
    v->col = 0;
    v->id = id;
    v->grado = 0;
    assert(v!=NULL);
    return v;
}

u32 get_vertice_id(vertice v){
    assert(v!=NULL);
    return v->id;
}

u32 get_grado_vertice(vertice v){
    assert(v!=NULL);
    return v->grado;
}

u32 get_color_vertice(vertice v){
    assert(v!=NULL);
    return v->col;
}

void set_color(vertice v, color colorv){
    assert(v!=NULL);
    v->col = colorv;
}


void add_grado(vertice v){
    assert(v!=NULL);
    v->grado ++;
}


vertice destroy_vertice(vertice v){
    assert(v!=NULL);
    v->col=0;
    v->grado=0;
    v->id=0;
    free(v);
    v=NULL;
    assert(v==NULL);
    return v;
}

#include <stdlib.h>
#include <assert.h>

#include "vertice.h"
#include "list.h"

vertice create_vertice(u32 id){
    vertice v = malloc(sizeof(vertice));
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

vertice set_color(vertice v, color colorv){
    assert(v!=NULL);
    v->col = colorv;
    return v;
}


vertice set_grado(vertice v, u32 new_grado){
    assert(v!=NULL);
    v->grado = new_grado;
    return v;
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

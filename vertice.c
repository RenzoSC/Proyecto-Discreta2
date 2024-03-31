#include <stdlib.h>
#include <assert.h>

#include "vlist.h"
#include "vertice.h"

vertice create_vertice(u32 id){
    vertice v = malloc(sizeof(struct vertice_st));
    v->vecinos = empty();
    v->col = 0;
    v->id = id;
    assert(v!=NULL);
    return v;
}

u32 get_vertice_id(vertice v){
    assert(v!=NULL);
    return v->id;
}

u32 get_grado_vertice(vertice v){
    assert(v!=NULL);
    return list_len(v->vecinos);
}

u32 get_color_vertice(vertice v){
    assert(v!=NULL);
    return v->col;
}

u32 get_first_vecino(vertice v){
    assert(v!=NULL);
    return list_head(v->vecinos);
}

u32 get_last_vecino(vertice v){
    assert(v!=NULL);
    return list_tail(v->vecinos);
}

u32 get_vecino_index(vertice v, u32 index){
    assert(v!=NULL);
    return list_index(v->vecinos, index);
}

void set_color(vertice v, color colorv){
    assert(v!=NULL);
    v->col = colorv;
}


void add_vecino(vertice v, u32 vec){
    assert(v!=NULL);
    v->vecinos = add_elemnt(vec, v->vecinos);
}

void pop_vecino(vertice v){
    assert(v!=NULL);
    assert(is_empty(v->vecinos));
    v->vecinos = pop_element(v->vecinos);
}

vertice destroy_vertice(vertice v){
    assert(v!=NULL);
    v->col=0;
    v->id=0;
    v->vecinos= destroy(v->vecinos);
    free(v);
    v=NULL;
    assert(v==NULL);
    return v;
}

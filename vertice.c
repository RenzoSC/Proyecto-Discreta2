#include <stdlib.h>
#include <assert.h>

#include "vertice.h"
#include "list.h"

vertice create_vertice(u32 id){
    vertice v = malloc(sizeof(vertice));
    v->col = 0;
    v->id = id;
    v->vecinos_id =NULL;
    v->grado = 0;
    v->maxlen = 0;
    assert(v!=NULL);
    return v;
}


vertice add_vecino(vertice v, u32 vecino){
    assert(v!=NULL);
    assert(v->maxlen>=v->grado);

    if (v->grado == v->maxlen )
    {
        u32 new_maxlen = v->maxlen == 0 ? 1:v->grado*2;
        v->vecinos_id = realloc(v->vecinos_id, new_maxlen*sizeof(u32));
        v->maxlen = new_maxlen;
    }
    (v->vecinos_id)[v->grado] = vecino;
    v->grado ++;
    return v;
}


u32 get_vertice_id(vertice v){
    assert(v!=NULL);
    return v->id;
}

u32 get_vecino_by_index(vertice v, u32 index){
    assert(v!=NULL);
    assert(index<=v->grado);
    return (v->vecinos_id)[index];
}

u32 get_grado_vertice(vertice v){
    assert(v!=NULL);
    return v->grado;
}

u32 get_color_vertice(vertice v){
    assert(v!=NULL);
    return v->col;
}

vertice change_vecino_by_index(vertice v, u32 index, u32 new_vecino){
    assert(v!=NULL);
    assert(index<=v->grado);
    (v->vecinos_id)[index]= new_vecino;
    return v;
}

vertice set_color(vertice v, color colorv){
    assert(v!=NULL);
    v->col = colorv;
    return v;
}

vertice pop_vecino(vertice v){
    assert(v!=NULL);
    assert(v->grado>=1 && v->vecinos_id!=NULL);
    v->grado--;
    return v;
}

vertice destroy_vertice(vertice v){
    assert(v!=NULL);
    free(v->vecinos_id);
    v->vecinos_id = NULL;
    v->col=0;
    v->grado=0;
    v->id=0;
    v->maxlen=0;
    free(v);
    v=NULL;
    assert(v==NULL);
    return v;
}

#include "list.h"

#include "vertice.h"
#include <stdlib.h>
#include <assert.h>

struct list_st{
    vertice * elems;
    u32 len;
    u32 maxlen;
};

list empty(){
    list l = malloc(sizeof(struct list_st));
    l->elems = NULL;
    l->len = 0;
    l->maxlen =0;
    assert(l!=NULL);
    return l;
}

list add_elemnt(vertice elem, list lista){
    assert(lista != NULL);
    assert(lista->maxlen>=lista->len);

    if(lista->maxlen == lista->len){
        size_t new_maxlen = lista->maxlen == 0 ? 1 : 2*lista->len;
        lista->elems = realloc(lista->elems, new_maxlen*(sizeof(vertice)));
        lista->maxlen = new_maxlen;
    }
    (lista->elems)[lista->len]= elem;
    lista->len++;
    return lista;
};

list pop_element(list lista){
    assert(lista!=NULL);
    assert(lista->len>0);
    lista->len --;   //tengo que borrar memoria de lista->elems[index] ??
    return lista;
}

u32 list_len(list lista){
    assert(lista != NULL);
    return lista->len;
}

bool is_empty(list lista){
    assert(lista!=NULL);
    return (lista->len == 0);                        
}

vertice list_index(list lista, u32 index){
    assert(lista!=NULL);
    assert(lista->len >=index);
    return lista->elems[index];
}

vertice list_tail(list lista){
    assert(lista!=NULL);
    assert(lista->len >0);
    return lista->elems[lista->len-1];
}

vertice list_head(list lista){
    assert(lista!=NULL);
    assert(lista->len>0);
    return lista->elems[0];
}

list list_delete_index(list lista, u32 index){
    assert(lista!=NULL);
    assert(index < lista->len);

    //borrar memoria de lista->elems[index] ?

    for (size_t i = index; i < lista->len-1; i++)
    {
        lista->elems[i] = lista->elems[i+1];
    }
    lista->len--;
    return lista;
}

list destroy(list lista){
    assert(lista!=NULL);
    for (size_t i = lista->len -1; i >=0; i--)
    {
        destroy_vertice((lista->elems)[i]);
    }
    free(lista->elems);
    lista->len=0;
    lista->maxlen=0;
    free(lista);
    lista =NULL;

    assert(lista==NULL);
    return lista;
}
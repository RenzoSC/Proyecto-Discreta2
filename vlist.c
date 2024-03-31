#include "vlist.h"

#include "vertice.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
struct vNode{
    u32 id_vert;
    struct vNode *next;
};

struct list_st{
    struct vNode *node;
    u32 len;
};

list empty(){
    list l = malloc(sizeof(struct list_st));
    l->node = NULL;
    l->len = 0;
    assert(l!=NULL);
    return l;
}

list add_elemnt(u32 id_elem, list lista){
    assert(lista != NULL);
    struct vNode * aux = NULL;
    aux = malloc(sizeof (struct vNode));
    aux->id_vert = id_elem;
    aux->next = NULL;
    aux->next = lista->node;
    lista->node = aux;
    lista->len++;
    return lista;
};

list pop_element(list lista){
    assert(lista!=NULL);
    assert(lista->len>0);
    struct vNode *p = NULL;
    p = lista->node;
    lista->node = (lista->node)->next;
    lista->len --;
    p->next= NULL;
    free(p);
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

u32 list_index(list lista, u32 index){
    assert(lista!=NULL);
    assert(lista->len >=index && lista->len !=0);
    struct vNode*p = NULL;
    p = lista->node;
    for (size_t i = 0; i < lista->len - index-1; i++)
    {   
        p= p->next;
        
    }
    
    return p->id_vert;
}

u32 list_tail(list lista){
    assert(lista!=NULL);
    assert(lista->len >0);
    return lista->node->id_vert;
}

u32 list_head(list lista){
    assert(lista!=NULL);
    assert(lista->len>0);
    struct vNode*p = NULL;
    p = lista->node;
    for (size_t i = 0; i < lista->len-1; i++)
    {
        p = p->next;
    }
    
    return p->id_vert;
}


list destroy(list lista){
    assert(lista!=NULL);
    struct vNode*p = NULL;
    p = lista->node;
    while (p!=NULL)
    {
        lista->node  = (lista->node)->next;
        p->next = NULL;
        free(p);
        p = lista->node;
    }
    lista->len = 0;
    free(lista);
    lista =NULL;
    assert(lista==NULL);
    return lista;
}
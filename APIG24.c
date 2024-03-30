#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "EstructuraGrafo24.h"
#include "APIG24.h"

#define MAXLINE 1024

//Construccion de grafos

Grafo construir_grafo(){
    Grafo grafo = (Grafo)malloc(sizeof(struct Grafo_St));
    if (grafo == NULL) return NULL;
    
    u32 m,n;
    //bool error = false;
    char car[MAXLINE];
    while (fgets(car, MAXLINE, stdin ))
    {
        if (car[0] == 'c') continue;

        if (car[0]== 'e')
        {   
            printf("Se obtuvo un edge antes de indicar la cantidad de vértices y lados del grafo...\nSaliendo...");
            exit(-1);
        }else if (car[0] == 'p')
        {
            int ret = sscanf(car, "p edge %u %u\n",&n,&m);
            if (ret <2)
            {
                printf("Hubo un error al leer el numero de vertices y  lados %i", ret);
                exit(-1);
            }
            
            grafo->num_vertices = n;
            grafo->num_lados = m;
            grafo->list_vertice = malloc(sizeof(vertice)*n);
            grafo->list_vecinos = malloc(sizeof(u32)*m*2);
            break;
        }
    }
    bool* is_already = malloc(sizeof(bool)*grafo->num_vertices);
    for (size_t i = 0; i < grafo->num_vertices; i++)
    {
        is_already[i]= false;     //acordar de destruir el array
    }
    
    for (size_t i = 0; i < grafo->num_lados; i++)
    {
        char *is_eof = fgets(car, MAXLINE, stdin);
        if (is_eof==NULL && i < grafo->num_lados-1)
        {
            return NULL;
        }else if (is_eof==NULL)
        {
            printf("error al leer la linea con fgets....");
            exit(-1);
        }
        
        if (car[0]=='e')
        {   
            u32 vert1,vert2;
            int r = sscanf(car,"e %u %u", &vert1,&vert2);
            if (r<2)
            {
                printf("No se pasaron 2 vertices como correspondería: %i\n",r);
                exit(-1);
            }

            if (is_already[vert1]==false)
            {
                vertice vertice1= create_vertice(vert1);
                grafo->list_vertice[vert1]= vertice1;
                is_already[vert1]=true;
            }
            
            if (is_already[vert2]==false)
            {
                vertice vertice2= create_vertice(vert2);
                grafo->list_vertice[vert2]= vertice2;
                is_already[vert2]= true;
            }
            
            add_grado(grafo->list_vertice[vert1]);
            add_grado(grafo->list_vertice[vert2]);
            grafo->list_vecinos[vert1]= vert2;
            grafo->list_vecinos[vert2]= vert1;
            //printf("Agregué al vertice %i y al %i\n", vert2,vert1);
            vertice v1 = grafo->list_vertice[vert1];
            vertice v2 = grafo->list_vertice[vert2];
            if (grafo->delta < v1->grado || grafo->delta < v2->grado)
            {
                grafo->delta = v1->grado <= v2->grado ? v2->grado : v1->grado;
            }
            
        }else{
            printf("Mal formato de el paso del edge");
        }        
    }
    free(is_already);
    return grafo;
}

void destruir_grafo(Grafo G){
    assert(G!=NULL);
    for (size_t i = 0; i < G->num_vertices; i++)
    {
        destroy_vertice(G->list_vertice[i]);
    }
    free(G->list_vertice);
    free(G->list_vecinos);
    free(G);
    G = NULL;
    assert(G==NULL);
}

// Extraer información del grafo

u32 NumeroDeVertices(Grafo G){
    assert(G != NULL);
    return G->num_vertices;
}

u32 NumeroDeLados(Grafo G){
    assert(G != NULL);
    return G->num_lados;
}

u32 Delta(Grafo G){
    assert(G != NULL);
    return G->delta;
}

// Extraer informacion de los vertices

u32 grado_v(u32 i, Grafo G){
    assert(G!=NULL);
    if (i >= G->num_vertices){
        return 0;
    }else{
        return G->list_vertice[i]->grado;
    }
}

u32 color_v(u32 i, Grafo G){
    assert(G!=NULL);
    if (i >= G->num_vertices){
        return UINT32_MAX;
    }else{
        return G->list_vertice[i]->col;
    }
}

u32 vecino_v(u32 j, u32 i, Grafo G){
    assert(G!=NULL);
    if ((i>=NumeroDeVertices(G)) || (i<=NumeroDeVertices(G) && j>=grado_v(i,G)) || j >= grado_v(i,G))
    {
        return UINT32_MAX;
    }
    return G->list_vecinos[i + j];
}

// Asignar colores

void asignar_color_v(color c, u32 i, Grafo G){
    assert(G!=NULL);
    if (i<NumeroDeVertices(G))
    {
        set_color(G->list_vertice[i], c);
    }
}

void extraer_color_v(Grafo G, color* col){
    assert(G!=NULL);
    for (u32 i = 0; i < G->num_vertices; i++) {
        col[i] = G->list_vertice[i]->col;
    }
}

void importar_colores(color* col,Grafo G){
    assert(G!=NULL);
    for (u32 i = 0; i < G->num_vertices; i++) {
        G->list_vertice[i]->col = col[i];
    }
}

#include "APIG24.h"
#include "EstructuraGrafo24.h"

#include <stdlib.h>
#include <assert.h>


//extraer información del grafo

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
    if (i >= G->num_vertices){
        return 0;
    }else{
        return G->list_vertice[i]->grado;
    }
}

u32 color_v(u32 i, Grafo G){
    if (i >= G->num_vertices){
        return UINT32_MAX;
    }else{
        return G->list_vertice[i]->col;
    }
}

u32 vecino_v(u32 j, u32 i, Grafo G){
    if ((i>=NumeroDeVertices(G)) || (i<=NumeroDeVertices(G) && j>=grado_v(i,G)))
    {
        return UINT32_MAX;
    }
    
}

// Asignar colores

void asignar_color_v(color* c, u32 i, Grafo G){
    if (i<NumeroDeVertices(G))
    {
        G->list_vertice[i]->col = c;
    }
}

void extraer_color_v(Grafo G, color* col){
    for (u32 i = 0; i < G->num_vertices; i++) {
        // Asignamos el color del vértice i al arreglo Color
        col[i] = G->list_vertice[i]->col;
    }
}

void importar_colores(color* col,Grafo G){
    // Iteramos sobre cada vértice del grafo
    for (u32 i = 0; i < G->num_vertices; i++) {
        // Asignamos el color del vértice i al color almacenado en el arreglo Color
        G->list_vertice[i]->col = col[i];
    }
}
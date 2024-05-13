#include "APIG24.h"
#include "vertice.h"
#include <stdio.h>
int main()
{
    Grafo g= construir_grafo();

    for(unsigned int i=0u; i < NumeroDeVertices(g); i++){
        printf("Vertice:%u\n", g->list_vertice[i]->id);
        printf("Color:%u\n", color_v(i,g));
        printf("Grado:%u\n",grado_v(i,g));
    }

    printf("numero de lados: %u\n", NumeroDeLados(g));

    printf("numero de vertices: %u\n", NumeroDeVertices(g));

    printf("Delta: %u\n", Delta(g));

    printf("El vertice 6 es vecino de %u\n", vecino_v(0,6,g));
    printf("El vertice 6 es vecino de %u\n", vecino_v(1,6,g));
    printf("El vertice 6 es vecino de %u\n", vecino_v(2,6,g));
    
    color * col = malloc(sizeof(color)*g->num_vertices);
    extraer_color_v(g, col);
    for (size_t i = 0; i < g->num_vertices; i++)
    {
        printf("color: %u\n", col[i]);
        col[i] = i;
    }

    importar_colores(col,g);
    for (size_t i = 0; i < g->num_vertices; i++)
    {
        printf("color: %u\n", g->list_vertice[i]->col);
    }
    free(col);
    destruir_grafo(g);
    return 0;
}

/*
Funciones a testear:
Grafo construir_grafo(); funca

void destruir_grafo(Grafo G); funca

//extraer información del grafo

u32 NumeroDeVertices(Grafo G); funca

u32 NumeroDeLados(Grafo G); funca

u32 Delta(Grafo G);     funca

// Extraer informacion de los vertices

u32 grado_v(u32 i, Grafo g);    funca

u32 color_v(color i, Grafo g);  funca

u32 vecino_v(u32 j, u32 i, Grafo g);  funca

// Asignar colores

void asignar_color_v(color c, u32 i, Grafo g); funca

void extraer_color_v(Grafo g, color* col);  funca funca

void importar_colores(color* c,Grafo g);  funca 
*/
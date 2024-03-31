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

    printf("El vertice 1 es vecino de %u\n", vecino_v(3,1,g));
    printf("El vertice 1 es vecino de %u\n", vecino_v(2,1,g));
    printf("El vertice 1 es vecino de %u\n", vecino_v(4,1,g));
    printf("El vertice 1 es vecino de %u\n", vecino_v(0,1,g));
    
    destruir_grafo(g);
    return 0;
}

/*
Funciones a testear:
Grafo construir_grafo();
Grafo construir_grafo();

void destruir_grafo(Grafo G);

//extraer información del grafo

u32 NumeroDeVertices(Grafo G);

u32 NumeroDeLados(Grafo G);

u32 Delta(Grafo G);

// Extraer informacion de los vertices

u32 grado_v(u32 i, Grafo g);

u32 color_v(color i, Grafo g);

u32 vecino_v(u32 j, u32 i, Grafo g);

// Asignar colores

void asignar_color_v(color c, u32 i, Grafo g);

void extraer_color_v(Grafo g, color* col);

void importar_colores(color* c,Grafo g);
*/
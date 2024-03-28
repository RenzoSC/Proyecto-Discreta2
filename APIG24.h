#ifndef _APIG24_h
#define _APIG24_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "EstructuraGrafo24.h"

typedef struct Grafo_St *Grafo;

typedef unsigned int color;

typedef unsigned int u32;

Grafo construir_grafo();

void destruir_grafo(Grafo G);

//extraer información del grafo

u32 NumeroDeVertices(Grafo G);

u32 NumeroDeLados(Grafo G);

u32 Delta(Grafo G);

// Extraer informacion de los vertices

u32 grado_v(u32 grado, Grafo g);

u32 color_v(color col, Grafo g);

u32 vecino_v(u32 j, u32 i, Grafo g);

// Asignar colores

void asignar_color_v(color* c, u32 i, Grafo g);

void extraer_color_v(Grafo g, color* col);

void importar_colores(color c,Grafo g);

#endif
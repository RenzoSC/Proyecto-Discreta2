#ifndef _APIG24_h
#define _APIG24_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "EstructuraGrafo24.h"

typedef struct GrafoST *Grafo;

typedef unsigned int color;

typedef unsigned int u32;

GrafoSt construir_grafo();

void destruir_grafo();

//extraer información del grafo

u32 NumeroDeVertices(Grafo G);

u32 NumeroDeLados(Grafo G);

u32 Delta(Grafo G);

// Extraer informacion de los vertices

u32 grado_v(u32 grado, GrafoSt g);

u32 color_v(color col, GrafoSt g);

u32 vecino_v(u32 j, u32 i, GrafoSt g);

// Asignar colores

u32 asignar_color_v(color* c, u32 i, GrafoSt g);

u32 extraer_color_v(GrafoSt g, color* col);

void importar_colores(color c,GrafoSt g);

#endif
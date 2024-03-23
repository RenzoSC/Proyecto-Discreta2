#ifndef _ESTRUCTURAGRAFO24_H
#define _ESTRUCTURAGRAFO24_H

typedef unsigned int u32;

typedef struct GrafoSt {
    int vertices;
    int lados;
    int delta;
    int vecinos[];
} GrafoSt;

#endif
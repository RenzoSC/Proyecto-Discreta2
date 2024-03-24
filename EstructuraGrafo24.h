#ifndef _ESTRUCTURAGRAFO24_H
#define _ESTRUCTURAGRAFO24_H

#include "list.h"

typedef unsigned int u32;

typedef struct GrafoSt {
    u32 vertices;
    u32 lados;
    u32 delta;
    list vecinos;
} GrafoSt;

#endif
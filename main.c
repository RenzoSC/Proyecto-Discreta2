#include "APIG24.h"
#include "vertice.h"
#include <stdio.h>
int main()
{
    Grafo g= construir_grafo();
    printf("numero de vertices: %u\n", g->num_vertices);

    printf("numero de vertices: %u\n", g->num_lados);
    return 0;
}

#include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

float calcularAreaTriangulo(Ponto p1, Ponto p2, Ponto p3) {
    return 0.5 * ((p1.x * (p2.y - p3.y)) + (p2.x * (p3.y - p1.y)) + (p3.x * (p1.y - p2.y)));
}

int main() {
    int numVertices;
    printf("Digite o numero de vertices do poligono: ");
    scanf("%d", &numVertices);

    if (numVertices < 3) {
        printf("O poligono deve ter pelo menos 3 vertices.\n");
        return 1;
    }

    Ponto vertices[numVertices];

    printf("Digite as coordenadas x e y dos vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        scanf("%f %f", &vertices[i].x, &vertices[i].y);
    }

    float area = 0.0;
    for (int i = 1; i < numVertices - 1; i++) {
        area += calcularAreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    if (area < 0) {
        area = -area;
    }

    printf("A area do poligono e aproximadamente %.2f .\n", area);

    return 0;
}

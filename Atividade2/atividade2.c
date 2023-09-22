#include <stdio.h>
#include <string.h>

void troca(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(char **arr, int baixo, int alto) {
    char *pivot = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quicksort(char **arr, int baixo, int alto, int *comparacoes, int *trocas) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        quicksort(arr, baixo, pi - 1, comparacoes, trocas);
        quicksort(arr, pi + 1, alto, comparacoes, trocas);
    }
}

int main() {
    char *arr[20] = {
        "maçã", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparacoes = 0;
    int trocas = 0;

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1, &comparacoes, &trocas);

    // Mostrar o vetor ordenado no console
    printf("Vetor Ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    // Gerar um arquivo de saída
    FILE *arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivoSaida, "%s\n", arr[i]);
    }

    fclose(arquivoSaida);

    // Indicar a mediana do conjunto de dados
    char *mediana = arr[n / 2];
    printf("\nMediana: %s\n", mediana);

    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}

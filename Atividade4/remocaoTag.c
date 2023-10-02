#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    char caractere;
    int dentroTag = 0;

    printf("Digite o nome do arquivo HTML de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saída (sem tags HTML): ");
    scanf("%s", nomeArquivoSaida);

    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    arquivoSaida = fopen(nomeArquivoSaida, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivoEntrada);
        return 1;
    }

    while ((caractere = fgetc(arquivoEntrada)) != EOF) {
        if (caractere == '<') {
            dentroTag = 1;
        } else if (caractere == '>') {
            dentroTag = 0;
        } else if (!dentroTag) {
            fputc(caractere, arquivoSaida);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("As tags HTML foram removidas com sucesso e o arquivo de saída foi gerado.\n");

    return 0;
}

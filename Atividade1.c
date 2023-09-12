#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char telefone[15];
    char curso[50];
    float notas[2];
    float media;
    char situacao[15];
} Estudante;

int main() {
    FILE *entrada_arquivo = fopen("DadosEntrada.csv", "r");
    if (entrada_arquivo == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    FILE *saida_arquivo = fopen("SituacaoFinal.csv", "w");
    if (saida_arquivo == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(entrada_arquivo);
        return 1;
    }

    char linha[256];
    Estudante estudante;

    // Ignorar a primeira linha do arquivo CSV (cabeçalho)
    fgets(linha, sizeof(linha), entrada_arquivo);

    while (fgets(linha, sizeof(linha), entrada_arquivo)) {
        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", 
                estudante.nome, estudante.telefone, estudante.curso, 
                &estudante.notas[0], &estudante.notas[1]) == 5) {
            // Processar a linha apenas se tiver os 5 campos necessários
            float soma_notas = 0;
            for (int i = 0; i < 2; i++) {
                soma_notas += estudante.notas[i];
            }
            estudante.media = soma_notas / 2;

            if (estudante.media >= 7.0) {
                strcpy(estudante.situacao, "APROVADO");
            } else {
                strcpy(estudante.situacao, "REPROVADO");
            }

            fprintf(saida_arquivo, "%s,%.2f,%s\n", estudante.nome, estudante.media, estudante.situacao);
        } else {
            printf("Linha de dados inválida: %s\n", linha);
        }
    }

    fclose(entrada_arquivo);
    fclose(saida_arquivo);

    return 0;
}

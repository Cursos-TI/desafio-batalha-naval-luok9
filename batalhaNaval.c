#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas diretamente)
    int linhaNavioH = 2; // Linha inicial do navio horizontal
    int colunaNavioH = 1; // Coluna inicial do navio horizontal

    int linhaNavioV = 5; // Linha inicial do navio vertical
    int colunaNavioV = 7; // Coluna inicial do navio vertical

    // Validação dos limites do navio horizontal
    if (colunaNavioH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Posiciona navio horizontal com valor 3
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioH][colunaNavioH + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação dos limites do navio vertical e checagem de sobreposição
    int sobreposicao = 0;
    if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("Erro: navio vertical sobrepõe outro navio.\n");
            return 1;
        }

        // Posiciona navio vertical com valor 3
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

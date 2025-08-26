#include <stdio.h>

#define TAM 10        // tamanho do tabuleiro
#define NAVIO 3       // valor que representa navio
#define AGUA 0        // valor que representa água
#define TAM_NAVIO 3   // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // matriz 10x10 para representar o tabuleiro
    int i, j;

    // 1. Inicializar tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Definir as coordenadas iniciais dos navios
    // Navio horizontal começando na posição (2, 1)
    int linhaH = 2, colunaH = 1;

    // Navio vertical começando na posição (5, 7)
    int linhaV = 5, colunaV = 7;

    // 3. Validar e posicionar o navio horizontal
    if (colunaH + TAM_NAVIO <= TAM) { 
        for (j = colunaH; j < colunaH + TAM_NAVIO; j++) {
            tabuleiro[linhaH][j] = NAVIO;
        }
    }

    // 4. Validar e posicionar o navio vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;
        for (i = linhaV; i < linhaV + TAM_NAVIO; i++) {
            if (tabuleiro[i][colunaV] == NAVIO) {
                sobreposicao = 1; // marca se tem colisão
            }
        }
        if (!sobreposicao) {
            for (i = linhaV; i < linhaV + TAM_NAVIO; i++) {
                tabuleiro[i][colunaV] = NAVIO;
            }
        } else {
            printf("Erro: O navio vertical se sobrepõe ao navio horizontal!\n");
        }
    }

    // 5. Exibir o tabuleiro
    printf("\n--- Tabuleiro Batalha Naval ---\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


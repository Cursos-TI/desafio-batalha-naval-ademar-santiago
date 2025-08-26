#include <stdio.h>

#define TAM 10        // tamanho do tabuleiro
#define NAVIO 3       // valor que representa navio
#define AGUA 0        // valor que representa água
#define TAM_NAVIO 3   // tamanho fixo dos navios

// Função para verificar se a posição está dentro dos limites
int dentro_limite(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// Função para verificar sobreposição
int sobrepoe(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == NAVIO);
}

// Posiciona navio horizontal
void posicionar_horizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAM_NAVIO <= TAM) {
        int valido = 1;
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            if (sobrepoe(tabuleiro, linha, j)) valido = 0;
        }
        if (valido) {
            for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
                tabuleiro[linha][j] = NAVIO;
            }
        }
    }
}

// Posiciona navio vertical
void posicionar_vertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO <= TAM) {
        int valido = 1;
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            if (sobrepoe(tabuleiro, i, coluna)) valido = 0;
        }
        if (valido) {
            for (int i = linha; i < linha + TAM_NAVIO; i++) {
                tabuleiro[i][coluna] = NAVIO;
            }
        }
    }
}

// Posiciona navio diagonal ↘
void posicionar_diagonal_direita(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO <= TAM && coluna + TAM_NAVIO <= TAM) {
        int valido = 1;
        for (int k = 0; k < TAM_NAVIO; k++) {
            if (sobrepoe(tabuleiro, linha + k, coluna + k)) valido = 0;
        }
        if (valido) {
            for (int k = 0; k < TAM_NAVIO; k++) {
                tabuleiro[linha + k][coluna + k] = NAVIO;
            }
        }
    }
}

// Posiciona navio diagonal ↙
void posicionar_diagonal_esquerda(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO <= TAM && coluna - (TAM_NAVIO - 1) >= 0) {
        int valido = 1;
        for (int k = 0; k < TAM_NAVIO; k++) {
            if (sobrepoe(tabuleiro, linha + k, coluna - k)) valido = 0;
        }
        if (valido) {
            for (int k = 0; k < TAM_NAVIO; k++) {
                tabuleiro[linha + k][coluna - k] = NAVIO;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // 1. Inicializar tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Definir coordenadas iniciais (fixas neste nível)
    // Dois navios tradicionais
    posicionar_horizontal(tabuleiro, 2, 1);   // Horizontal
    posicionar_vertical(tabuleiro, 5, 7);     // Vertical

    // Dois navios diagonais
    posicionar_diagonal_direita(tabuleiro, 0, 0);   // ↘ diagonal principal
    posicionar_diagonal_esquerda(tabuleiro, 0, 9);  // ↙ diagonal secundária

    // 3. Exibir tabuleiro
    printf("\n--- Tabuleiro Batalha Naval ---\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}



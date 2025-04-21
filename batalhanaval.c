#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Simulando navio
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    // --------- MATRIZES DE HABILIDADES (5x5) ---------
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // CONE para baixo (triângulo apontando pra baixo)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i >= j - 2 && i >= 2 - j) { // forma do cone
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // CRUZ (linha e coluna centrais)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // OCTAEDRO (forma de losango)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // --------- SOBREPOR HABILIDADES NO TABULEIRO ---------
    // Centro para aplicar habilidades
    int centro_linha = 4;
    int centro_coluna = 4;

    // Aplique o CONE
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int tab_i = centro_linha - 2 + i;
            int tab_j = centro_coluna - 2 + j;

            if (tab_i >= 0 && tab_i < 10 && tab_j >= 0 && tab_j < 10) {
                if (cone[i][j] == 1 && tabuleiro[tab_i][tab_j] == 0) {
                    tabuleiro[tab_i][tab_j] = 5; // habilidade visual
                }
            }
        }
    }

    // Aplique a CRUZ
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int tab_i = centro_linha - 2 + i;
            int tab_j = centro_coluna - 2 + j;

            if (tab_i >= 0 && tab_i < 10 && tab_j >= 0 && tab_j < 10) {
                if (cruz[i][j] == 1 && tabuleiro[tab_i][tab_j] == 0) {
                    tabuleiro[tab_i][tab_j] = 5;
                }
            }
        }
    }

    // Aplique o OCTAEDRO
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int tab_i = centro_linha - 2 + i;
            int tab_j = centro_coluna - 2 + j;

            if (tab_i >= 0 && tab_i < 10 && tab_j >= 0 && tab_j < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[tab_i][tab_j] == 0) {
                    tabuleiro[tab_i][tab_j] = 5;
                }
            }
        }
    }

    // --------- EXIBIR TABULEIRO FINAL ---------
    printf("\nLegenda: 0 = água | 3 = navio | 5 = área de habilidade\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

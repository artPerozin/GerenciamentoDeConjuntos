#include <stdio.h>
#include "negocio.h"

#define MAX_LIN 50
#define MAX_COL 50

int mat[MAX_LIN][MAX_COL] = {0};
int LIN, COL;

void definirTamanhoMatriz() {
    printf("Digite o numero de conjuntos (max %d): ", MAX_LIN);
    scanf("%d", &LIN);

    while (LIN < 1 || LIN > MAX_LIN) {
        printf("Valor invalido. Digite novamente (1-%d): ", MAX_LIN);
        scanf("%d", &LIN);
    }

    printf("Digite o tamanho maximo de cada conjunto (max %d): ", MAX_COL);
    scanf("%d", &COL);
    
    while (COL < 1 || COL > MAX_COL) {
        printf("Valor invalido. Digite novamente (1-%d): ", MAX_COL);
        scanf("%d", &COL);
    }

}

int criarNovoConjuntoVazio(int contador) {
    if(contador >= LIN) {
        printf("Limite maximo de conjuntos atingido!\n");
        return contador;
    }

    printf("conjunto n %d criado com exito! ", contador);
    return contador + 1;
}

void inserirDadosConjunto(int contador) {
    if (contador == 0) {
        printf("Nenhum conjunto criado ainda.\n");
        return;
    }

    int idx;
    printf("Qual conjunto (0 - %d) voce deseja inserir os dados: ", contador - 1);
    scanf("%d", &idx);

    if (idx < 0 || idx >= contador) {
        printf("Esse conjunto nao existe.\n");
        return;
    }

    int pos = 0;
    while (pos < COL && mat[idx][pos] != 0) {
        pos++;
    }

    int espacoDisponivel = COL - pos;
    if (espacoDisponivel == 0) {
        printf("O conjunto %d ja esta cheio.\n", idx);
        return;
    }

    int temp[COL];
    int i = 0, valor;
    printf("Digite valores para adicionar ao conjunto %d (digite 0 para encerrar):\n", idx);
    while (i < espacoDisponivel) {
        scanf("%d", &valor);
        if (valor == 0) break;
        temp[i++] = valor;
    }

    if (i < espacoDisponivel && valor != 0) {
        printf("Não ha espaço suficiente para todos os valores. Nenhum valor foi inserido.\n");
        return;
    }

    for (int j = 0; j < i; j++) {
        mat[idx][pos + j] = temp[j];
    }

    printf("Conjunto %d atualizado com sucesso!\n", idx);
}

int removerConjunto(int contador) {
    int idx;
    printf("Qual conjunto (0 - %d) deseja remover? ", contador - 1);
    scanf("%d", &idx);

    if (idx < 0 || idx >= contador) {
        printf("Esse conjunto nao existe.\n");
        return contador;
    }

    for (int j = 0; j < COL; j++) {
        mat[idx][j] = 0;
    }

    for (int i = idx; i < contador - 1; i++) {
        for (int j = 0; j < COL; j++) {
            mat[i][j] = mat[i + 1][j];
        }
    }

    for (int j = 0; j < COL; j++) {
        mat[contador - 1][j] = 0;
    }

    contador--;
    printf("Conjunto %d removido.\n", idx);
    return contador;
}

int unirConjuntos(int contador) {
    if(contador >= LIN) {
        printf("Limite maximo de conjuntos atingido!\n");
        return contador;
    }

    int idx1, idx2;
    printf("Qual primeiro conjunto (0 - %d) que voce deseja unir: ", contador - 1);
    scanf("%d", &idx1);

    if (idx1 < 0 || idx1 >= contador) {
        printf("Esse conjunto nao existe.\n");
        return contador;
    }

    printf("Qual o segundo conjunto (0 - %d) que voce deseja unir: ", contador - 1);
    scanf("%d", &idx2);

    if (idx2 < 0 || idx2 >= contador) {
        printf("Esse conjunto nao existe.\n");
        return contador;
    }

    criarNovoConjuntoVazio(contador);

    int k = 0;
    for (int i = 0; i < COL && mat[idx1][i] != 0; i++) {
        mat[contador][k++] = mat[idx1][i];
    }

    for (int i = 0; i < COL && mat[idx2][i] != 0; i++) {
        int existe = 0;
        for (int j = 0; j < k; j++) {
            if (mat[contador][j] == mat[idx2][i]) {
                existe = 1;
                break;
            }
        }
        if (!existe && k < COL) {
            mat[contador][k++] = mat[idx2][i];
        }
    }

    printf("Conjunto unido criado no indice %d.\n", contador);
    return contador + 1;
}

int interseccaoConjuntos(int contador) {
    if(contador >= LIN) {
        printf("Limite maximo de conjuntos atingido!\n");
        return contador;
    }

    int idx1, idx2;
    printf("Qual primeiro conjunto (0 - %d) que voce deseja fazer a interseccao: ", contador - 1);
    scanf("%d", &idx1);

    if (idx1 < 0 || idx1 >= contador) {
        printf("Esse conjunto nao existe.\n");
        return contador;
    }

    printf("Qual o segundo conjunto (0 - %d) que voce deseja fazer a interseccao: ", contador - 1);
    scanf("%d", &idx2);

    if (idx2 < 0 || idx2 >= contador) {
        printf("Esse conjunto nao existe.\n");
        return contador;
    }

    criarNovoConjuntoVazio(contador);
    int k = 0;

    for (int i = 0; i < COL && mat[idx1][i] != 0; i++) {
        for (int j = 0; j < COL && mat[idx2][j] != 0; j++) {
            if (mat[idx1][i] == mat[idx2][j]) {
                mat[contador][k++] = mat[idx1][i];
                break;
            }
        }
    }

    printf("Interseção criada no indice %d.\n", contador);
    return contador + 1;
}

void mostrarUmConjunto(int contador) {
    if (contador == 0) {
        printf("Nenhum conjunto criado ainda.\n");
        return;
    }

    int idx;
    printf("Qual conjunto (0 - %d) você deseja exibir: ", contador - 1);
    scanf("%d", &idx);

    if (idx < 0 || idx >= contador) {
        printf("Esse conjunto nao existe.\n");
        return;
    }

    printf("Conjunto %d: ", idx);
    for (int i = 0; i < COL; i++) {
        if (mat[idx][i] == 0) break;
        printf("%d ", mat[idx][i]);
    }
    printf("\n");
}

void mostrarTodosOsConjuntos(int contador) {
    if (contador == 0) {
        printf("Nenhum conjunto criado ainda.\n");
        return;
    }

    printf("\n=== Lista de todos os conjuntos ===\n");
    for (int i = 0; i < contador; i++) {
        printf("Conjunto %d: ", i);
        int vazio = 1;

        for (int j = 0; j < COL; j++) {
            if (mat[i][j] == 0) break;
            printf("%d ", mat[i][j]);
            vazio = 0;
        }

        if (vazio) printf("(vazio)");
        printf("\n");
    }
    printf("===================================\n\n");
}

void fazerBuscaPorUmValor(int valor) {
    int encontrou = 0;

    printf("Linhas que contem %d: ", valor);
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (mat[i][j] == valor) {
                if (encontrou) printf(", ");
                printf("Conjunto %d", i);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhuma linha contem %d", valor);
    }
    printf("\n");
}
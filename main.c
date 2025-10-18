#include <stdio.h>
#include "negocio.h"

int main() {
    int contador = 0;
    int opcao;
    int c;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Criar um novo conjunto vazio\n");
        printf("2. Inserir dados em um conjunto\n");
        printf("3. Remover um conjunto\n");
        printf("4. Unir dois conjuntos\n");
        printf("5. Criar a interseccao de dois conjutnos\n");
        printf("6. Mostrar um conjunto\n");
        printf("7. Mostrar todos os conjuntos\n");
        printf("8. Buscar por um valor\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao (1-9): ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while ((c = getchar()) != '\n' && c != EOF) { }
            opcao = 0;
        }

        switch (opcao) {
            case 1: criarNovoConjuntoVazio(contador); break;
            case 2: inserirDadosConjunto(contador); break;
            case 3: removerConjunto(contador); break;
            case 4: unirConjuntos(contador); break;
            case 5: interseccaoConjuntos(contador); break;
            case 6: mostrarUmConjunto(contador); break;
            case 7: mostrarTodosOsConjuntos(contador); break;
            case 8: fazerBuscaPorUmValor(contador); break;
            case 9: break;
            default:
                printf("Erro: opcao fora da tabela (1-9)\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}
#include "projeto.h"
#include <stdio.h>

int main() {
    ProdutoLista lista = criarProdutoLista();
    int opcao;

    do {
        printf("=== Menu ===\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Atualizar Produto\n");
        printf("4. Excluir Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1: {
                int subOpcao;

                printf("=== Submenu ===\n");
                printf("1. Queijo\n");
                printf("2. Vinho\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);
                limparTela();

                if (subOpcao == 1) {
                    char tipo[20];
                    int lote;

                    printf("Tipo do queijo: ");
                    scanf("%s", tipo);
                    limparTela();

                    printf("Lote do queijo: ");
                    scanf("%d", &lote);
                    limparTela();

                    adicionarProduto(&lista, tipo, lote);
                } else if (subOpcao == 2) {
                    char tipo[20];
                    int lote;

                    printf("Tipo do vinho: ");
                    scanf("%s", tipo);
                    limparTela();

                    printf("Lote do vinho: ");
                    scanf("%d", &lote);
                    limparTela();

                    adicionarProduto(&lista, tipo, lote);
                } else {
                    printf("Opcao invalida.\n");
                }

                break;
            }
            case 2:
                listarProdutos(lista);
                break;
            case 3:
                listarProdutos(lista);
                atualizarProduto(&lista);
                break;
            case 4:
                listarProdutos(lista);
                excluirProduto(&lista);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}


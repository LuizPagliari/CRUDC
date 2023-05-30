#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ProdutoLista criarProdutoLista() {
    ProdutoLista lista;
    lista.count = 0;
    return lista;
}

void adicionarProduto(ProdutoLista* lista, const char* tipo, int lote) {
    if (lista->count < MAX_PRODUTOS) {
        Produto produto;
        strncpy(produto.tipo, tipo, sizeof(produto.tipo));
        produto.lote = lote;

        lista->produtos[lista->count] = produto;
        lista->count++;

        printf("Produto adicionado com sucesso.\n");
    } else {
        printf("Limite de produtos excedido.\n");
    }
}

void listarProdutos(ProdutoLista lista) {
    if (lista.count == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < lista.count; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Tipo: %s\n", lista.produtos[i].tipo);
        printf("Lote: %d\n", lista.produtos[i].lote);
        printf("\n");
    }
}

void atualizarProduto(ProdutoLista* lista) {
    if (lista->count == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int produtoNum;

    do {
        printf("Digite o numero do produto a ser atualizado: ");
        scanf("%d", &produtoNum);
        limparTela();

        if (produtoNum < 1 || produtoNum > lista->count) {
            printf("Numero de produto invalido. Insira um numero valido.\n");
        }
    } while (produtoNum < 1 || produtoNum > lista->count);

    Produto* produto = &(lista->produtos[produtoNum - 1]);

    printf("Produto selecionado:\n");
    printf("Tipo: %s\n", produto->tipo);
    printf("Lote: %d\n\n", produto->lote);

    printf("Digite o novo tipo do produto: ");
    scanf("%s", produto->tipo);
    limparTela();

    printf("Digite o novo lote do produto: ");
    scanf("%d", &(produto->lote));
    limparTela();

    printf("Produto atualizado com sucesso.\n");
}

void excluirProduto(ProdutoLista* lista) {
    if (lista->count == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int produtoNum;

    do {
        printf("Digite o numero do produto a ser excluido: ");
        scanf("%d", &produtoNum);
        limparTela();

        if (produtoNum < 1 || produtoNum > lista->count) {
            printf("Numero de produto invalido. Insira um numero valido.\n");
        }
    } while (produtoNum < 1 || produtoNum > lista->count);

    for (int i = produtoNum - 1; i < lista->count - 1; i++) {
        lista->produtos[i] = lista->produtos[i + 1];
    }

    lista->count--;

    printf("Produto excluido com sucesso.\n");
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

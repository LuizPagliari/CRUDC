#ifndef PROJETO_H
#define PROJETO_H

#define MAX_PRODUTOS 100

typedef struct {
    char tipo[20];
    int lote;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int count;
} ProdutoLista;

ProdutoLista criarProdutoLista();
void adicionarProduto(ProdutoLista* lista, const char* tipo, int lote);
void listarProdutos(ProdutoLista lista);
void atualizarProduto(ProdutoLista* lista);
void excluirProduto(ProdutoLista* lista);
void limparTela();

#endif

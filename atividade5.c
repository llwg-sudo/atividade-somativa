#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual_desconto) {
    produto->preco = produto->preco - (produto->preco * percentual_desconto / 100.0f);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    int i;

    for (i = 0; i < quantidade; i++) {
        printf("Produto %d\n", i + 1);
        printf("ID: %d\n", (ptr + i)->id);
        printf("Preco: R$ %.2f\n\n", (ptr + i)->preco);
    }
}

int main() {
    int quantidade;
    int i;
    Produto *estoque;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    estoque = malloc(quantidade * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        Produto *produto_atual = estoque + i;

        printf("\nCadastro do produto %d\n", i + 1);

        printf("Digite o ID: ");
        scanf("%d", &produto_atual->id);

        printf("Digite o preco: ");
        scanf("%f", &produto_atual->preco);
    }

    printf("\nProdutos cadastrados:\n\n");
    imprimir_produtos(estoque, quantidade);

    if (quantidade > 0) {
        aplicar_desconto(estoque, 10.0f);

        printf("Depois de aplicar 10%% de desconto no primeiro produto:\n\n");
        imprimir_produtos(estoque, quantidade);
    }

    free(estoque);

    return 0;
}

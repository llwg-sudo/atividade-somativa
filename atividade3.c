#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual_desconto) {
    produto->preco = produto->preco - (produto->preco * percentual_desconto / 100.0f);
}

int main() {
    Produto produto = {1, 100.0f};

    printf("ID: %d\n", produto.id);
    printf("Preco antes do desconto: R$ %.2f\n", produto.preco);

    aplicar_desconto(&produto, 10.0f);

    printf("Preco depois do desconto: R$ %.2f\n", produto.preco);

    return 0;
}

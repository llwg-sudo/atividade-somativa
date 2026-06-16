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
    Produto estoque[3] = {
        {1, 100.0f},
        {2, 250.0f},
        {3, 80.0f}
    };

    aplicar_desconto(&estoque[0], 10.0f);

    imprimir_produtos(estoque, 3);

    return 0;
}

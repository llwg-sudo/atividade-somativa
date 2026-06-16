#include <stdio.h>

void aplicar_desconto(float *preco, float percentual_desconto) {
    *preco = *preco - (*preco * percentual_desconto / 100.0f);
}

int main() {
    float preco = 100.0f;

    printf("Preco antes do desconto: R$ %.2f\n", preco);

    aplicar_desconto(&preco, 10.0f);

    printf("Preco depois do desconto: R$ %.2f\n", preco);

    return 0;
}

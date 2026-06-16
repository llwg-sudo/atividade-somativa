#include <stdio.h>

int main() {
    float preco = 100.0f;
    float *ptr_preco = &preco;

    printf("Preco antes do aumento: R$ %.2f\n", preco);

    *ptr_preco = *ptr_preco * 1.10f;

    printf("Preco depois do aumento: R$ %.2f\n", preco);

    return 0;
}

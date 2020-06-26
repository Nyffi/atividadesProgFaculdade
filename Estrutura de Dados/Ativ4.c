float imprimeDevedor(struct tNo1 *devedores) {
    struct tNo1 *p = devedores;
    float divTotal = 0.00;

    if (p == NULL) {
        return divTotal;
    }

    while (p != NULL) {
        if (p->dado.divida > 0) {
            divTotal = divTotal + p->dado.divida;
            printf("Nome: %s\nIdade: %d\nDivida: R$ %.2f\n\n", p->dado.nome, p->dado.idade, p->dado.divida);
        }
    }
    return divTotal;
}

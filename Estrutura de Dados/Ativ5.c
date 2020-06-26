void transfereLista (struct tNo2 *naoDevedores, struct tNo1 *devedores) {
    struct tNo2 *p = naoDevedores, *novo;
    struct tNo1 *q = devedores, *aux;

    if (devedores == NULL) {
        return;
    }

    novo->dado.idade = q->dado.idade;
    novo->dado.divida = 0.00;
    strcpy(novo->dado.nome, q->dado.nome);

    while (p->prox != NULL) {
        p = p->prox;
    }
    novo->ant = p;
    p->prox = novo;
    novo->prox = NULL;

    aux = q;
    q = q->prox;
    free(aux);

    transfereLista(p, q);
}

int imprimeRepeticao (struct tNo1 devedores, struct tNo2 naoDevedores) {
    struct tNo1 *p = devedores, *auxP;
    struct tNo2 *q = naoDevedores, *auxQ;
    int contador = 0;

    if (p == NULL || q == NULL) {
        return 0;
    }

    auxP = p;
    auxQ = q;

    while (auxP != NULL) {
        while (auxQ != NULL) {
            if (strcmp(auxP->dado.nome, auxQ->dado.nome) == 0 && auxQ->dado.idade == auxP->dado.idade) {
                printf("Repeticao encontrada: %s\n", auxP->dado.nome);
                contador++;
            }
            auxQ = auxQ->prox;
        }
        auxP = auxP->prox;
        auxQ = q;
    }

    return contador;
}

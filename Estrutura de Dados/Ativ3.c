int comparaDados (struct tNo *L1, struct tNo *F1) {
    struct tNo *F2 = NULL, *L2 = NULL;

    while (F1 != NULL) {
        L2 = pop(&F1);
        push(&F2, L2);
    }
    F2 = F1;
    F2 = NULL;
    L2 = NULL;

    while (L1 != NULL && F1 != NULL) {
        F2 = pop(&F1);
        L2 = dequeue(&L1);

        if (F2 != L2) {
            return 1; //Falso
        }
    }

    if ((L1 == NULL && F1 != NULL) || (L1 != NULL && F1 == NULL)) {
        return 1; //Falso;
    }

    return 0; //Verdadeiro
}

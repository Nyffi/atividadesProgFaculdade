#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool bazTest(char *bazWord);

int main() {
    char baz[10];

    printf("Digite a palavra: Bazinga\n");
    gets(baz);
    if (bazTest(baz)) {
        printf("Voce bazingou com sucesso!");
        return 0;
    } else {
        printf("Voce falhou em bazingar.");
        return 0x00000045;
    }
}

bool bazTest(char *bazWord) {
    if (strcmp(bazWord, "bazinga") == 0) {
        return true;
    } else {
        return false;
    }
}
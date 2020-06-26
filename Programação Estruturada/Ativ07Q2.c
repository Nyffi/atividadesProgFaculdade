#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");

    int num;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &num);
    printf("Sum = %d",somaNum(num));
    return 0;
}
int somaNum(int num)
{
    if(num != 0)
        return num + somaNum(num-1);
    else
        return num;
}

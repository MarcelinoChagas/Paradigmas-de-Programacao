#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main()
{
    Lista *li;
    li = cria_lista();
    printf("Hello world!\n");
    printf("\n Tamanho da Lista: %d",tamanho_lista(li));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main(){

    struct aluno al, a[5] = {{1,"Fulando de Tal","81977772222",19, 7.0, 6.0, 8.0},
                            {2,"Sicrano de La","81900003333",21, 7.1, 6.1, 8.1},
                            {3,"Beltrano de Ca","81911112222",22, 7.2, 6.2, 8.2},
                            {4,"Itanhaem La","81944441111",23, 7.3, 6.3, 8.3},
                            {5,"Fulando de Tal","81988885555",24, 7.4, 6.4, 8.4}};

    Lista* li = cria_lista();

    // TRECHO DE INSERCAO
    printf("\nTamanho da Lista: %d",tamanho_lista(li));
    insere_lista_inicio(li,a[0]);
    printf("\nValor Inserido");
    printf("\nTamanho da Lista: %d",tamanho_lista(li));
    insere_lista_final(li,a[1]);
    printf("\nValor Inserido");
    printf("\nTamanho da Lista: %d",tamanho_lista(li));
    insere_lista_ordenada(li,a[2]);
    printf("\nValor Inserido");
    printf("\nTamanho da Lista: %d",tamanho_lista(li));

    // TRECHO DE REMOCAO
    remove_lista(li,1);
    printf("\n\nValor Removido");
    printf("\nTamanho da Lista: %d",tamanho_lista(li));
    remove_lista(li,2);
    printf("\nValor Removido");
    printf("\nTamanho da Lista: %d",tamanho_lista(li));


    // TRECHO CONSULTA
    int x;
    for(int i = 0; i < 4; i++)
        x = consulta_lista_mat(li, 3, &a[i]);
    printf("\n\n1 = Acho | 0 = Nao Achou");
    printf("\nResultado: %d",x);
    printf("\nTamanho da Lista: %d",tamanho_lista(li));

    // TRECHO ATUALIZACAO
    printf("\n\nValor Atualizado");
    atualizar_lista(li,3,a[4]);
    printf("\nTamanho da Lista: %d",tamanho_lista(li));

    return 0;
}

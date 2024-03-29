#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista {
    int qtd;
    struct aluno dados[MAX]
};

typedef struct lista* Elem;

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li -> qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}


// INSERIR
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li-> dados[li->qtd] = al;
    li-> qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){

    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i;
    for(i = li->qtd; i >= 0; i--)
        li-> dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k = li-> qtd-1; k >= i; k--)
        li-> dados[k+1] = li -> dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

// REMOVER
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;

    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k = 0; k < li->qtd-1; k++)
        li->dados[k] = li ->dados[k+1];
    li-> qtd--;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd)    // Elemento Nao Encontrado
        return 0;

    for(k = i; k < li->qtd-1; k++)
        li->dados[k] = li -> dados[k+1];
    li->qtd--;
    return 1;
}


// CONSULTA
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd) //Elemento nao encontrado
        return 0;

    *al = li->dados[i];

    return 1;
}


// ATUALIZA
int atualizar_lista(Lista* li, int mat, struct aluno al){
    int x;

    if(li == NULL)
        return 0;
    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd) //Elemento nao encontrado
        return 0;
    else{
        al = li->dados[i];
        x = 1;
    }

    // k, i = 0
    int j, l = 0;
    if(x == 1){

    while(l < li->qtd && li->dados[l].matricula < al.matricula)
        l++;

    for(j = li-> qtd-1; j >= l; j--)
        li-> dados[j+1] = li -> dados[j];
    li->dados[l] = al;
    return 1;

    }
}

#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#define MAX 10

struct aluno {
    int matricula;
    char nome[30];
    char telefone[11];
    int idade;
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

// INSERIR
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

// REMOVER
int remove_lista_final(Lista* li);
int remove_lista_inicio(Lista* li);
int remove_lista(Lista* li, int mat);

// CONSULTA
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);

// ATUALIZAR
int atualizar_lista(Lista* li, int mat, struct aluno al);

#endif // LISTASEQUENCIAL_H_INCLUDED

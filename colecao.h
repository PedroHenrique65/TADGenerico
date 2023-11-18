/*------------------------------------------------
Colecao.h
Arquivo com a especificação para o TAD Colecao,
tipo de dado para uma coleção genérica.
Exemplo do curso: Estrutura de Dados 1
---------------------------------------------------
Autor: Pedro Henrique
Novembro/2021
-------------------------------------------------*/
#ifndef COLECAO_H
#define COLECAO_H

typedef struct colecao
Colecao;

typedef struct aluno
Aluno;


Colecao *colCriar( int max_itens );

int colInserir( Colecao *c, int *item);

void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*));

void *colConsultar(Colecao *c, void *key, int(*cmp)(void*,void*));

int colDestruir( Colecao *c );

void *colpegarPrimeiro(Colecao *c);

void *colpegarProximo(Colecao *c);

void *colRemover(Colecao *c, void *key, int(*cmp)(void*,void*));

int compararAlunos(void *aluno1, void *aluno2);

int colEsvaziar(Colecao *c);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"
#define true 1
#define false 0

// Estrutura da colecao de alunos
typedef struct colecao{
  int numItens;
  int maxItens;
  int atual;
  void **item;
}Colecao;

// Estrutura do Aluno
typedef struct aluno{
    char nome[30];
    int idade;
    float media;
}Aluno;

Colecao *colCriar(int maxItens){
  Colecao *c;
  if (maxItens>0){
    c = (Colecao*)malloc(sizeof(Colecao));
    if(c!=NULL){
      c->item = (void**)malloc(sizeof(void*)*maxItens);
      if(c->item != NULL){
        c->maxItens = maxItens;
        c->numItens = 0;
        return c;
      }
      free(c);
    }
  }
return NULL;
}

int colInserir(Colecao *c, int *item ){
  if ( c != NULL ) {
    if ( c->numItens < c->maxItens) {
    c->item[c->numItens] = item;
    c->numItens++;
    return 1;
    }
  }
}
/* fim de colInserir */

void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*)) // Remove um aluno da coleção.
{
  int i, j;
  void *del;
  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      for(i=0; i < c->numItens; i++)
      {
        if(cmp(key, c->item[i]) == true)
        {
          del = c->item[i];
          for(j=i; j < c->numItens-1; j++)
          {
            c->item[j] = c->item[j+1];
          }
          c->numItens--;
          return del;
        }
      }
    }
  }
  return NULL;
}




//fim  de colRemover

void *colConsultar(Colecao *c, void *key, int(*cmp)(void*,void*)) // Checa se um aluno existe na coleção.
{
    int i;
    if(c!=NULL){
        if(c->item != NULL){
          if(c->numItens>0){
            for(i=0; i < c->numItens; i++){
                if(cmp(key, c-> item[i]) == true){
                    return c->item[i];
                }
            }
          }
        }
    }
    return NULL;
}

int colDestruir( Colecao *c ){
  if ( c != NULL ) {
    if ( c->numItens == 0 ) {
      free(c->item);
      free(c);
      return 1 ;
    }
  }
  return 0;
}


void *colpegarPrimeiro(Colecao *c){
  if(c!=NULL){
        if(c->item != NULL){
            c->atual = 0;
            return c->item[c->atual];
        }
    }
    return NULL;
}

void *colpegarProximo(Colecao *c)
{
    if(c!=NULL){
        if(c->item != NULL){
            c->atual++;
            if(c->atual < c->numItens){
                return c->item[c->atual];
            }
        }
    }
    return NULL;
}

Aluno *criarAluno(char nome[], int idade, float media){
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if(aluno != NULL){
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->media = media;
   // aluno->matricula = matricula;
    return aluno;
  }
  else{
    return NULL;
  }
}

int colEsvaziar(Colecao *c)
{
    int i;
    if(c != NULL)
    {
        if(c->numItens > 0)
        {
            for(i = 0; i < c->numItens; i++)
            {
                c->item[i] = NULL;
            }
            c->numItens = 0;
            return 1;
        }
    }
    return 0;
}
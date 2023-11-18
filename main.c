#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include <string.h>

typedef struct aluno{
    char nome[30];
    int matricula;
    float media;
}Aluno;

int cmpAluno(void *key, void *item){
    int *keymat; Aluno *colitem;
    keymat = (int *)key;
    colitem = (Aluno *)item;
    if (keymat == colitem->matricula)
        return 1;
    else{
        return 0;
    }
}



int main(){
  Colecao *cofoAlunos = NULL;
  Aluno *pAluno = NULL;

  int tamColecao;
  int i=0;
  int idade,op, turma, matricula;
  int qtdAlunos=1;
  float media;
  char nome[30];
  int *alunoParaRemover, *key;

  do{
    printf("\n---------TURMA FUTSTORESLZ---------\n");
    printf("1- Para criar e escolher o tamanho da turma. \n");
    printf("2- Para para matricular um aluno. \n");
    printf("3- Para listar os seus alunos cadastrados. \n");
    printf("4- Para remover um aluno da turma. \n");
    printf("5- Para consultar um aluno. \n");
    printf("6- Para esvaziar a colecao. \n");
    printf("7- Para destruir a colecao. \n");
    printf("0- Para fechar o menu. ");
    printf("\n---------TURMA FUTSTORESLZ---------\n");

    scanf("%d", &op);

    switch(op){
      case 1:
        if(cofoAlunos == NULL){
          printf("\n---------------");
          printf("\nDigite o tamanho da turma: ");
          scanf("%d",&tamColecao);

          if (tamColecao>0){
            cofoAlunos = colCriar(tamColecao);
            printf("\nTurma criada com sucesso! \n");
          }
          else{
            printf("Tamanho da turma insuficiente, tente colocar um valor maior que 0! \n");
          }
        }
        else{
          printf("já foi criada a turma");
        }
        break;

      case 2:
        if(cofoAlunos != NULL){
            for(int i=0; i<tamColecao; i++){
                pAluno = (Aluno *)malloc(sizeof(Aluno));
                printf("-------------------");
                printf("\nDigite o nome do %d aluno: ", i+1);
                scanf("%s", (pAluno->nome));
                printf("-------------------");
                printf("\nDigite uma matricula para o %d aluno: ", i+1);
                scanf("%d", &pAluno->matricula);
                printf("-------------------");
                printf("\nDigite a media do %d aluno: ", i+1);
                scanf("%f", &pAluno->media);
                printf("\n");
              if (colInserir(cofoAlunos, pAluno)){
                printf("Aluno matriculado\n");
              }
              else{
                printf("Erro na matricula");
              }
            }
          }else{
              printf("----------------");
              printf("\nTurma nao foi criada\n");
              printf("----------------");
          }

        break;

      case 3:
        if (cofoAlunos!=NULL){
        pAluno = colpegarPrimeiro(cofoAlunos);
        if(pAluno!=NULL){
        int i = 0;
        while(pAluno != NULL){
            printf("--------Aluno %d----------", i+1);
            i++;
            printf("\nAluno: %s\nMatricula: %d\nMedia: %.2f\n"
                 , (pAluno->nome),(pAluno->matricula), (pAluno->media));
            pAluno = colpegarProximo(cofoAlunos);
        }
        }else{
            printf("\n----------------");
            printf("\nNao há alunos matriculados\n");
            printf("----------------");
        }
        }else{
           printf("----------------");
           printf("\nTurma esta vazia\n");
           printf("----------------");
        }
        break;

      case 4:
         if(cofoAlunos != NULL){
                printf("\n----------------\n");
                printf("Digite o nome do aluno: ");
                scanf("%s", &nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("Digite a media do aluno: ");
                scanf("%f", &media);
                if(colRemover(cofoAlunos,(void *)matricula, cmpAluno) != NULL) // Aluno é removido da coleção.
                {
                    printf("\nAluno removido.\n");
                    }
                else
                {
                    printf("Aluno nao encontrado ou erro na remocao.\n\n");
                }
                free(pAluno);
            }
            else{
              printf("----------------");
              printf("\nTurma esta vazia\n");
              printf("----------------");
            }
            break;

      case 5:
          if (cofoAlunos !=NULL){
                printf("Digite o nome do aluno: ");
                scanf("%s", &nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("Digite a nota do aluno: ");
                scanf("%f", &media);
            if(colConsultar(cofoAlunos, (void *)matricula, cmpAluno)!= NULL){
                printf("\nO aluno esta matriculado");
            }else{
                printf("\nO aluno nao esta matriculado");
            }

          }else{
            printf("----------------");
            printf("\nTurma esta vazia\n");
            printf("----------------");
        break;

      case 6:
      if(cofoAlunos!=NULL){
            if(colEsvaziar(cofoAlunos)){
                pAluno = NULL;
                printf("Turma esvaziada");
            }else{
                printf("erro");
            }
      }else{
        printf("----------------");
        printf("\nTurma esta vazia\n");
        printf("----------------");
      }
        break;
      case 7:
      if (cofoAlunos!=NULL){
            if(colDestruir(cofoAlunos)== 1){
                printf("Turma fechada");
                cofoAlunos = NULL;
            }else{
                printf("A turma nao pode fechar, pois ha alunos matriculados");
            }
      }else{
        printf("----------------");
        printf("\nTurma esta vazia\n");
        printf("----------------");
      }
        break;
      case 0:
        printf("-------------------------");
        printf("-------------------------");
        break;
      default:
        printf("opção invalida, tente novamente!");
        break;
    }
    }


  }while(op != 0);

  return 0;
  }
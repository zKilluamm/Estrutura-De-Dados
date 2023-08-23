#include <stdlib.h>
#include <stdio.h>


//////////////////////////////
//Declaração da estrutura no//
//////////////////////////////

struct no{
    int numero;
    struct no *anterior;
    struct no *proximo;


};

struct no *cabeca = NULL;

void inserir(int numero){
    //Alocacao na memoria
    struct no *NovoNo = (struct no *) malloc(sizeof(struct no));
    NovoNo -> numero = numero;
    NovoNo -> anterior = NULL;
    NovoNo -> proximo = NULL;

    if (cabeca == NULL){
        //Caso facil, a lista esta vazia
        cabeca = NovoNo;
    }else{
    //Caso dificil, a lista NAO esta vazia
    struct no *ponteiro = cabeca;

    while (ponteiro -> proximo != NULL){
        ponteiro = ponteiro -> proximo;
        }
    //Executa os parametros
    ponteiro -> proximo = NovoNo;
    NovoNo -> anterior = ponteiro;



    }

}

void imprimir(){
    struct no *ponteiro = cabeca;

    while(ponteiro != NULL){
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;


    }


    printf("------------------------\n");
    printf("|BOLSONARO22BOLSONARO22|\n");
    printf("------------------------\n");

}

void remover(int numero){

          struct no *ponteiro = cabeca;

    while (ponteiro != NULL){
        if (ponteiro -> numero == numero){
            if(ponteiro -> anterior == NULL){
                //excluir o primeiro no da lista
                cabeca = cabeca -> proximo;
                if (cabeca != NULL){
                    cabeca -> anterior = NULL;
                }
                free(ponteiro);
                ponteiro = cabeca;
            }else if(ponteiro -> proximo == NULL){
                //Excluir o ultimo no da lista
                struct no *temp = ponteiro;
                ponteiro = ponteiro -> anterior;
                ponteiro -> proximo = NULL;
                free(temp);
            }else{
            //excluir um no no meio da lista

            struct no *temp = ponteiro;
            ponteiro = ponteiro -> anterior;
            temp -> anterior -> proximo = ponteiro -> proximo;
            temp -> proximo -> anterior = ponteiro -> anterior;
            free(temp);
                }
            }
    if (ponteiro != NULL){
        ponteiro = ponteiro -> proximo;
        }
    }
}



////////////////////////////////////////////
//funcao principal de execucao do programa//
////////////////////////////////////////////


int main(){
    remover(1);
    imprimir();

    inserir(1);
    remover(1);
    imprimir( );

    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    remover(1);
    remover(5);

    imprimir( );

}

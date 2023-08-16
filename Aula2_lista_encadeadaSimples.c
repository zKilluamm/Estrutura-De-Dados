#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////
//PROGRAMA DE LISTA DE ENCADEAMENTO SIMPLES//
/////////////////////////////////////////////




struct no{
	int numero;
	struct no *proximo;
};
///////////////////////////
//DECLARAÇÃO DE VARIÁVEIS//
///////////////////////////

struct no *cabeca = NULL;


//////////////////////////////////////
//FUNCAOI QUE INSERE UM NO NA LISTA//
/////////////////////////////////////
void inserir(int numero){


	//ALOCANDO ESPACO NA MEMORIA
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;

	if (cabeca == NULL){
		//caso facil, a lista esta vazia
		cabeca = novoNo;

	}else{
		//caso dificil, a lista nao esta vazia
		struct no *ponteiro = cabeca;

		while (ponteiro -> proximo != NULL){

			ponteiro = ponteiro -> proximo;
		}

		ponteiro -> proximo = novoNo;
	}
}
	void imprimir(){
        printf("\n");

        struct no *ponteiro = cabeca;
        while(ponteiro != NULL){
            printf("%d\n", ponteiro -> numero);
            ponteiro = ponteiro -> proximo;
        }

	}



//FUNCAO QUE EXCLUI O NO DA LISTA//

void remover(int numero){
if(cabeca != NULL){
    if (cabeca -> numero == numero){
        //caso facil, escluir o primero no da lista
        struct no *ponteiroExcluir = cabeca;
        cabeca = cabeca -> proximo;
        free (ponteiroExcluir);
    }else{
        //caso dificil, excluir algum no no meio da lista
        struct no *ponteiroAnterior = cabeca;

        while ((ponteiroAnterior -> proximo -> numero != numero)&&
        (ponteiroAnterior -> proximo -> numero !=numero)){
            ponteiroAnterior = ponteiroAnterior -> proximo;

        }
        if (ponteiroAnterior -> proximo != NULL){
            struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
            ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
            free(ponteiroExcluir);
        }

    }
 }



}

///////////////////////////////////////////
//FUNCAO PRINCIPAL DE EXCUCAO DO PROGRAMA//
///////////////////////////////////////////

int main (int argc, char *argv[]){
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    inserir(6);

    imprimir();

    remover(100);
    remover(1);
    remover(3);
    remover(6);

    imprimir();
}

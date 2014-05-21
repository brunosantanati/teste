#include <stdio.h>
#include <stdlib.h>

struct no{
       int dado;
       struct no *proximo;       
       struct no *anterior;
};

typedef struct no No;
void inserirNovoNo(No **ptrParaPtrPrimeiroNo, No **ptrParaPtrUltimoNo, int dado);
int isEmpty(No *ponteiroPrimeiroNo);
void mostrarDadosDosNos(No *ponteiroPrimeiroNo);
No *getListaInvertida(No *ponteiroPrimeiroNo);

int main(void){
    No *ponteiroPrimeiroNo = NULL;
    No *ponteiroUltimoNo = NULL;
    
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 1);
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 2);
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 2);
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 2);
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 3);
    inserirNovoNo(&ponteiroPrimeiroNo, &ponteiroUltimoNo, 5);

    printf("Lista antes da inversao \n");
    mostrarDadosDosNos(ponteiroPrimeiroNo);
        
    printf("\n\nLista apos inversao \n");
    No *ptrPrimeiroNoListaInvertida = getListaInvertida(ponteiroUltimoNo);
    mostrarDadosDosNos(ptrPrimeiroNoListaInvertida);

    getch();

    return 0;    
}

void inserirNovoNo(No **ptrParaPtrPrimeiroNo, No **ptrParaPtrUltimoNo, int dado){
     No *novoNo = (No*) malloc(sizeof(No));
     novoNo->dado = dado;
     
     if(isEmpty(*ptrParaPtrPrimeiroNo)){
          novoNo->proximo = NULL;
          novoNo->anterior = NULL;
          *ptrParaPtrPrimeiroNo = novoNo;
     }else{
          novoNo->proximo = NULL;
          novoNo->anterior = *ptrParaPtrUltimoNo;
          (*ptrParaPtrUltimoNo)->proximo = novoNo;
     }
     
     *ptrParaPtrUltimoNo = novoNo;
}

int isEmpty(No *ponteiroPrimeiroNo){
     return (ponteiroPrimeiroNo == NULL);
}

void mostrarDadosDosNos(No *ponteiroPrimeiroNo){
     No *temp;
     
     printf("Nos: ");
     for(temp = ponteiroPrimeiroNo; temp != NULL; temp = temp->proximo){
          printf("%d -> ", temp->dado);         
     }     
     printf("NULL");
}

No *getListaInvertida(No *ponteiroUltimoNo){
     No *ptrPrimeiroNoListaInvertida = NULL;
     No *ptrUltimoNoListaInvertida = NULL;
     No *noAtual = ponteiroUltimoNo;
     No *noTemporario = NULL;
     int isPrimeiraIteracao = 1;
     
     while(noAtual != NULL){
          if(isPrimeiraIteracao){
               inserirNovoNo(&ptrPrimeiroNoListaInvertida,
                     &ptrUltimoNoListaInvertida, noAtual->dado);
               isPrimeiraIteracao = 0;
          }else if(noAtual->dado != noTemporario->dado){
               inserirNovoNo(&ptrPrimeiroNoListaInvertida,
                     &ptrUltimoNoListaInvertida, noAtual->dado);
          }
          noTemporario = noAtual;
          noAtual = noAtual->anterior;
     }     
     
     return ptrPrimeiroNoListaInvertida;                        
}

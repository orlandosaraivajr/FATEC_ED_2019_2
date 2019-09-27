/*
 * Exemplo do uso de fila com uso de vetor.
 *
 * Neste exemplo, faço uso de typedef.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 28/04/2018
 */
 #include <iostream>
 #include <stdlib.h>

using namespace std;

 typedef int ELEMENTO;

 typedef struct NO{
 	ELEMENTO valor;
 	struct NO* prox;
 }*FILA;

 FILA novoElemento(ELEMENTO elem){
 	FILA aux = (FILA) malloc( sizeof(NO) );
 	aux->valor = elem;
 	aux->prox  = NULL;
 	return aux;
 }

 FILA enqueue(ELEMENTO elem, FILA no){
     if(no == NULL) {
         return novoElemento(elem);
     }
 	FILA aux = novoElemento(elem);
 	aux->prox = no;
 	return aux;
 }

 void mostraFila(FILA no){
 	while(no != NULL){
 		cout <<"[" << no->valor << "] -> ";
 		no = no->prox;
 	}
 	cout << endl;
 }

 ELEMENTO dequeue(FILA no){
    ELEMENTO temp;
 	FILA noAnterior = no;
 	while(no->prox != NULL){
 		noAnterior = no;
 		no = no->prox;
 	}
 	noAnterior->prox = NULL;
    temp = no->valor;
 	free(no);
    return temp;
 }

 int tamanhoFila(FILA no){
     FILA fila_local = no;
 	int cont = 0;
 	while(fila_local != NULL){
 		cont++;
 		fila_local = fila_local->prox;
 	}
 	return cont;
 }

 void destruir(FILA no){
    cout << endl<< endl;
    FILA noProximo = no;
    while(noProximo->prox != NULL){
 		cout << "| " << noProximo->valor << endl;
        no = noProximo;
        noProximo = no->prox;
        no->prox = NULL;
        free(no);
 	}
    no = noProximo;
    cout << "| " << no->valor << endl;
    no->prox = NULL;
    free(no);

 }

 int buscaFila(ELEMENTO ch, FILA no){
     int cont = tamanhoFila(no);
     while(no != NULL){
         if (ch == no->valor) {
             return cont;
         }
         cont--;
         no = no->prox;
     }
     return cont;
 }

 int main(){
     FILA fila = NULL;
    // FILA fila = novoElemento(5);
    fila = enqueue(5, fila);
    fila = enqueue(8, fila);
    fila = enqueue(1, fila);
    fila = enqueue(3, fila);
    fila = enqueue(5, fila);
    fila = enqueue(4, fila);
    fila = enqueue(2, fila);

    mostraFila(fila);

    cout << "O valor 4 encontra-se na posicao "<< buscaFila(4, fila) << " da fila" << endl;
    cout << "O valor 8 encontra-se na posicao "<< buscaFila(8, fila) << " da fila" << endl;
    
    cout << "Atendimento para: " << dequeue(fila) << endl;
    mostraFila(fila);
    cout << "O valor 8 encontra-se na posicao "<< buscaFila(8, fila) << " da fila" << endl;
    cout << "Atendimento para: " << dequeue(fila) << endl;
    mostraFila(fila);

    cout << "Tamanho da fila: " << tamanhoFila(fila) ;

    destruir(fila);


    return 0;
 }

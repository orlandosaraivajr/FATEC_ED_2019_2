/*
 * Exercício 02 - Pilha.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 28/09/2019
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct node {
    string url;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int contador;
} Pilha;


Pilha * inicializar() {
    // Pilha * s = (Pilha *)malloc(sizeof(Pilha));
    Pilha * s = new Pilha;
    s->contador = 0;
    s->top = NULL;
}

void push(Pilha *s) {
    Node *np; 

    // np = (Node *)malloc(sizeof(Node));
    np = new Node;
    if (np == NULL) {
        exit(1);
    }

	cout << "Digite o site navegado " << endl;
    cin >> np->url ;
    np->next = s->top;
    s->top = np;

    s->contador++;
}

void imprime_pilha(Pilha *s) {
	Node* temp;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
    cout << "Total de sites visitados : ";
    cout << s->contador << endl << endl;
	while(temp!=NULL){
		cout << temp->url << endl;
		temp = temp->next;
	}
	cout << endl;
}

string desempilha(Pilha *s) {
    string last_url = "";
    Node *np;
    if (s->top == NULL) {
    	return last_url;
    }
    np = s->top;
    last_url = s->top->url;
    s->top = np->next;
    s->contador = s->contador - 1;
    delete np;
	return last_url;
}

void pop(Pilha *pilha_local) {
    string last_url;
    last_url = desempilha(pilha_local);
	cout << "Desempilhado:   " << last_url << endl;
    return;
}

void destruir_pilha(Pilha *s) {
    while (s->top != NULL) {
        pop(s);
    }
    pop(s);
    delete s;
}


int main() {

    Pilha *minha_pilha = inicializar();
    push(minha_pilha);
    push(minha_pilha);
    push(minha_pilha);
    imprime_pilha(minha_pilha);
    pop(minha_pilha);
    cout << "Agora a URL em main " << endl;
	cout << desempilha(minha_pilha);
	destruir_pilha(minha_pilha);
    return 0;
}

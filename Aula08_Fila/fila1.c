/*
 * Exemplo do uso de fila com uso de vetor.
 *
 * Neste exemplo, faço uso de variáveis estáticas.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 28/04/2018
 * Alterado em : 20/09/2018
 */
 #include <iostream>

using namespace std;

struct Item {
    int     valor;
};

static Item *fila;
static int N, inicio, fim;

void inicializar(int maxN) {
	fila = new Item[maxN];
	N = maxN;
	inicio = N - 1;
	fim = 0;
}

void inserir(Item item) {
	fila[fim++] = item;
	fim = fim % N;
}

Item sair_fila(void) {
	inicio = (inicio + 1) % N;
	return fila[inicio];
}

void imprime_fila() {
    int x;
	for (x = 0; x < N ; x++)
		cout << fila[x].valor <<" ";
    cout << endl;

}

int main(void) {
	Item i;
    int x;

    N = 20;

	inicializar(N);

    for ( x = 0; x<N;x++) {
        i.valor = x + 1;
        inserir(i);
    }
    imprime_fila();

    for ( x = 0; x<N;x++) {
        cout << "Do comeco: " <<  sair_fila().valor << endl;
    }
    i.valor = 46;
    inserir(i);
    i.valor = 45;
    inserir(i);
    i.valor = 47;
    inserir(i);
    imprime_fila();

    delete fila;
	return 0;
}

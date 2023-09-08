#include <iostream>

using namespace std;

/*
5. Faça uma função “insere_meio(int vet[ ], int tam)” que insere um elemento no meio
de um vetor de números inteiros. Depois faça o programa principal para testar a sua
função.
Por exemplo:
Sendo o vetor = {1,2,3,4,5,6} e qtde = 6, ao usar
insere_meio(vetor, qtde, 100),
será retornado o novo valor de qtde, que passou a ser 7, e o vetor, ao término
da função, passará a ficar da seguinte forma: vetor= {1,2,3,100,4,5,6}.
Protótipo da função: int insere_meio( int *vetor, int qtde, int elemento);
*/

int insere_meio( int *vetor, int qtde, int elemento);

int main(void){
    srand(time(NULL));

    int qtde = 8;
    int vetor[qtde];

    for(int i = 0; i < qtde; i++){
        vetor[i] = rand() % 100;

        cout << vetor[i] << " ";
    }
    cout << endl;

    qtde = insere_meio(vetor, qtde, 100);

    for(int i = 0; i < qtde; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}

int insere_meio( int *vetor, int qtde, int elemento){
    int aux = qtde / 2;

    for(int i = qtde+1; i > aux; i--){
        vetor[i] = vetor[i - 1];
    }

    vetor[aux] = elemento;

    return qtde + 1;
}
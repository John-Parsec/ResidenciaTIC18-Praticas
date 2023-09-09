#include <iostream>

using namespace std;
/*
Faça uma função “insere_meio(int vet[ ], int tam)” que insere um elemento no meio
de um vetor de números inteiros. Depois faça o programa principal para testar a sua
função.
*/

int insere_meio( int *vetor, int qtde, int elemento);

int main(void){
    srand(time(NULL));
    int vetor[] = {0, 1, 2, 3, 4, 5, 6};
    int qtde, elemento;

    qtde = size(vetor);
    
    cout << "Vetor: ";
    for(int i = 0; i < qtde; i++){
        cout << vetor[i] << " ";
    }

    cout << endl << "\nDigite o elemento a ser inserido: ";
    cin >> elemento;

    qtde = insere_meio(vetor, qtde, elemento);

    cout << "\nVetor atualizado: ";
    for(int i = 0; i < qtde; i++)
        cout << vetor[i] << " ";
    cout << endl;

    return 0;
}

int insere_meio( int *vetor, int qtde, int elemento){
    int aux = qtde/2;

    for(int i = qtde; i > aux; i--){
        vetor[i] = vetor[i-1];
    }

    vetor[aux] = elemento;

    return qtde + 1;
}
/*OBS: Esta função passa do limite de memoria alocado para o vetor, o que pode gerar problemas.*/
#include <iostream>

using namespace std;
/*
Escreva uma função chamada maxmin que receba um vetor de números inteiros
chamado vetor, uma variável inteira n contendo o tamanho do vetor, e os endereços
de duas variáveis inteiras, maximo e minimo nas quais será retornado o valor do
elemento de maior valor e o valor do elemento de menor valor.
*/

void maxmin(int vetor[], int n, int &maximo, int &minimo);

int main(void){
    srand(time(NULL));
    int maximo = 0, minimo = 0;
    int vtam = 10;
    int vetor[vtam];


    cout << "Vetor: ";
    for(int i = 0; i < vtam; i++){
        vetor[i] = rand() % 100;

        cout << vetor[i] << " ";
    }
    cout << endl;

    maxmin(vetor, vtam, maximo, minimo);

    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    return 0;
}

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    if (n > 0){
        maximo = minimo = vetor[0];

        for(int i = 1; i < n; i++){

            if(vetor[i] > maximo){
                maximo = vetor[i];
            }
            if(vetor[i] < minimo){
                minimo = vetor[i];
            }
        }
    }    
}

/*
Qual o tipo de coesão e acoplamento da função?
    Coesão: Funcional
    Acoplamento: Forte
*/
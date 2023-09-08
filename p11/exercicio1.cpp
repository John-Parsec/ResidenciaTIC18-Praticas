#include <iostream>

using namespace std;
/*
1. Escreva uma função chamada maxmin que receba um vetor de números inteiros
chamado vetor, uma variável inteira n contendo o tamanho do vetor, e os endereços
de duas variáveis inteiras, maximo e minimo nas quais será retornado o valor do
elemento de maior valor e o valor do elemento de menor valor.
Protótipo da Função:
void maxmin(int vetor[], int n, int &maximo, int &minimo);
Escreva também uma função principal (main) que use a função maxmin.
*/

void maxmin(int vetor[], int n, int &maximo, int &minimo);

int main(void){
    srand(time(NULL));

    int vtam = 10;
    int vetor[vtam];
    int max, min;

    for(int i = 0; i < vtam; i++){
        vetor[i] = rand() % 100;
        cout << vetor[i] << " ";
    }
    
    cout << endl << endl;

    maxmin(vetor, vtam, max, min);
    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

    return 0;
}

void maxmin(int vetor[], int n, int &maximo, int &minimo){
    for(int i = 0; i < n; i++){
        if(vetor[i] > maximo){
            maximo = vetor[i];
        }
        if(vetor[i] < minimo){
            minimo = vetor[i];
        }
    }
}

/*
2. Qual o tipo de coesão e acoplamento da função do exercício 1?
R: Coesão funcional e acoplamento baixo.
*/

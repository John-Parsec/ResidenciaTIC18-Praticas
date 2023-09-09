#include <iostream>

using namespace std;
/*
Faça uma função que receba um vetor de números inteiros por parâmetro, a
quantidade de elementos do vetor, e um multiplicador e multiplique cada elemento
do vetor pelo multiplicador.
*/

void multiplica_por_n(int *vet, int qtde, int n){
    for(int i = 0; i < qtde; i++){
        vet[i] *= n;
    }
}

int main(void){

    int *vet, qtde, n;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> qtde;

    cout << "Digite o multiplicador: ";
    cin >> n;

    vet = new int[qtde];

    cout << "Digite os elementos do vetor:\n";
    for(int i = 0; i < qtde; i++){
        cin >> vet[i];
    }

    multiplica_por_n(vet, qtde, n);

    cout << "\nValores multiplicados: \n";
    for(int i = 0; i < qtde; i++){
        cout << vet[i] << " ";
    }
    cout << endl;

    return 0;
}


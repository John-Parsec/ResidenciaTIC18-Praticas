#include <iostream>

using namespace std;
/*
Faça uma função chamada conta_primos que receba um vetor de números inteiros e
retorne a quantidade de números do vetor que são primos.
*/

int conta_primos (int *vet, int qtde);

bool ver_primo(int n);

int main(void){
    int *vet, qtde;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> qtde;

    vet = new int[qtde];

    cout << "Digite os elementos do vetor:\n";
    for(int i = 0; i < qtde; i++){
        cin >> vet[i];
    }

    cout << "\nQuantidade de números primos: " << conta_primos(vet, qtde) << endl;

    return 0;
}

int conta_primos (int *vet, int qtde){
    int cont = 0;

    for(int i = 0; i < qtde; i++){
        if(ver_primo(vet[i])){
            cont++;
        }
    }

    return cont;
}

bool ver_primo(int n){
    if(n == 1){
        return false;
    }

    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}
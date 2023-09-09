#include <iostream>

using namespace std;
/*
Faça uma função que receba dois vetores de números inteiros e os seus
respectivos tamanhos por parâmetro e retorne um vetor com os valores dos dois
vetores intercalados.
*/

int* intercala(int *vet1, int tam1, int *vet2, int tam2);

int main(void){
    int *vet1, *vet2, *vet3, tam1, tam2;
    int valor = 1;

    cout << "Digite o tamanho do primeiro vetor: ";
    cin >> tam1;

    cout << "Digite o tamanho do segundo vetor: ";
    cin >> tam2;

    vet1 = new int[tam1];
    vet2 = new int[tam2];

    cout << "Vetor 1: ";
    for(int i = 0; i < tam1; i++){
        vet1[i] = valor++;
        cout << vet1[i] << " ";
    }
    cout << endl;

    cout << "Vetor 2: ";
    for(int i = 0; i < tam2; i++){
        vet2[i] = valor++;
        cout << vet2[i] << " ";
    }
    cout << endl;

    vet3 = intercala(vet1, tam1, vet2, tam2);

    cout << "Vetor 3: ";
    for(int i = 0; i < tam1 + tam2; i++){
        cout << vet3[i] << " ";
    }
    cout << endl;

    return 0;
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int *vet3 = new int[tam1 + tam2];
    int optVetor = 1, contTam1 = 0, contTam2 = 0;

    for(int i = 0; i < tam1+tam2; i++){
        if(optVetor == 1)
            vet3[i] = vet1[contTam1++];
        else
            vet3[i] = vet2[contTam2++];
        
        if(contTam1 == tam1)
            optVetor = 2;
        else if(contTam2 == tam2)
            optVetor = 1;
        else if(optVetor == 1)
            optVetor = 2;
        else
            optVetor = 1;
    }

    return vet3;
}
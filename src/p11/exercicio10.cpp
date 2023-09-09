#include <iostream>

using namespace std;
/*
Escreva uma função que recebe uma string de caracteres e uma letra e devolve um
vetor de inteiros contendo as posições (índices no vetor da string) onde a letra foi
encontrada) e um inteiro contendo o tamanho do vetor criado (total de letras iguais
encontradas). Utilize o retorno de um vetor para retornar os índices e um ponteiro
para guardar o tamanho do vetor.
*/

int* posicoes(string str, char letra, int *tam);

int main(void){
    int *vet, tam;
    char letra;
    string str;

    cout << "Digite uma string: ";
    getline(cin, str);

    cout << "Digite uma letra: ";
    cin >> letra;

    vet = posicoes(str, letra, &tam);

    cout << "Posicoes onde a letra foi encontrada: ";
    for(int i = 0; i < tam; i++){
        cout << vet[i] << " ";
    }
    cout << endl;

    return 0;
}

int* posicoes(string str, char letra, int *tam){
    int vtam = str.length();
    int *vet = new int[vtam];
    int aux = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == letra){
            vet[aux] = i;
            aux++;
        }
    }

    *tam = aux;

    return vet;
}
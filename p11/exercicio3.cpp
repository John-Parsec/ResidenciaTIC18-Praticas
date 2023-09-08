#include <iostream>

using namespace std;

/*
3. Faça uma função que receba (por referência) 4 variáveis float e ordena (crescente) os
valores destas variáveis. Depois faça o programa principal para testar a sua função.
*/

void ordena(float &a, float &b, float &c, float &d){
    float vetor[4] = {a, b, c, d};
    float aux;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    a = vetor[0];
    b = vetor[1];
    c = vetor[2];
    d = vetor[3];
}

int main(void){
    srand(time(NULL));

    float a, b, c, d;

    cout << "Digite 4 numeros de ponto flutuante: " << endl;
    cin >> a >> b >> c >> d;

    ordena(a, b, c, d);

    cout << "Numeros ordenados: " << endl;
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}
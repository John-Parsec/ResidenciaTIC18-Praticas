#include <iostream>

using namespace std;
/*
Faça uma função que receba (por referência) 4 variáveis float e ordena (crescente) os
valores destas variáveis. Depois faça o programa principal para testar a sua função.
*/

void ordena(float &a, float &b, float &c, float &d){
    float ordem[4] = {a, b, c, d};

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(ordem[i] > ordem[j]){
                float aux = ordem[i];
                ordem[i] = ordem[j];
                ordem[j] = aux;
            }
        }
    }

    a = ordem[0];
    b = ordem[1];
    c = ordem[2];
    d = ordem[3];
}

int main(void){
    srand(time(NULL));
    float a = rand() % 100, b = rand() % 100, c = rand() % 100, d = rand() % 100;

    cout << "Antes: " << a << " | " << b << " | " << c << " | " << d << endl;

    ordena(a, b, c, d);

    cout << "Depois: " << a << " | " << b << " | " << c << " | " << d << endl;

    return 0;
}
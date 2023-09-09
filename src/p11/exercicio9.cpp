#include <iostream>

using namespace std;
/*
Faça uma função para calcular o valor de S, dado por:
S = 1/n + 2/(n-1) + 3/(n-2) + ... + n/1
*/

float calc_serie(int N){
    float S = 0;

    for(int i = 1; i <= N; i++){
        S += i/(N-i+1);
    }

    return S;
}

int main(void){

    int N;

    cout << "Digite o valor de N: ";
    cin >> N;

    cout << "S = " << calc_serie(N) << endl;

    return 0;
}
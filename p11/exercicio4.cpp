#include <iostream>

using namespace std;

/*
4. Escreva uma função calcula que:
    a. receba como parâmetros duas variáveis inteiras, X e Y;
    b. retorne em X a soma de X e Y;
    c. retorne em Y a subtração de X e Y.
*/

void calcula(int &x, int &y){
    int aux = x;
    x = x + y;
    y = aux - y;
}

int main(void){

    int x, y;

    cout << "Digite dois numeros inteiros: " << endl;
    cin >> x >> y;

    calcula(x, y);

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    return 0;
}
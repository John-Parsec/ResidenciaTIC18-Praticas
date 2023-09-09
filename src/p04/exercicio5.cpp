#include <iostream>

using namespace std;

int main(void){
    int n;
    float f;
    char ch;
    bool b;

    cout << "bool: " << endl;
    b = true;
    cout << " true : " << b << endl;
    b = false;
    cout << " false : " << b << endl;
    
    cout << endl;

    n = 25;
    cout << "int em bool: " << endl;
    cout << "n= " << n << " | " << " >0 : " << (bool)n << endl;
    n = -25;
    cout << "n= " << n << " | " << " <0 : " << (bool)n << endl;
    n = 0;
    cout << "n= " << n << " | " << " =0 : " << (bool)n << endl;

    cout << endl;

    f = 21.5;
    cout << "float em bool: " << endl;
    cout << "f= " << f << " | " << " >0.0 : " << (bool)f << endl;
    f = -21.5;
    cout << "f= " << f << " | " << " <0.0 : " << (bool)f << endl;
    f = 0.0;
    cout << "f= " << f << " | " << " =0.0 : " << (bool)f << endl;

    cout << endl;

    cout << "char em bool: " << endl;
    ch = 'a';
    cout << "ch= " << ch << " | " << " nao nulo : " << (bool)ch << endl;
    ch = '0';
    cout << "ch= " << ch << " | " << " nao nulo : " << (bool)ch << endl;
    ch = '\0';  // caractere nulo
    cout << "ch= " << ch << " | " << " nulo : " << (bool)ch << endl;

    return 0;
}
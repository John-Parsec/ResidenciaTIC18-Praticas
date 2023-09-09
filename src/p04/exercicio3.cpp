#include <iostream>
#include <climits>

using namespace std;

int main(void){
    unsigned int uimin = 0;
    unsigned long int ulimin = 0;
    unsigned long int uli;
    unsigned int ui;
    long int li;

    cout << "a)" << endl;
    cout << "int valor min: " << INT32_MIN << endl;
    cout << "int valor max: " << INT32_MAX << endl;


    cout << "\nb)" << endl;
    cout << "unsigned long int valor min: " << ulimin << endl;
    cout << "unsigned long int valor max: " << ULONG_MAX << endl;
    uli = ULONG_MAX;


    cout << "\nc)" << endl;
    li = uli;
    cout << "li: " << li << endl;
    uli = li;
    cout << "uli: " << uli << endl;
    //o valor maximo do unsigned long int eh maior que o valor maximo do long int, logo,
    //o valor maximo do unsigned long int nao pode ser armazenado em um long int e gera um overflow.
    //porem, quando o valor em overflow do li e atribuido ao uli ele e apresentado normalmente já que
    //o uli consegue armazenar aquele valor.


    cout << "\nd)" << endl;
    cout << "long int valor min: " << LONG_MIN << endl;
    cout << "long int valor max: " << LONG_MAX << endl;
    li = LONG_MAX;


    cout << "\ne)" << endl;
    ui = li;
    cout << "ui: " << ui << endl;
    li = ui;
    cout << "li: " << li << endl;
    //o valor maximo do long int cabe em um unsigned int, logo, nao gera overflow.
    //por tanto, o valor entre os dois pode ser atribuido normalmente.

    cout << "\nf)" << endl;
    cout << "unsigned int valor max: " << UINT32_MAX << endl;
    cout << "unsigned int valor min: " << uimin << endl;
    ui = UINT32_MAX;
    
    return 0;
}
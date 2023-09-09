#include <iostream>
#include <locale>

using namespace std;

/*
As variáveis de tipo bool podem assumir valores true ou false. Elas
serão amplamente utilizadas nos próximos tópicos. Entretanto, outros tipos
de dados podem ser utilizados no lugar de valores bool e seus valores são
convertidos em true ou false.
a. Faça uma aplicação que mostre como os diversos tipos que foram
estudados até aqui são convertidos em true ou false.
*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    cout << "A)" << endl;
    char c1 = 'A', c2 = '0', c3 = '\n', c4 = '\t', c5 = '\0';

    cout << "Conversao de caracteres para bool" << endl;
    cout << "c1 = " << c1 << " - " << bool(c1) << endl;
    cout << "c2 = " << c2 << " - " << bool(c2) << endl;
    cout << "c3 = "
         << "\\n"
         << " - " << bool(c3) << endl;
    cout << "c4 = "
         << "\\t"
         << " - " << bool(c4) << endl;
    cout << "c5 = "
         << "\\0"
         << " - " << bool(c5) << endl; // Falso pois \0 tamb�m � lido como null, ou seja, vazio.

    int i1 = 0, i2 = 1, i3 = -1, i4 = 100, i5 = -100;

    cout << "Conversao de inteiros para bool" << endl;
    cout << "i1 = " << i1 << " - " << bool(i1) << endl;
    cout << "i2 = " << i2 << " - " << bool(i2) << endl;
    cout << "i3 = " << i3 << " - " << bool(i3) << endl;
    cout << "i4 = " << i4 << " - " << bool(i4) << endl;
    cout << "i5 = " << i5 << " - " << bool(i5) << endl;

    float f1 = 0.0, f2 = 1.0, f3 = -1.0, f4 = 0.0001, f5 = -0.000001;

    cout << "Conversao de float para bool" << endl;
    cout << "f1 = " << f1 << " - " << bool(f1) << endl;
    cout << "f2 = " << f2 << " - " << bool(f2) << endl;
    cout << "f3 = " << f3 << " - " << bool(f3) << endl;
    cout << "f4 = " << f4 << " - " << bool(f4) << endl;
    cout << "f5 = " << f5 << " - " << bool(f5) << endl;

    double d1 = 0.0, d2 = 1.0, d3 = -1.0, d4 = 0.0001, d5 = -0.00000000000000000000001;

    cout << "Conversao de double para bool" << endl;
    cout << "d1 = " << d1 << " - " << bool(d1) << endl;
    cout << "d2 = " << d2 << " - " << bool(d2) << endl;
    cout << "d3 = " << d3 << " - " << bool(d3) << endl;
    cout << "d4 = " << d4 << " - " << bool(d4) << endl;
    cout << "d5 = " << d5 << " - " << bool(d5) << endl;

    return 0;
}
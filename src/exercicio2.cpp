#include <iostream>
#include <string>
#include <locale>
#include <cwchar>

using namespace std;

/*
Os caracteres numéricos aparecem na tabela ASCII, e em outras, numa
sequência que começa pelo caractere ‘0’ até o caractere ‘9’. As variáveis de
tipo caractere podem ser tratadas também como valores numéricos. Com
base nestas afirmações desenvolva um programa em C++ que:
a. Imprima na tela, utilizando cout, cada um dos caracteres numéricos
e seu correspondente código numérico. Como modificar o
comportamento do cout para imprimir um objeto de tipo char como
caractere e como número?
‘0’ - 48
i.
Exemplo:
‘1’ - 49
…
‘9’ - 57
b. Modifique o exercício anterior para que a saída imprima também o
código numérico em octal e em hexadecimal.
c. Acrescente ao código do exercício anterior a possibilidade de ler um
caractere qualquer e imprima no mesmo formato do inciso anterior.
d. Pesquise como fazer para armazenar uma variável os caracteres
especiais ‘ç’ e ‘ã’. Acrescente no código do exercício anterior um
exemplo que demonstra como usar este recurso.
*/

int main(void)
{
    // setlocale(LC_ALL, "Portuguese_Brazil");

    char caracter = '0';
    cout << "A)" << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;
    cout << caracter << " - " << int(caracter++) << endl;

    cout << "B)" << endl;
    caracter = '0';
    cout << "Carac"
         << "\tASCII"
         << "\tOctal"
         << "\tHexa" << endl;
    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;

    cout << caracter << "\t"
         << dec << int(caracter) << "\t0"
         << oct << int(caracter) << "\t0x"
         << hex << int(caracter++) << endl;


    cout << "C)" << endl;

    cout << "Digite um caracter: ";
    cin >> caracter;

    cout << "Carac"
         << "\tASCII"
         << "\tOctal"
         << "\tHexa" << endl;

    wcout << caracter << "\t"
          << dec << (int)caracter << "\t0"
          << oct << int(caracter) << "\t0x"
          << hex << int(caracter) << endl;

    cout << "D)" << endl;
    /*Para ler caracteres especiais é preciso ir nas configuraçõeses do UTF-8
        pesquisar por "Iso" e escolher a opção "Weastern ISO-8859-1" e reiniciar o vs code.
        após isso trocasse o  tipo da variavel de char para wchar_t, pois o char não suporta caracteres especiais.
        Agora o codigo abaixo funciona para caracteres especiais e normais.
    */
    wchar_t specialCaracter;

    cout << "Digite um caracter especial: ";
    wcin >> specialCaracter;

    cout << "Carac"
         << "\tASCII"
         << "\tOctal"
         << "\tHexa" << endl;

    wcout << specialCaracter << "\t"
          << dec <<(int)specialCaracter << "\t0"
          << oct << int(specialCaracter) << "\t0x"
          << hex << int(specialCaracter) << endl;

    return 0;
}
#include <iostream>

using namespace std;
/*
Escreva uma função que codifica uma string em um código secreto. A regra secreta de codificação é extremamente simples: 
substitui cada letra pela letra seguinte (Z é codificado como A). Por exemplo, “Estruturas de Dados” se transformaria em
“Ftusvuvsbt ef Ebept”. Escreva uma função para codificar e uma para decodificar
cadeias segundo este código. Suas funções devem escrever a string produzida em uma string diferente da fornecida como entrada.
*/

string codifica(string str);
string decodifica(string str);


int main(void){
    string str, strCodificada, strDecodificada;

    cout << "Digite uma string: ";
    getline(cin, str);

    strCodificada = codifica(str);
    cout << "\nString codificada: " << strCodificada << endl;

    strDecodificada = decodifica(strCodificada);
    cout << "\nString decodificada: " << strDecodificada << endl;

    return 0;
}

string codifica(string str){
    string strCodificada;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'z'){
            strCodificada += 'a';
        }
        else if(str[i] == 'Z'){
            strCodificada += 'A';
        }
        else if(str[i] == ' '){
            strCodificada += ' ';
        }
        else{
            strCodificada += str[i] + 1;
        }
    }

    return strCodificada;
}

string decodifica(string str){
    string strDecodificada;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            strDecodificada += 'z';
        }
        else if(str[i] == 'A'){
            strDecodificada += 'Z';
        }
        else if(str[i] == ' '){
            strDecodificada += ' ';
        }
        else{
            strDecodificada += str[i] - 1;
        }
    }

    return strDecodificada;
}
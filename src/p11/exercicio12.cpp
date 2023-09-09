#include <iostream>

using namespace std;
/*
Escreva uma função que receba duas strings A e B por parâmetro e retorne uma
terceira string C com os caracteres que aparecem tanto em A quanto em B. O
tamanho das string A e B pode ser diferente.
*/

string intersectString(string strA, string strB);

int main(void){
    string strA, strB, strC;

    cout << "Digite a primeira string: ";
    cin >> strA;

    cout << "Digite a segunda string: ";
    cin >> strB;

    
    strC = intersectString(strA, strB);
    
    cout << "String C: " << strC << endl;

    return 0;
}

string intersectString(string strA, string strB){
    string strC;

    for(int i = 0; strA[i] != '\0'; i++){
        for(int j = 0; strB[j] != '\0'; j++){
            if(strA[i] == strB[j]){
                strC += strA[i];
            }
        }
    }

    return strC;
}
#include <iostream>
#include <wchar.h>
#include <locale.h>

using namespace std;

int main(void){
    //setlocale(LC_ALL, "pt_BR.UTF-8");
    //locale::global(locale("pt_BR.UTF-8"));
    wcout.imbue(locale("pt_BR.UTF-8"));
    char c = '0';
    wchar_t wc;

    cout << "\tDec\tHex\tOct\n";
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c++ << '\t' << '\n';
    cout << "'" << c <<"' -\t" << dec << (int)c << '\t' << hex << (int)c << '\t' << oct << (int)c << '\t' << '\n';


    cout << "Digite um caractere char: ";
    wcin >> wc;

    wcout << "'" << wc <<"' -\t" << dec << (int)wc << '\t' << hex << (int)wc << '\t' << oct << (int)wc << '\t' << '\n';

    return 0;
}
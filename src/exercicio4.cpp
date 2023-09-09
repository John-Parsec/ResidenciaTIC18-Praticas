#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

/*
Durante a aula foram apresentados o tipo de dados double e suas
variações, que permitem representar um subconjunto dos números reais.
Sobre estes tipos de dados crie uma aplicação que:
a. Sobre o tipo float identifique qual o menor e o maior valor que
pode ser representado por uma variável deste tipo. Mostre esta
informação na tela.
b. Crie uma variável pif de tipo float e atribua a ela o valor da
constante pi com o maior número de casas decimais que você consiga
achar na Internet. Imprima este valor na tela.
c. Explore as formas de formatar a saída com o comando cout e
modifique a quantidade de casas decimais que são apresentadas para
2, 4, 8 e 16.
d. Crie uma variável pid de tipo double e atribua a ela o valor da
constante pi com o maior número de casas decimais que você consiga
achar na Internet. Imprima este valor na tela.
e. Identifique se existe alguma diferença entre o valor pif e pid quando
seus valores são impressos com cout utilizando 2, 4, 8 e 16 casas
decimais
f. No seu sistema existe diferença entre o tipo double e long double?
Mostre seu achado com algum exemplo dentro do seu código.
*/

int main(){
    float pif = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912;
    double pid = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912;
    
    cout << "Limite superior do tipo >float< : " << numeric_limits<float>::max() << endl;
    cout << "Limite inferior do tipo >float< : " << numeric_limits<float>::min() << endl;
    
    cout << fixed;
    cout << "\nValor de pif (2 casas decimais): " << setprecision(2) << pif << endl;
    cout << "Valor de pid (2 casas decimais): " << setprecision(2) << pid << endl;    
    cout << "Valor de pif (4 casas decimais): " << setprecision(4) << pif << endl;
    cout << "Valor de pid (4 casas decimais): " << setprecision(4) << pid << endl;
    cout << "Valor de pif (8 casas decimais): " << setprecision(8) << pif << endl;
    cout << "Valor de pid (8 casas decimais): " << setprecision(8) << pid << endl;
    cout << "Valor de pif (16 casas decimais): " << setprecision(16) << pif << endl;
    cout << "Valor de pid (16 casas decimais): " << setprecision(16) << pid << endl;
    // o pid se aproxima mais do valor dado para PI, tendo mudança so no ultimo digito de impressao


    cout << "\nValor de pid: " << setprecision(60) << pid << endl;

    cout << "\ntamanho double: "<< sizeof(double) << " | " << "tamanho long double: "<< sizeof(long double) << endl;
    // no meu sistema o longo double e o double nao tem o mesmo tamanho
    // double 8 bytes, long double 16 bytes
    cout << scientific ;
    cout << "limite inferior double: "<<numeric_limits<double>::min() << " | " << "limite superior double: "<< numeric_limits<double>::max() << endl;
    cout << "limite inferior long double: "<< numeric_limits<long double>::min() << " | " << "limite superior long double: "<< numeric_limits<long double>::max() << endl;
    // os limites inferiores e superiores tambem foram diferentes
    // double: [2.225073858507201383090232717332404064219215980462331830553327e-308 - 1.797693134862315708145274237317043567980705675258449965989175e+308]
    // long double [3.362103143112093506262677817321752602598079344846471240108827e-4932 - 1.189731495357231765021263853030970205169063322294624200440324e+4932]

    
    return 0;
}
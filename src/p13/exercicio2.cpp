#include <iostream>

using namespace std;

/*
Crie um tipo estruturado (struct) empregado para armazenar dados (nome,
sobrenome, ano de nascimento, RG, ano de admissão, salário) de empregados de
uma empresa. Defina um vetor de empregados para armazenar até 50 empregados.
Faça uma função chamada “Reajusta_dez_porcento( )” que receba por parâmetro o
vetor de empregados e a quantidade de elementos no vetor e atualize o salário de
cada empregado em 10%. Crie uma função main para testar a função.
*/

struct empregado{
    string nome;
    string sobrenome;
    int ano_nascimento;
    string RG;
    int ano_admissao;
    float salario;
};

void geraDados(empregado *empregados, int n){
    for(int i = 0; i < n; i++){
        empregados[i].nome = "Nome " + to_string(i);
        empregados[i].sobrenome = "Sobrenome " + to_string(i);
        empregados[i].ano_nascimento = 2000 + i;
        empregados[i].RG = "RG " + to_string(i);
        empregados[i].ano_admissao = 2010 + i;
        empregados[i].salario = 1000 + (i*100);
    }
}


void reajustaDezPorcento(empregado *empregados, int n){
    for(int i = 0; i < n; i++){
        empregados[i].salario *= 1.1;
    }
}

void imprimeEmpregados(empregado *empregados, int n){
    for(int i = 0; i < n; i++){
        cout << "Nome: " << empregados[i].nome << endl;
        cout << "Sobrenome: " << empregados[i].sobrenome << endl;
        cout << "Ano de nascimento: " << empregados[i].ano_nascimento << endl;
        cout << "RG: " << empregados[i].RG << endl;
        cout << "Ano de admissao: " << empregados[i].ano_admissao << endl;
        cout << "Salario: " << empregados[i].salario << endl;
        cout << endl;
    }
}  


int main(void){
    empregado empregados[50];
    int qtdeEmpregados = 25;

    geraDados(empregados, qtdeEmpregados);

    imprimeEmpregados(empregados, qtdeEmpregados);

    cout << "\n----------Reajustando salarios em 10%----------\n" << endl;

    reajustaDezPorcento(empregados, qtdeEmpregados);

    imprimeEmpregados(empregados, qtdeEmpregados);

    return 0;
}
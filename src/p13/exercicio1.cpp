#include <iostream>
#include <vector>

using namespace std;
/*
Uma empresa de ônibus faz diariamente 5 viagens de ida e 5 viagens de volta entre
as cidades do Rio de Janeiro e São Paulo. Cada ônibus tem 40 assentos para serem
preenchidos por passageiros. A empresa costuma vender as passagens
antecipadamente, e para cada passagem vendida é anotado o número do assento, a
data e hora, o CPF, o nome e a idade do passageiro. As passagens são vendidas por
80 reais cada.
Faça um programa para gerenciar a venda de passagens de ônibus. O programa deve
possibilitar obter as seguintes informações:
1. Qual o total arrecadado para uma determinada viagem.
2. Qual o total arrecadado em um determinado mês.
3. Qual o nome do passageiro de uma determinada poltrona P de uma
determinada viagem.
4. Qual o horário de viagem mais rentável.
5. Qual a média de idade dos passageiros.
*/


struct hora{
    int hora;
    int minuto;
};

struct date{
    int dia;
    int mes;
    int ano;
};

struct viagem{
    short int tipo = 0; // 0 = ida, 1 = volta
    date data_viagem;
    hora horario;
    float preco = 80;
    int nmr_assento;
    struct{
        bool ocupada = false;
        string cpf;
        string nome;
        int idade;
    } poltronas[40];
};

float totalArrecadadoViagem(viagem v);
float totalArrecadadoMes(vector<viagem> vs, int mes);
string nomePassageiro(viagem v, int poltrona);
hora horarioMaisRentavel(vector<viagem> vs);
float mediaIdadePassageiros(vector<viagem> vs);
void cadastrarViagem(vector<viagem> &vs, int tipo, date data, hora horario);
int cadastroDeViagem(vector<viagem> &vIda, vector<viagem> &vVolta, int &qtdeViagensIda, int &qtdeViagensVolta);
void venderPassagem(viagem &v, int poltrona, string cpf, string nome, int idade);
void venderPassagem(viagem &v, int poltrona, string cpf, string nome, int idade);
int informacoes(int qst, vector<viagem> vIda, vector<viagem> vVolta);
int menu(vector<viagem> &vIda, vector<viagem> &vVolta, int &qtdeViagensIda, int &qtdeViagensVolta);


int main(void){
    int result;
    int qtdeViagensIda = 5, qtdeViagensVolta = 5;
    vector<viagem> viagensIda;
    vector<viagem> viagensVolta;

    do{
        result = menu(viagensIda, viagensVolta, qtdeViagensIda, qtdeViagensVolta);
    }while(result != 0);

    return 0;
}


// 1. Qual o total arrecadado para uma determinada viagem.
float totalArrecadadoViagem(viagem v){
    float total = 0;
    for(int i = 0; i < 40; i++){
        if(v.poltronas[i].ocupada){
            total += v.preco;
        }
    }
    return total;
}

// 2. Qual o total arrecadado em um determinado mês.
float totalArrecadadoMes(vector<viagem> vs, int mes){
    float total = 0;
    for(auto it = vs.begin(); it != vs.end(); it++){
        if(it->data_viagem.mes == mes){
            total += totalArrecadadoViagem(*it);
        }

    }
    return total;
}

// 3. Qual o nome do passageiro de uma determinada poltrona P de uma
string nomePassageiro(viagem v, int poltrona){
    return v.poltronas[poltrona-1].nome;
}

// 4. Qual o horário de viagem mais rentável.
hora horarioMaisRentavel(vector<viagem> vs){
    hora h;
    int total = 0;
    for(auto it = vs.begin(); it != vs.end(); it++){
        if(totalArrecadadoViagem(*it) > total){
            total = totalArrecadadoViagem(*it);
            h = it->horario;
        }
    }
    return h;
}   

// 5. Qual a média de idade dos passageiros.
float mediaIdadePassageiros(vector<viagem> vs){
    float total = 0;
    int nmr_passageiros = 0;
    for(auto it = vs.begin(); it != vs.end(); it++){
        for(int i = 0; i < 40; i++){
            if(it->poltronas[i].ocupada){
                total += it->poltronas[i].idade;
                nmr_passageiros++;
            }
        }
    }

    return total/nmr_passageiros;
}

void cadastrarViagem(vector<viagem> &vs, int tipo, date data, hora horario){
    viagem v;
    v.tipo = tipo;
    v.data_viagem = data;
    v.horario = horario;
    vs.push_back(v);
}

int cadastroDeViagem(vector<viagem> &vIda, vector<viagem> &vVolta, int &qtdeViagensIda, int &qtdeViagensVolta){
    int tipo;
    date data;
    hora horario;

    cout << "Tipo de viagem (0 = ida, 1 = volta): ";
    cin >> tipo;
    cout << "Data da viagem (dd/mm/aaaa): ";
    cin >> data.dia >> data.mes >> data.ano;
    cout << "Horário da viagem (hh:mm): ";
    cin >> horario.hora >> horario.minuto;

    if(tipo == 0){
        if(qtdeViagensIda == 0){
            cout << "Número máximo de viagens de ida atingido" << endl;
            return -1;
        }

        cadastrarViagem(vIda, tipo, data, horario);
    }
    else if (tipo == 1){
        if(qtdeViagensVolta == 0){
            cout << "Número máximo de viagens de volta atingido" << endl;
            return -1;
        }

        cadastrarViagem(vVolta, tipo, data, horario);
    }
    else{
        cout << "Tipo de viagem inválido" << endl;
        return -1;
    }

    return 1;
}

void venderPassagem(viagem &v, int poltrona, string cpf, string nome, int idade){
    v.poltronas[poltrona-1].ocupada = true;
    v.poltronas[poltrona-1].cpf = cpf;
    v.poltronas[poltrona-1].nome = nome;
    v.poltronas[poltrona-1].idade = idade;
}

int vendaDePassagem(vector<viagem> &vIda, vector<viagem> &vVolta){
    int tipo, poltrona, idade, viagemId;
    int i = 1;
    string cpf, nome;
    cout << "Tipo de viagem (0 = ida, 1 = volta): ";
    cin >> tipo;

    if(tipo == 0){
        cout << "Viagens de ida disponíveis: " << endl;
        for(auto it = vIda.begin(); it != vIda.end(); it++){
            cout << i++ << " - " << it->data_viagem.dia << "/" << it->data_viagem.mes << "/" << it->data_viagem.ano << " - " << it->horario.hora << ":" << it->horario.minuto << endl;
        }
        cout << "Número da viagem: ";
        cin >> viagemId;
    }
    else if (tipo == 1){
        cout << "Viagens de volta disponíveis: " << endl;
        for(auto it = vVolta.begin(); it != vVolta.end(); it++){
            cout << i++ << " - " << it->data_viagem.dia << "/" << it->data_viagem.mes << "/" << it->data_viagem.ano << " - " << it->horario.hora << ":" << it->horario.minuto << endl;
        }
        cout << "Número da viagem: ";
        cin >> viagemId;
    }
    else{
        cout << "Tipo de viagem inválido" << endl;
        return -1;
    }
    
    viagemId--;

    cout << "Número da poltrona: ";
    cin >> poltrona;
    cout << "CPF: ";cout << "Total arrecadado para uma determinada viagem" << endl;
    cin >> cpf;
    cout << "Nome: ";
    cin >> nome;
    cout << "Idade: ";
    cin >> idade;

    if(tipo == 0){
        venderPassagem(vIda[viagemId], poltrona, cpf, nome, idade);
    }
    else if (tipo == 1){
        venderPassagem(vVolta[viagemId], poltrona, cpf, nome, idade);
    }

    return 1;
}

int informacoes(int qst, vector<viagem> vIda, vector<viagem> vVolta){
    int tipo, mes, viagemId, poltrona;
    hora h;
    int i = 1;

    if(qst == 1){
        cout << "Qual o tipo de viagem (0 = ida, 1 = volta)? ";
        cin >> tipo;

        if(tipo != 0 && tipo != 1){
            cout << "Tipo de viagem inválido" << endl;
            return -1;
        }

        cout << "Qual a viagem? " << endl;
        for(auto it = vIda.begin(); it != vIda.end(); it++){
            cout << i++ << " - " << it->data_viagem.dia << "/" << it->data_viagem.mes << "/" << it->data_viagem.ano << " - " << it->horario.hora << ":" << it->horario.minuto << endl;
        }

        cin >> viagemId;

        cout << "Total arrecadado: " << totalArrecadadoViagem(vIda[viagemId-1]) << endl;
    }
    else if(qst == 2){
        cout << "Qual o mês? ";
        cin >> mes;

        cout << "Total arrecadado: " << totalArrecadadoMes(vIda, mes) + totalArrecadadoMes(vVolta, mes) << endl;
    }
    else if(qst == 3){
        cout << "Qual o tipo de viagem (0 = ida, 1 = volta)? ";
        cin >> tipo;

        if(tipo != 0 && tipo != 1){
            cout << "Tipo de viagem inválido" << endl;
            return -1;
        }

        cout << "Qual a viagem? " << endl;
        for(auto it = vIda.begin(); it != vIda.end(); it++){
            cout << i++ << " - " << it->data_viagem.dia << "/" << it->data_viagem.mes << "/" << it->data_viagem.ano << " - " << it->horario.hora << ":" << it->horario.minuto << endl;
        }

        cin >> viagemId;

        cout << "Qual a poltrona? ";
        cin >> poltrona;

        cout << "Nome do passageiro: " << nomePassageiro(vIda[viagemId-1], poltrona) << endl;
    }
    else if(qst == 4){
        cout << "Qual o tipo de viagem (0 = ida, 1 = volta)? ";
        cin >> tipo;

        if(tipo == 0)
            h = horarioMaisRentavel(vIda);
        else if (tipo == 1)
            h = horarioMaisRentavel(vVolta);
        else{
            cout << "Tipo de viagem inválido" << endl;
            return -1;
        }

        cout << "Horário da viagem mais rentável: " << h.hora << ":" << h.minuto << endl;
    }
    else if(qst == 5){
        cout << "Média de idade dos passageiros: " << mediaIdadePassageiros(vIda) + mediaIdadePassageiros(vVolta) << endl;
    }

    return 1;
}


int menu(vector<viagem> &vIda, vector<viagem> &vVolta, int &qtdeViagensIda, int &qtdeViagensVolta){
    short int opt;

    cout << "1. Cadastrar viagem" << endl;
    cout << "2. Vender passagem" << endl;
    cout << "3. Total arrecadado para uma determinada viagem" << endl;
    cout << "4. Total arrecadado em um determinado mês" << endl;
    cout << "5. Nome do passageiro de uma determinada poltrona P de uma determinada viagem" << endl;
    cout << "6. Horário de viagem mais rentável" << endl;
    cout << "7. Média de idade dos passageiros" << endl;
    cout << "0. Sair" << endl;
    cout << "\nOpção: ";
    cin >> opt;

    switch(opt){
        case 0:
            return 0;
        case 1:
            return cadastroDeViagem(vIda, vVolta, qtdeViagensIda, qtdeViagensVolta);
        case 2:
            return vendaDePassagem(vIda, vVolta);
        case 3:
            return informacoes(1, vIda, vVolta);
        case 4:
            return informacoes(2, vIda, vVolta);
        case 5:
            return informacoes(3, vIda, vVolta);
        case 6:
            return informacoes(4, vIda, vVolta);
        case 7:
            return informacoes(5, vIda, vVolta);
    }

    return 1;
}

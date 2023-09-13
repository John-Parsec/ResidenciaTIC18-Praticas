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

int main(void){




    return 0;
}
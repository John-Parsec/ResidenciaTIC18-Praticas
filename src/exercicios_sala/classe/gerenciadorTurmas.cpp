#include <bits/stdc++.h>

using namespace std;

class Aluno{
    private:
        string nome;
        string matricula;
        vector<vector<float>> notas;
    public:
        Aluno(string nome, string matricula){
            this->nome = nome;
            this->matricula = matricula;
        }

        string getNome(){
            return this->nome;
        }

        string getMatricula(){
            return this->matricula;
        }

        int getIndexByName(string nome){
            for(int i = 0; i < this->notas.size(); i++){
                if(this->notas[i][0] == nome){
                    return i;
                }
            }
            return -1;
        }

        

        void addNotas(int index, float nota1, float nota2){
            vector<float> notas;
            notas.push_back(nota1);
            notas.push_back(nota2);
            this->notas.insert(this->notas.begin() + index, notas);
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setMatricula(string matricula){
            this->matricula = matricula;
        }

        string toString(){
            return this->nome + " " + this->matricula;
        }
};

class gerenciadorTurmas{
    private:


    public:



};
#include <bits/stdc++.h>

using namespace std;

class Estado{
    private:
        string nome;
        string sigla;
    public:
        Estado(string nome = "", string sigla = ""){
            this->nome = nome;
            this->sigla = sigla;
        }

        string getNome(){
            return this->nome;
        }
        
        string getSigla(){
            return this->sigla;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setSigla(string sigla){
            this->sigla = sigla;
        }
};

class Cidade{
    private:
        string nome;
        Estado *estado;
    public:
        string getNome(){
            return this->nome;
        }

        Estado getEstado(){
            return this->estado->getNome();
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setEstado(Estado *estado){
            this->estado = estado;
        }
};

int main(void){

    vector<Estado> estados;
    vector<Cidade> cidades;

    estados.push_back(Estado("Bahia", "BA"));
    estados.push_back(Estado("Pernambuco", "PE"));
    estados.push_back(Estado("Minas Gerais", "MG"));

    for(int i = 0; i < 2; i++){
        Cidade cidade;
        string nome;
        string sigla;

        cout << "Digite o nome da cidade: ";
        cin >> nome;
        cidade.setNome(nome);

        cout << "Digite a sigla do estado: ";
        cin >> sigla;

        for(int j = 0; j < estados.size(); j++){
            if(estados[j].getSigla() == sigla){
                cidade.setEstado(&estados[j]);
                break;
            }
        }

        cidades.push_back(cidade);
    }

    for(int i = 0; i < cidades.size(); i++){
        cout << "Cidade: " << cidades[i].getNome() << endl;

        // Estado estado = cidades[i].getEstado();
        // cout << "Estado: " << estado.getNome() << endl;
        
        cout << "Estado: " << cidades[i].getEstado().getNome() << endl;
        
    }


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

class BancoDeDados{
    private:
        string nomeArquivo;
        fstream arquivo;
    public:
        static void salvarDados(vector<string> dados){
            ofstream arquivo;
            arquivo.open("dados.txt");
            for(auto dado : dados){
                arquivo << dado << endl;
            }
            arquivo.close();
        }

        static vector<string> recuperarDados(){
            vector<string> dados;
            ifstream arquivo;
            arquivo.open("dados.txt");
            string dado;
            while(getline(arquivo, dado)){
                dados.push_back(dado);
            }
            arquivo.close();
            return dados;
        }
};

int main(){
    vector<string> dados = {"Teste1", "Teste2", "Teste3"};
    BancoDeDados::salvarDados(dados);
    
    vector<string> dadosRecuperados = BancoDeDados::recuperarDados();
    for(auto dado : dadosRecuperados){
        cout << dado << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;

/*
Faça um programa para um supermercado para a consulta de preço de produtos. O
programa deverá armazenar de cada produto o seu código, seu nome e seu preço.
Ao utilizar o programa o usuário deve poder:
1. Inserir um novo produto
2. Excluir um produto cadastrado
3. Listar todos os produtos com seus respectivos códigos e preços
4. Consultar o preço de um produto através de seu código.
O código deve ser formado de uma string numérica de 13 caracteres
O nome deve ter um tamanho de no máximo 20 caracteres
O preço deve ter duas casas decimais
O sistema deve permitir o cadastro de até 300 produtos diferentes.
O sistema deve controlar para que não tenha produtos com o mesmo código ou
mesmo nome, não permitindo o seu cadastro.
O sistema deverá ser feito modularizados, com qualidade e utilizando estrutura na
sua implementação.
*/

struct produto{
    string codigo;
    char nome[21];
    float preco;
};

void geraDados(vector<produto> &produtos, int n);
void inserirProduto(vector<produto> &produtos);
void excluirProduto(vector<produto> &produtos);
void listarProdutos(vector<produto> &produtos);
void consultarPreco(vector<produto> &produtos);
void menu(vector<produto> produtos);
void geradorDeDados(vector<produto> &produtos);
string geraCodigo(int n);
bool verCodigoUnico(vector<produto> &produtos, string codigo);
bool verNomeUnico(vector<produto> &produtos, string nome);


int main(void){
    srand(time(NULL));

    vector<produto> produtos;

    menu(produtos);

    return 0;
}

void menu(vector<produto> produtos){
    int opt;

    do{
        cout << endl;
        cout << "----------Menu----------" << endl;
        cout << "1 - Inserir produto" << endl;
        cout << "2 - Excluir produto" << endl;
        cout << "3 - Listar produtos" << endl;
        cout << "4 - Consultar preco" << endl;
        cout << "5 - Gerar dados" << endl; // Para testes
        cout << "0 - Sair" << endl;
        cout << "Digite uma opcao: ";
        cin >> opt;
        cout << endl;

        switch(opt){
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                inserirProduto(produtos);
                break;
            case 2:
                excluirProduto(produtos);
                break;
            case 3:
                listarProdutos(produtos);
                break;
            case 4:
                consultarPreco(produtos);
                break;
            case 5:
                geradorDeDados(produtos);
                break;
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
    }while (opt != 0);        
}

void inserirProduto(vector<produto> &produtos){
    if(produtos.size() == 300){
        cout << "Nao e possivel inserir mais produtos" << endl;
        return;
    }

    produto p;
    cout << "Digite o nome do produto: ";
    cin >> p.nome;

    if(!verNomeUnico(produtos, p.nome)){
        cout << "Produto ja cadastrado" << endl;
        return;
    }

    cout << "Digite o preco do produto: ";
    cin >> p.preco;

    cout << "Digite o codigo do produto: ";
    cin >> p.codigo;

    if(!verCodigoUnico(produtos, p.codigo)){
        cout << "Codigo ja cadastrado" << endl;
        return;
    }
    
    produtos.push_back(p);
}

void excluirProduto(vector<produto> &produtos){
    string codigo;

    cout << "Digite o codigo do produto a ser excluido: ";
    cin >> codigo;

    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].codigo == codigo){
            produtos.erase(produtos.begin() + i);
            cout << "Produto excluido com sucesso" << endl;
            return;
        }
    }
    cout << "Produto nao encontrado" << endl;
}

void listarProdutos(vector<produto> &produtos){
    cout << "Produtos cadastrados:" << endl;
    cout << "Nome\t\tPreco\t\tCodigo" << endl;
    for(int i = 0; i < produtos.size(); i++){
        cout << produtos[i].nome << "\t" << setprecision(2) << produtos[i].preco << "\t\t" << produtos[i].codigo << endl;
    }
    
    cout << endl;
}

void consultarPreco(vector<produto> &produtos){
    string codigo;

    cout << "Digite o codigo do produto a ser consultado: ";
    cin >> codigo;

    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].codigo == codigo){
            cout << "Preco do produto: " << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }
    cout << "Produto nao encontrado" << endl;
}

bool verCodigoUnico(vector<produto> &produtos, string codigo){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].codigo == codigo){
            return false;
        }
    }
    return true;
}

bool verNomeUnico(vector<produto> &produtos, string nome){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].nome == nome){
            return false;
        }
    }
    return true;
}

string geraCodigo(int n){
    char cd[n+1];
    
    for(int i = 0; i < n; i++){
        cd[i] = '0' + (rand() % 10);
    }
    cd[n] = '\0';

    string codigo(cd);
    return codigo;    
}

void geradorDeDados(vector<produto> &produtos){
    int total;

    cout << "Quantos dados deseja gerar?" << endl;
    cin >> total;

    geraDados(produtos, total);
}

void geraDados(vector<produto> &produtos, int n){
    
    string nome;

    for(int i = 0; i < n; i++){
        if(produtos.size() == 300){
            cout << "Nao e possivel inserir mais produtos" << endl;
            return;
        }

        produto p;
        
        do{
            p.codigo = geraCodigo(13);

        }while(!verCodigoUnico(produtos, p.codigo));

        p.preco = ((float)rand()/RAND_MAX);
        p.preco += ((float)rand()/RAND_MAX) * 100.0;

        nome = "Produto " + to_string(i+1);
        strcpy(p.nome, nome.c_str());

        produtos.push_back(p);
    }
}

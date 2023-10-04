#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Ponto{
    private:
        float x, y, z;
    public:
        static float distancia(Ponto p1, Ponto p2){
            float dist = sqrt(pow((p1.get_x() - p2.get_x()), 2) + pow((p1.get_y() - p2.get_y()), 2) + pow((p1.get_z() - p2.get_z()), 2));
            return dist;
        }

        float get_x(){
            return this->x;
        }
        
        float get_y(){
            return this->y;
        }

        float get_z(){
            return this->z;
        }

        void le_ponto(){
            cout << "Digite as coordenadas (x y z): ";
            cin >> this->x >> this->y >> this->z;
        }

        void escreve_ponto(){
            cout << "(" << this->x << ", " << this->y << ", " << this->z <<")";
        }

        float distancia(Ponto p1){
            float dist = sqrt(pow((p1.get_x() - this->x), 2) + pow((p1.get_y() - this->y), 2) + pow((p1.get_z() - this->z), 2));
            return dist;
        }

        Ponto operator+(Ponto p1){
            Ponto p;
            p.x = this->x + p1.get_x();
            p.y = this->y + p1.get_y();
            p.z = this->z + p1.get_z();
            return p;
        }

        bool operator==(Ponto p1){
            if(this->x == p1.get_x() && this->y == p1.get_y() && this->z == p1.get_z()){
                return true;
            } else {
                return false;
            }
        }

        bool operator!=(Ponto p1){
            if(this->x != p1.get_x() || this->y != p1.get_y() || this->z != p1.get_z()){
                return true;
            } else {
                return false;
            }
        }

        void operator=(Ponto p1){
            this->x = p1.get_x();
            this->y = p1.get_y();
            this->z = p1.get_z();
        }
};

class Poligono{
    private:
        vector<Ponto> pontos;
    public:
        Ponto getPonto(int i){
            return this->pontos[i];
        }

        void le_pontos(){
            cout << "Criando um poligono!" << endl;
            char sn;
            do{
                Ponto p;
                p.le_ponto();
                pontos.push_back(p);
                cout << "Deseja inserir mais pontos (s/n): ";
                cin >> sn;
            } while(sn != 'n');
        }

        void lista_pontos(){
            cout << "As coordenadas digitadas foram: " << endl;
            for(Ponto p : pontos){
                cout << "(" << p.get_x() << ", " << p.get_y() << ")" << endl;
            }
        }

        float perimetro(){
            float per = 0;
            vector<Ponto>::iterator it2;
            Ponto p1;
            Ponto p2;

            for(auto it = pontos.begin(); it != pontos.end()-1; it++){
                it2 = it;
                advance(it2, 1);
                p1 = *it;
                p2 = *it2;
                per += p1.distancia(p2);
            }

            it2 = pontos.begin();
            p1 = *it2;
            per += p1.distancia(p2);
            
            return per;
        }

        void operator=(Poligono p1){
            this->pontos = p1.pontos;
        }

        bool operator==(Poligono p1){
            for(int i = 0; i < this->pontos.size(); i++){
                if(this->pontos[i] != p1.pontos[i]){
                    return false;
                }
                return true;
            }
        }

        Poligono operator+(Poligono p1){
            Poligono poli;
            Ponto p;

            if(this->pontos.size() != p1.pontos.size()){
                return poli;
            }

            for(int i = 0; i < p1.pontos.size(); i++){
                p = this->pontos[i]+p1.pontos[i];
                poli.pontos.push_back(p);
            }

            return poli;
        }
};

int main(void){
    Poligono poli;

    poli.le_pontos();

    poli.lista_pontos();

    cout << endl << "Perimetro calculado: " << poli.perimetro() << endl;
}
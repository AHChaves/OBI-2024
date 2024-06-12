#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Amigo{

    public:
        int cod;
        int tempo;

        Amigo(int cod, int tempo) {
            this->cod = cod;
            this->tempo = tempo;
        }

        void SomaTempo(int time){
            this->tempo += time;
        }

};

int main(){

    string entrada;
    char tipo;
    vector<Amigo*> *amg = new vector<Amigo*>();
    int nRep, i, cod;

    cin >> nRep;

    fflush(stdin);

    for(i=0; i <nRep; i++){
        getline(cin, entrada);
        tipo = entrada[0];
        cod = stoi(entrada.substr(2));

        Amigo* temp= new Amigo(cod, 0);
        amg->push_back(temp);

        

    }



    return 0;
}
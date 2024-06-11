#include <iostream>
#include <regex>

using namespace std;

void RegSearch(vector<string> &copas, vector<string> &espadas, vector<string> &ouro, vector<string> &paus, string naipe){
    regex reg(R"(\d{2}[CEUP])");
    smatch matches;

    while(regex_search(naipe, matches, reg)){
        
        string carta = matches.str(0);

        if((carta[0] == '1' and carta[1] <= '3') or (carta[0] == '0' and carta[1] <= '9')){

            char tipo = carta[2];

            switch (tipo)
            {
            case 'C':
                copas.push_back(carta);
                break;
            case 'E':
                espadas.push_back(carta);
                break;
            case 'U':
                ouro.push_back(carta);
                break;
            case 'P':
                paus.push_back(carta);
                break;
            }
        }
        else
            return;
        naipe = matches.suffix().str();
    }

}

bool Search_Irregularities(vector<string> vetor){

    int i = 0;

    for (string carta : vetor){
        for(int j = vetor.size()-1; j > i; j--){
            if(carta == vetor[j]) 
                return true;
        }
        i++;
    }

    return false;
}

void Impressao(vector<string> vetor, bool error){

    int missing = (13 - vetor.size());

    if(error)
        cout << "error" << endl;
    else
        cout << missing << endl;
}


int main(){

    string naipe;
    vector<string> copas;
    vector<string> espadas;
    vector<string> ouro;
    vector<string> paus;
    vector<bool> error(4, false);

    cin >> naipe;

    if(naipe.size() >= 3 or naipe.size() <= 156){
        
        RegSearch(copas, espadas, ouro, paus, naipe);

        error.at(0) = Search_Irregularities(copas);
        error.at(1) = Search_Irregularities(espadas);
        error.at(2) = Search_Irregularities(ouro);
        error.at(3) =  Search_Irregularities(paus);
    
        Impressao(copas, error.at(0));
        Impressao(espadas, error.at(1));
        Impressao(ouro, error.at(2));
        Impressao(paus, error.at(3));

        return 0;
    }

    return 0;
}
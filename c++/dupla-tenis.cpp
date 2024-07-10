#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){

    vector<int> amigos;
    int diferenca_menor = INT_MAX;

    for(int i = 0; i < 4; i++){
        int habilidade;
        cin >> habilidade;
        amigos.push_back(habilidade);
    }

    for(int i = 1, j = (amigos.size() - 2); i < amigos.size(), j >= 0; i++, j--){

        int sum1 = amigos.at(0) + amigos.at(i);
        int sum2;

        if(i == amigos.size() -1)
            sum2 = amigos.at(i-1) + amigos.at(j+1);
        else
            sum2 = amigos.at(3) + amigos.at(j);

        int sub = sum2 - sum1; 

        if(sub <0)
            sub *= -1;

        if(sub < diferenca_menor)
            diferenca_menor = sub;

    }

    cout << diferenca_menor;


    return 0;
}
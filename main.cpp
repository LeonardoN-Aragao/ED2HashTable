#include <iostream>
#include <fstream>
#include "TabelaHash.h"

using namespace std;

int main(int arg, char * args){

    fstream file;
    string name = to_string(args[1]);
    file.open(name);

    int tam;
    int inseridos;
    int sondagem;

    if(file.is_open()){
        
        string data;

        //Tamanho da tabela hash
        getline(file,data, ' ');
        tam = stoi(data);
        
        //Numero de chaves que serao lidas
        getline(file,data, ' ');
        inseridos = stoi(data);

        //Tipo de Sondagem (1 para linear e 2 para dupla)
        getline(file,data);
        sondagem = stoi(data);

        TabelaHash tabela(tam, sondagem);
        
        for(int i = 0 ; i < inseridos; i++){
            getline(file,data);
            tabela.add(stoi(data));
        }

        file.close();
    }
    else{
        cout<<"Erro ao abrir arquivo!";
        return;
    }
}
#include <iostream>

using namespace std;

class TabelaHash{

    public:
        int tamanho;
        int * tabela;
        int sondagem;

        int funcHash(int chave){
            return chave % tamanho;
        }

        int funcHash2(int chave){
            return 1 + (chave % (tamanho-1));
        }

        int linear(int chave, int iteracoes){
            return (funcHash(chave) + iteracoes) % tamanho;
        }

        int dupla(int chave, int iteracoes){
            return funcHash(chave) + (iteracoes * funcHash2(chave)) % tamanho;
        }

        TabelaHash(int tam, int sond){
            tamanho = tam;
            tabela = new int[tamanho];

            for(int i = 0; i<tamanho; i++){
                tabela[i] = -1;
            }

            sondagem = sond;
        }

        ~TabelaHash(){
            delete tabela;
        }

        int search(int chave, int iteracoes){
            int resposta = -1;
            
            for(int i = 0; i < iteracoes; i++){
                int resposta;
                
                if(sondagem == 1)
                    resposta = linear(chave,i);
                else
                    resposta = dupla(chave,i);

                if (resposta == chave || resposta == -1)
                    break;
            }

            return resposta;
        }

        void add(int chave){
                
            for(int i = 0; i < tamanho; i++){
               
                int pos = (funcHash(chave)+i) % tamanho;

                if(tabela[pos] == -1){
                    tabela[funcHash(chave)] = chave;
                }
            }
        }
};
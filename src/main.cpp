#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <locale.h>
#include "Instancia.h"
#include "Solucao.h"
#include "Avaliador.h"
#include "Menu.h"
#include "HeuristicasConstrutivas.h"
#include "BuscasLocais.h"


using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "portuguese");

    Instancia inst;
    Solucao sol;
    float fo; 
    char* nomeArq = argv[1];

    int op, hc, bl;
    do
    {
        op = menuPrincipal();
        switch (op)
        {
            case 1:
            { 
                bool sucesso = leInstancia(inst, nomeArq);

                if(sucesso)
                    printf("\nArquivo carregado com sucesso!\n");
                else
                    printf("\nFalha ao carregar arquivo '%s'\n", nomeArq);

                
            }    
            break;
            case 2: 
                hc = menuHeuristicaConstrutiva();
                switch (hc)
                {                 
                    case 1:
                        cout<< "  ---- VMP --- " <<endl;
                        sol = VizinhoMaisProximo(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 2:
                        cout << " ---- IMB ---- " <<endl;
                        sol = InsercaoMaisBarata(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 3:
                        cout << " ---- Randômico ---- " <<endl;
                        sol = Randomica(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 4:

                    break;
                    case 5:

                    break;                
                    default:
                        cout << "Opção inválida" <<endl;
                    break;
                }
            break;
            case 3:
                bl = menuBuscaLocal();
                switch (bl)
                {
                    case 1:
                         cout<<" Busca Local Troca (BI)" <<endl;
                    break;
                
                    default:
                        cout<< "Opção Inválida" << endl;
                    break;
                }    
            break;
            case 0:
                cout << "Até a próxima!!!" << endl;
            break;
            default:
                printf("Algo deu errado!\n");
            break;
        }
    }while(op != 0);

    return 0; 
}

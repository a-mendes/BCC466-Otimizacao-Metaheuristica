#ifndef HEURISTICASCONSTRUTIVAS_H
#define HEURISTICASCONSTRUTIVAS_H

#include <set>
#include <algorithm>
#include <random>
#include <cfloat>

#include "Instancia.h"
#include "Solucao.h"

using namespace std;

//retorno o ID do candidato com melhor avaliacao
int melhorCandidato(Instancia& inst, set<int>& C, int idUltimo);
Solucao VizinhoMaisProximo(Instancia& inst);

//retorna o melhor custo, além de atualizar as variaveis id e pos com os melhores valores
float melhorCandidatoIMB(Instancia& inst, set<int>& C,Solucao& sol,int& id,int& pos);
Solucao InsercaoMaisBarata(Instancia& inst);

//construção randômica
Solucao Randomica(Instancia& inst);

#endif /*HEURISTICASCONSTRUTIVAS_H*/
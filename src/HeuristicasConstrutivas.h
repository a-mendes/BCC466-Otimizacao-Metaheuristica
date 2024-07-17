#ifndef HEURISTICASCONSTRUTIVAS_H
#define HEURISTICASCONSTRUTIVAS_H

#include <set>

#include "Instancia.h"
#include "Solucao.h"

using namespace std;

//retorno o ID do candidato com melhor avaliacao
int melhorCandidato(Instancia& inst, set<int>& C, int idUltimo);
Solucao VizinhoMaisProximo(Instancia& inst);
Solucao InsercaoMaisBarata(Instancia& inst);

#endif /*HEURISTICASCONSTRUTIVAS_H*/
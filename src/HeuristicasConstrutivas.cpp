#include "HeuristicasConstrutivas.h"

int melhorCandidato(Instancia& inst, set<int>& C, int idUltimo)
{
    int idMelhor;
    float custoMelhor = MAXFLOAT;
    set<int>::iterator it;
    for(it = C.begin(); it != C.end(); it++)
    {
        if( inst.distancia[idUltimo][*(it)] < custoMelhor)
        {
            custoMelhor = inst.distancia[idUltimo][*(it)];
            idMelhor = *it;
        }
    }

    return idMelhor;
}

Solucao VizinhoMaisProximo(Instancia& inst)
{
    Solucao sol;
    //criando minha lista de candidatos
    set<int> C;
    //inicializando minha lista de candidatos
    for(int i = 1; i < inst.n; i++)
    {
        C.insert(i);
    }
    sol.push_back(0); //adicionando a cidade origem do Caixeiro
 
    while(! C.empty())
    {
        int id = melhorCandidato(inst, C, sol.at(sol.size()-1));
        sol.push_back(id);
        C.erase(id);
    }
 
    return sol;
}

float melhorCandidatoIMB(Instancia& inst, set<int>& C,Solucao& sol,int& id,int& pos)
{
    float custoMelhor = MAXFLOAT, custo;   
    for(int i = 0; i < sol.size(); i++)
    {   int proxCidade = i+1;
        if(i+1 == sol.size())//ultima posição
        {
            proxCidade = 0;
        }
        set<int>::iterator it;
        for(it = C.begin(); it != C.end(); it++)
        {
            custo = inst.distancia[sol.at(i)][*(it)]+inst.distancia[*(it)][sol.at(proxCidade)] - inst.distancia[sol.at(i)][sol.at(proxCidade)];
            if( custo < custoMelhor)
            {
                custoMelhor = custo;
                id = *it;
                pos = i+1;
            }
        }
    }
    return custoMelhor;
}


Solucao InsercaoMaisBarata(Instancia& inst)
{
    //variaveis que controlam o id da cidade ser inserida e sua posição
    int id, pos;
    //variavel que controla o valor da FO
    float fo = 0;
    //criando uma solução vazia
    Solucao sol;
    //criando uma lista de candidatos
    set<int> C;
    //inicializando minha lista de cadidatos
    for(int i = 2; i < inst.n; i++)
    {
        C.insert(i);
    }
    //inicializando minha solução com a cidade origem e a cidade 1
    sol.push_back(0);
    sol.push_back(1);
    //atualizando a FO
    fo = inst.distancia[sol.at(0)][sol.at(1)]+inst.distancia[sol.at(1)][sol.at(0)];
    while( ! C.empty())
    {
        fo+=melhorCandidatoIMB(inst, C, sol, id, pos);
        sol.insert(sol.begin()+pos, id);
        C.erase(id);
    }

    printf("\nFO calculada: %.2f\n", fo);

    return sol;

}


Solucao Randomica(Instancia& inst)
{
    Solucao sol;

    for(int i = 0; i < inst.n; i++)
    {
        sol.push_back(i);
    }
    
    random_shuffle(sol.begin(), sol.end());

    return sol;

}
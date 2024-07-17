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

Solucao InsercaoMaisBarata(Instancia& inst){

    Solucao s;

    //criando minha lista de candidatos
    set<int> lc;

    //inicializando minha lista de candidatos
    for(int i = 3; i < inst.n; i++)
        lc.insert(i);

    //Rota inicial envolvendo 3 cidades
    //Método: inserir as 3 primeiras cidades da instancia na solução.
    s.push_back(0);
    s.push_back(1);    
    s.push_back(2);

    for(int k = 0; k < lc.size(); k++){
        float melhorDistancia = MAXFLOAT;
        int melhorPosicao = 0;

        for(int i = 0, j + 1; i < s.size() - 1; i++){
            //dik + dkj − dij
            float distancia = 
                inst.distancia[s.at(i)][lc.at(k)] + 
                inst.distancia[lc.at(k)][s.at(j)] - 
                inst.distancia[s.at(i)][s.at(j)];

            if(distancia < melhorDistancia){
                melhorCandidato = i+1;
                melhorDistancia = distancia;
            }
        }

        s.insert(melhorPosicao, lc.at(k))
    }

}
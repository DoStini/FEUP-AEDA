#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
vector<CKart> CGrupo::ordenaKarts()
{
	vector<CKart> vord;
	for(CPista & pista : pistasG){
	    vector<CKart> & ref = pista.getFrotaActual();
	    vord.insert(vord.begin(), ref.begin(), ref.end());
	}

	sort(vord.begin(),
         vord.end(),
         [](CKart & k1, CKart & k2){
	            return k1.getNumero() < k2.getNumero();
	    });

	return vord;
    
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    vector<CKart> vord;
    for(CPista & pista : pistasG){
        vector<CKart> ref = pista.getKartsAvariados();
        vord.insert(vord.begin(), ref.begin(), ref.end());
    }

    return count_if(vord.begin(),
                    vord.end(),
                    [cilind](CKart & k1){
                        return (int)k1.getCilindrada() == cilind;
                    });
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    vector<CKart> karts;
    for(auto k1 : frotaKartsPista){
        int num = k1.getNumero();
        if( !k1.getAvariado() &&
            (int)k1.getCilindrada() == cilind &&
            find_if(this->kartsEmProva.begin(),
                    this->kartsEmProva.end(),
                    [num](CKart k2){return num == k2.getNumero();}) == this->kartsEmProva.end())
            karts.push_back(k1);

    }

    if(karts.size() < numeroKarts) {
        for(auto & kart : karts) kartsLinhaPartida.push(kart);
        return false;
    }

    for (int i = 0; i < numeroKarts; ++i) {
        kartsLinhaPartida.push(karts[i]);
    }

    return true;
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    int counter = 0;
    while (!kartsLinhaPartida.empty()) {
        counter++;
        CKart car = kartsLinhaPartida.front();
        kartsEmProva.push_back(car);
        kartsLinhaPartida.pop();
    }
    return counter;
}


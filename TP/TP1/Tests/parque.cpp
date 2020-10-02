#include "parque.h"
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Equals{
public:
    explicit Equals(T val){comp = val;}
    bool operator()(InfoCartao val){
        return val.nome == comp;
    }
private:
    T comp;
};


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli) {
    this->vagas = lot;
}

unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}




int ParqueEstacionamento::posicaoCliente(const string& nome) const{

    Equals<string> eq(nome);

    auto it = std::find_if(clientes.begin(), clientes.end(), eq);

    return it == clientes.end() ? -1 : it - clientes.begin();


    int out = -1;

    for(int i = 0; i < clientes.size(); i++){
        if(clientes[i].nome == nome) {
            out = i;
            break;
        }
    }
    return out;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){

    if (clientes.size() >= numMaximoClientes || posicaoCliente(nome) != -1) return false;
    InfoCartao cartao;
    cartao.nome = nome;
    cartao.presente = false;
    clientes.push_back(cartao);
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome){
    int pos = posicaoCliente(nome);

    if(vagas == 0 ||
        pos == -1 ||
        clientes[pos].presente) return false;

    clientes[pos].presente = true;
    vagas--;
    return true;

}

bool ParqueEstacionamento::sair(const string & nome){

    int pos = posicaoCliente(nome);

    if(pos == -1 ||
        !clientes[pos].presente) return false;

    clientes[pos].presente = false;
    vagas++;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome){
    int pos = posicaoCliente(nome);

    if(pos == -1 ||
       clientes[pos].presente) return false;

    clientes.erase(clientes.begin() + pos);
    return true;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao - vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}
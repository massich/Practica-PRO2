#include "sala.hh"
#include <iostream>
using namespace std;


void imprimir_string(string a) {
    if (a.empty()) cout << "NULL";
    else cout << a;
}

Sala::Sala(int m, int n) {
    Matrix A(m,Row(n));
    estanteria = A;
}

void Sala::poner_items(string p, int quant) {
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j].empty()){
                estanteria[i][j] = p;
                --quant;
            }
            if(quant == 0){
                i = estanteria.size();
                j = estanteria[0].size();
            }  
        }
    }
    if(quant != 0) cout << quant << endl;      
}

void Sala::quitar_items(string p, int quant) {
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j] == p){
                estanteria[i][j].clear();
                --quant;
            }
            if(quant == 0){
                i = estanteria.size();
                j = estanteria[0].size();
            }  
        }
    }
    if(quant != 0) cout << quant << endl;      
}

void Sala::consul_pos(int m,int n) const {
    imprimir_string(estanteria[m][n]);
}
//falta afegir que escrigui els continguts i la quantitat
void Sala::escribir_sala() const{
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); j++){
            if(j == estanteria[0].size() - 1) {
                imprimir_string(estanteria[i][j]);
            }else{
                imprimir_string(estanteria[i][j]);
                cout << " ";
            }
        }
        cout << endl;
    }
}

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
//faltara incloure l'error a la funcio del main.
void Sala::redimensionar(int m, int n){
    Matrix nova(m,Row(n));
    int x = nova.size() - 1;
    int y = 0;
    for(int i = estanteria.size() - 1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j) {
            if(not estanteria[i][j].empty()) {
                nova[x][y] = estanteria[i][j];
                ++y;
                if( y == nova[0].size()){
                    --x;
                    y = 0;
                }
            }
        }
    }
    estanteria = nova;
}

void Sala::compactar() {
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            int x = i;
            int y = j;
            while(estanteria[i][j].empty() and x >= 0) {
                ++y;
                if(y == estanteria[0].size() and x == 0) --x; 
                else if(y == estanteria[0].size()){
                    --x;
                    y = 0;
                    estanteria[i][j] = estanteria[x][y];
                    estanteria[x][y].clear(); 
                }
                else {
                    estanteria[i][j] = estanteria[x][y];
                    estanteria[x][y].clear(); 
                }
            }
        }
    }
}

void Sala::poner_items(string p, int quant) {
    int total = quant; 
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j].empty()){
                estanteria[i][j] = p;
                --quant;
            }
            if(quant == 0){
                i = -1;
                j = estanteria[0].size();
            }  
        }
    }
    if(quant != 0) cout << quant << endl;      
    total -= quant;
    sumar_stock(p,total);
}

void Sala::quitar_items(string p, int quant) {
    int total = quant;
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j] == p){
                estanteria[i][j].clear();
                --quant;
            }
            if(quant == 0){
                i = -1;
                j = estanteria[0].size();
            }  
        }
    }
    if(quant != 0) cout << quant << endl;
    total -= quant;
    restar_stock(p,total);      
}

void Sala::sumar_stock(string p, int quant) {
    stock[p] += quant;
}

void Sala::restar_stock(string p, int quant) {
    stock[p] -= quant;
}

void Sala::consultar_pos(int m,int n) const {
    imprimir_string(estanteria[m-1][n-1]);
}

int Sala::capacitat_actual() const{
    int cap = 0;
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); j++){
            if(not estanteria[i][j].empty()){
                cap++;
            }
        }
    }
    return cap;
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
    cout << endl;
    for (map<string,int>::const_iterator it=stock.begin(); it!=stock.end(); ++it) {
        cout << it->first << " " << it ->second << endl;
    }
}

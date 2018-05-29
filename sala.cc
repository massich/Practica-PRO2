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

void Sala::reorganizar() {
    int x = estanteria.size() - 1;
    int y = 0;
    for (map<string,int>::const_iterator it=stock_sala.begin(); it!=stock_sala.end(); ++it) {
        int rep = 0;
        while(rep < (it->second)){
            estanteria[x][y] = it->first;
            ++y;
            if(y == estanteria[0].size()){
                --x;
                y = 0;
            }
            ++rep; 
        }
    }   
}

int Sala::poner_items(string p, int quant) {
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
    total -= quant;
    sumar_stock(p,total);
    return quant;
}

int Sala::quitar_items(string p, int quant) {
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
    total -= quant;
    restar_stock(p,total);  
    return quant;    
}

void Sala::sumar_stock(string p, int quant) {
    stock_sala[p] += quant;
}

void Sala::restar_stock(string p, int quant) {
    stock_sala[p] -= quant;
}

void Sala::consultar_pos(int m,int n) const {
    cout << "  ";
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

void Sala::escribir() const{
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); j++){
            if(j == estanteria[0].size() - 1) {
                imprimir_string(estanteria[i][j]);
            }
            else if(j == 0){
                cout << "  ";
                imprimir_string(estanteria[i][j]);
                cout << " ";
            }
            else{
                imprimir_string(estanteria[i][j]);
                cout << " ";
            }
        }
        cout << endl;
    }
    int total = 0;
    for (map<string,int>::const_iterator it1=stock_sala.begin(); it1!=stock_sala.end(); ++it1) {
        total += it1->second;
    }
    cout << "  " << total << endl;
    for (map<string,int>::const_iterator it2=stock_sala.begin(); it2!=stock_sala.end(); ++it2) {
        cout << "  " << it2->first << " " << it2 ->second << endl;
    }
}

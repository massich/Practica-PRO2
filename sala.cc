/** @file sala.cc
    @brief Implementación de la clase sala.
*/

#include "sala.hh"
#include <iostream>
using namespace std;


void imprimir_string(string a) {
    //esta funcion imprime "NULL si la posición está vacía o el contenido si hay alguno"
    if (a.empty()) cout << "NULL";
    else cout << a;
}

Sala::Sala(int m, int n) {
    Matrix A(m,Row(n));
    estanteria = A;
}

void Sala::redimensionar(int m, int n){
    //Creamos una nuevaa matriz llamada nova y recorremos la estanteria.
    //siempre que encontremos un producto en una posicion de la estanteria lo copiaremos en la posición actual de nova.
    //Seguidamente avanzaremos una posicion de nova
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
    //Rrecorremos la estanteria, y si encontramos un vacio entramos en el bucle
    // en el bucle vamos avanzando posiciones hasta encontrar una con contenido
    //luego asignamos el contenido a la posicion original de la estanteria y hacemos un clear de la posicion actual
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            int x = i;
            int y = j;
            while(x >= 0 and estanteria[i][j].empty()) {
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
    //Reccorremos el stock de la sala con un iterador
    //entramos en un bucle donde vamos guardando el producto que señala el iterador en la estanteria
    // hasta que guardamos tantas unidades como hay en stock, para eso sirve el int rep, que cuenta las veces
    //que hemos colocado el producto
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
    //Recorremos la estanteria y vamos colocando productos en los sitios vacios.
    //ademas vamos restando a la cantidad inicial quant cada vez que colocamos un producto
    //al final añadimos la cantidad que se ha colocado en el stock 
    int total = quant; 
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j].empty()){
                estanteria[i][j] = p;
                --quant;
            }
            if(quant <= 0){
                i = -1;
                j = estanteria[0].size();
            }  
        }
    }      
    if(quant >= 0)total -= quant;
    if(total > 0)sumar_stock(p,total);
    return quant;
}

int Sala::quitar_items(string p, int quant) {
    //Recorremos la estanteria y cada vez que encontramos un producto p hacemos clear de la posicion
    //ademas vamos restando a la cantidad inicial quant cada vez que borramos un producto
    //al final restamos la cantidad que se ha borrado del stock 
    int total = quant;
    for(int i = estanteria.size()-1; i >= 0; --i){
        for(int j = 0; j < estanteria[0].size(); ++j){
            if(estanteria[i][j] == p){
                estanteria[i][j].clear();
                --quant;
            }
            if(quant <= 0){
                i = -1;
                j = estanteria[0].size();
            }  
        }
    }
    if(quant >= 0)total -= quant;
    if(total > 0)restar_stock(p,total);  
    return quant;    
}

void Sala::sumar_stock(string p, int quant) {
    //suma de unidades de p al stock
    stock_sala[p] += quant;
}

void Sala::restar_stock(string p, int quant) {
    //resta unidades de p al stock
    stock_sala[p] -= quant;
}

void Sala::consultar_pos(int m,int n) const {
    //imprime el string en la posicion indicada de la estanteria
    cout << "  ";
    imprimir_string(estanteria[m-1][n-1]);
    cout << endl;
}

int Sala::capacitat_actual() const{
    //Recorremos la estanteria y por cada posicion no vacia que encontramos
    //sumamos uno a cap, al final la funcion devuelve cap, que es la cantidad total de productos
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
    //Recorremos la estanteria y vamos imprimendo el contenido de cada posicion
    //hay varios ifs porque dependiendo de la posicion el espaciado es diferente
    for(int i = 0; i < estanteria.size(); ++i){
        for(int j = 0; j < estanteria[0].size(); j++){
            if( j!=0 and j == estanteria[0].size() - 1) {
                imprimir_string(estanteria[i][j]);
            }
            else if( j == 0 and estanteria[0].size() == 1) {
                cout << "  ";
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

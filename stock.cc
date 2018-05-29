/** @file stock.cc
    @brief Implementación de la clase stock.
*/

#include "stock.hh" 
#include <iostream>
using namespace std;



void Stock::poner_prod(string id){
    //Busca el producto en el stock, si lo encuentra imprime error
    //si no lo encunetra lo añade con 0 unidades 
    map<string,int>::iterator it;
    it = stock.find(id);
    if(it != stock.end()) cout << "  error" << endl;
    else stock[id] = 0;
}

void Stock::sumar_stock(string p, int quant) {
    //suma de unidades de p al stock
    if(quant > 0)stock[p] += quant;
}

void Stock::restar_stock(string p, int quant) {
    //resta unidades de p al stock
    if(quant > 0)stock[p] -= quant;
}

int Stock::comprobar_prod(string id) const {
    //comprueba si el producto esta en stock, si no lo está devuelve 0, si lo está devuelve 1
    return stock.count(id);
}

void Stock::consultar_prod(string id) const {
    //busca un producto en el stock, si no lo encuentra imprime error.
    //Si lo encuentra imprime las unidades totales de ese producto.
    map<string,int>::const_iterator it;
    it = stock.find(id);
    if(it != stock.end()) cout << "  " << it->second << endl;
    else cout << "  error" << endl;
}

void Stock::inventario() const{
    //Recorre todo el stock e imprime todos los productos y sus unidades
    for (map<string,int>::const_iterator it=stock.begin(); it!=stock.end(); ++it) {
        cout << "  " << it->first << " " << it ->second << endl;
    }
}

void Stock::quitar_prod(string id) {
    //Busca el producto en el stock, si lo encuentra y tiene 0 unidades lo borra del stock.
    //En cualquier otro caso imprime error.
    map<string,int>::iterator it;
    it = stock.find(id);
    if(it != stock.end() and it->second == 0) stock.erase (it);
    else cout << "  error" << endl;
}
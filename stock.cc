#include "stock.hh" 
#include <iostream>
using namespace std;



void Stock::poner_prod(string id){
    map<string,int>::iterator it;
    it = stock.find(id);
    if(it != stock.end()) cout << "  error" << endl;
    else stock[id] = 0;
}

void Stock::sumar_stock(string p, int quant) {
    stock[p] += quant;
}

void Stock::restar_stock(string p, int quant) {
    stock[p] -= quant;
}

void Stock::consultar_prod(string id) const {
    map<string,int>::const_iterator it;
    it = stock.find(id);
    if(it != stock.end()) cout << "  " << it->second << endl;
    else cout << "  error" << endl;
}

void Stock::inventario() const{
    for (map<string,int>::const_iterator it=stock.begin(); it!=stock.end(); ++it) {
        cout << "  " << it->first << " " << it ->second << endl;
    }
}

void Stock::quitar_prod(string id) {
    map<string,int>::iterator it;
    it = stock.find(id);
    if(it != stock.end() and it->second == 0) stock.erase (it);
    else cout << "  error" << endl;
}
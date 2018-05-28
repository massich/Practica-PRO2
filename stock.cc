#include "stock.hh" 
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

void consultar_prod(string id) const {
    map<string,int>::iterator it;
    it = stock.find(id);
    if(it != stock.end()) cout << "  " << it->second << endl;
    else cout << "  error" << endl;
}
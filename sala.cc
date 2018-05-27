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

void Sala::consul_pos(int m,int n) const {
    imprimir_string(estanteria[m][n]);
}

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

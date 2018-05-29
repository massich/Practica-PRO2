/** @file almacen.cc
    @brief Implementación de la clase almacen.
*/

#include "almacen.hh"
#include <iostream>
using namespace std;


Almacen::Almacen(int n) {
	estructura();
	vector<Sala> salas;
	while(0 < n) {
		int x,y;
		cin >> x >> y;
		Sala A(x,y);
		salas.push_back(A);
		--n;
	}
	V = salas;
}

void Almacen::redimensionar(int id_sala,int m, int n) {
	V[id_sala-1].redimensionar(m,n);
}

void Almacen::compactar(int id_sala) {
	V[id_sala-1].compactar();
}

void Almacen::reorganizar(int id_sala) {
	V[id_sala-1].reorganizar();
}

int Almacen::poner_items(int id_sala,std::string p, int quant) {
	return V[id_sala-1].poner_items(p,quant);
}

int Almacen::quitar_items(int id_sala,std::string p, int quant) {
	return V[id_sala-1].quitar_items(p,quant);
}

int Almacen::distribuir_almacen(BinTree <int> A, string& p, int quant) {
	if(A.empty()) return quant;
	else {
		int esq,dre;
		int root = A.value(); 
		int total = poner_items(root,p,quant);
		if(total == 0) return 0;
		else if(total%2 == 0) {
			esq = distribuir_almacen(A.left(), p, (total/2));
			dre = distribuir_almacen(A.right(), p, (total/2));
		}
		else {
			esq = distribuir_almacen(A.left(), p, ((total/2)+1));
			dre = distribuir_almacen(A.right(), p, (total/2));
		}
		return esq + dre;
	}
}

int Almacen::distribuir(string& p, int quant){
	return distribuir_almacen(T,p,quant);
}

void Almacen::consultar_pos(int id_sala, int m, int n) {
	V[id_sala-1].consultar_pos(m,n);
}

int Almacen::capacitat_actual(int id_sala) const {
	return V[id_sala-1].capacitat_actual();
}


void Almacen::escribir(int id_sala) const{
	V[id_sala-1].escribir();
}

void Almacen::read_bintree_int(BinTree<int>& a) {
  int x;
  cin >> x;
  if (x!=0){
	BinTree<int> l;
	read_bintree_int(l);
	BinTree<int> r;
	read_bintree_int(r);
	a=BinTree<int>(x,l,r);
  }
}

void Almacen::estructura() {
	read_bintree_int(T);
} 
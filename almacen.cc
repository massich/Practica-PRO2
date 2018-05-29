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

void Almacen::poner_items (int id_sala,std::string p, int quant) {
	V[id_sala-1].poner_items(p,quant);
}

void Almacen::quitar_items (int id_sala,std::string p, int quant) {
	V[id_sala-1].quitar_items(p,quant);
}

//void Almacen::distribuir(BinTree <int> A, std::string p, int quant) {
	//int esq,dre;
	//int root = A.value();

//}

void Almacen::consultar_pos(int id_sala, int m, int n) {
	V[id_sala-1].consultar_pos(m,n);
}

void Almacen::escribir(int id_sala) {
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
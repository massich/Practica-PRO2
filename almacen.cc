#include "almacen.hh"

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
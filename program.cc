  /**
   * @mainpage Función main de la pràctica TreeKEA.

En este proyecto se representa un almacén, con sus respectivas salas. Se introducen las clases "Almacen", "Sala" y "Stock". Además se usa alguna externa como el BInTree.hh.
La clase stock fuciona de inventario general para poder consultar productos y el propio inventario. Además la clase almacen llama siempre a la clase sala para las funciones,
de modo que la estructura del programa se centra en la clase "Sala" y "Stock" principalmente, pues alli es donde estan implementadas las funciones y las funciones de almacen
solo llaman a esas funciones.

*/

/** @file program.cc
    @brief Programa principal para el ejercicio "TreeKEA".
*/

#include "stock.hh"
#include "almacen.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;

int main() {
 int n;
 cin >> n; 
 Almacen magatzem(n);
 Stock sistema;
 string option;
 bool fin = false;
 while(not fin and cin >> option) {
   if(option == "poner_prod"){
     string id_prod;
     cin >> id_prod;
     cout << "poner_prod" << " " << id_prod << endl;
     sistema.poner_prod(id_prod);
   }

   else if(option == "quitar_prod"){
     string id_prod;
     cin >> id_prod;
     cout << "quitar_prod" << " " << id_prod << endl;
     sistema.quitar_prod(id_prod);
   }

   else if(option == "poner_items"){
     int id_sala;
     string id_prod;
     int quant;
     cin >> id_sala >> id_prod >> quant;
     cout << "poner_items" << " " << id_sala << " " << id_prod << " " << quant << endl;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = 0;
       if(quant >= 0)total = quant;
       int aux = magatzem.poner_items(id_sala,id_prod,quant);
       cout << "  " << aux << endl;
       total =   total - aux;
       sistema.sumar_stock(id_prod,total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "quitar_items"){
     int id_sala;
     string id_prod;
     int quant;
     cin >> id_sala >> id_prod >> quant;
     cout << "quitar_items" << " " << id_sala << " " << id_prod << " " << quant << endl;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = 0;
       if(quant >= 0)total = quant;
       int aux = magatzem.quitar_items(id_sala,id_prod,quant);
       cout << "  " << aux << endl;
       total -= aux;
       sistema.restar_stock(id_prod, total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "distribuir"){
     string id_prod;
     int quant;
     cin >> id_prod >> quant;
     cout << "distribuir" << " " << id_prod << " " << quant << endl;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = quant;
       int aux = magatzem.distribuir(id_prod,quant);
       cout << "  " << aux << endl;
       total -= aux;
       sistema.sumar_stock(id_prod, total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "compactar"){
     int id_sala;
     cin >> id_sala;
     cout << "compactar" << " " << id_sala << endl;
     magatzem.compactar(id_sala);
   }

   else if(option == "reorganizar"){
     int id_sala;
     cin >> id_sala;
     cout << "reorganizar" << " " << id_sala << endl;
     magatzem.reorganizar(id_sala);
   }

   else if(option == "redimensionar"){
     int id_sala, fil, col;
     cin >> id_sala >> fil >> col;
     cout << "redimensionar" << " " << id_sala << " " << fil << " " <<  col << endl;
     if((fil*col) < magatzem.capacitat_actual(id_sala)) {
       cout << "  error" << endl;
     }
     else {
       magatzem.redimensionar(id_sala,fil,col);
     }
   }

   else if(option == "inventario"){
     cout << "inventario" << endl;
     sistema.inventario();
   }

   else if(option == "escribir"){
     int id_sala;
     cin >> id_sala;
     cout << "escribir" << " " << id_sala << endl;
     magatzem.escribir(id_sala);
   }

   else if(option == "consultar_pos"){
     int id_sala, fila, col;
     cin >> id_sala >> fila >> col;
     cout << "consultar_pos" << " " << id_sala << " " << fila << " " << col << endl;
     magatzem.consultar_pos(id_sala,fila,col);
   }

   else if(option == "consultar_prod"){
     string id_prod;
     cin >> id_prod;
     cout << "consultar_prod" << " " << id_prod << endl;
     sistema.consultar_prod(id_prod);
   }
   else if(option == "fin"){
     cout << "fin" << endl;
     fin = true;
   }
 }

}

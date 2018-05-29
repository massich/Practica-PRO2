  /**
   * @mainpage Función main de la pràctica TreeKEA.

En este proyecto se representa un almacén, con sus respectivas salas. Se introducen las clases "Almacen", "Sala" y "Producto". Además se usa alguna eterna como el BInTree.hh.
Los productos se meten en una ista de productos dentro de la clase almacen para poder hacer el inventario y poder acceder a cada uno de los productos en todo momento. Además la clase almacen llama siempre a la clase sala para las funciones, de modo que la estructura del programa se centra en el almacen y deriva los trabajos a otras clases dependiendo de lo que se tenga que hacer.

Sólo se documentan elementos públicos
*/

/** @file main.cc
    @brief Programa principal para el ejercicio "TreeKEA".
*/

#include "stock.hh"
#include "sala.hh"
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
     sistema.poner_prod(id_prod);
   }

   else if(option == "quitar_prod"){
     string id_prod;
     cin >> id_prod;
     sistema.quitar_prod(id_prod);
   }

   else if(option == "poner_items"){
     int id_sala;
     string id_prod;
     int quant;
     cin >> id_sala >> id_prod >> quant;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = quant;
       cout << "  " << magatzem.poner_items(id_sala,id_prod,quant) << endl;
       total -= magatzem.poner_items(id_sala,id_prod,quant);
       sistema.sumar_stock(id_prod, total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "quitar_items"){
     int id_sala;
     string id_prod;
     int quant;
     cin >> id_sala >> id_prod >> quant;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = quant;
       cout << "  " << magatzem.quitar_items(id_sala,id_prod,quant) << endl;
       total -= magatzem.quitar_items(id_sala,id_prod,quant);
       sistema.restar_stock(id_prod, total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "distribuir"){
     string id_prod;
     int quant;
     cin >> id_prod >> quant;
     if(sistema.comprobar_prod(id_prod) > 0) {
       int total = quant;
       cout << "  " << magatzem.distribuir(id_prod,quant) << endl;
       total -= magatzem.distribuir(id_prod,quant);
       sistema.sumar_stock(id_prod, total);
     }
     else cout << "  error" << endl;
   }

   else if(option == "compactar"){
     int id_sala;
     cin >> id_sala;
     magatzem.compactar(id_sala);
   }

   else if(option == "reorganizar"){
     int id_sala;
     cin >> id_sala;
     magatzem.reorganizar(id_sala);
   }

   else if(option == "redimensionar"){
     int id_sala, fil, col;
     cin >> id_sala >> fil >> col;
     if(fil*col < magatzem.capacitat_actual(id_sala)) {
       cout << "  error" << endl;
     }
     else {
       magatzem.redimensionar(id_sala,fil,col);
     }
   }

   else if(option == "inventario"){
     sistema.inventario();
   }

   else if(option == "escribir"){
     int id_sala;
     cin >> id_sala;
     magatzem.escribir(id_sala);
   }

   else if(option == "consultar_pos"){
     int id_sala, fila, col;
     cin >> id_sala >> fila >> col;
     magatzem.consultar_pos(id_sala,fila,col);
   }

   else if(option == "consultar_prod"){
     string id_prod;
     cin >> id_prod;
     sistema.consultar_prod(id_prod);
   }
   else if(option == "fin"){
     fin = true;
   }
 }

}

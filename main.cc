  /**
   * @mainpage Función main de la pràctica TreeKEA.

En este proyecto se representa un almacén, con sus respectivas salas. Se introducen las clases "Almacen", "Sala" y "Producto". Además se usa alguna eterna como el BInTree.hh.
Los productos se meten en una ista de productos dentro de la clase almacen para poder hacer el inventario y poder acceder a cada uno de los productos en todo momento. Además la clase almacen llama siempre a la clase sala para las funciones, de modo que la estructura del programa se centra en el almacen y deriva los trabajos a otras clases dependiendo de lo que se tenga que hacer.

Sólo se documentan elementos públicos
*/

/** @file main.cc
    @brief Programa principal para el ejercicio "TreeKEA".
*/

// #include "producto.hh"
// #include "sala.hh"
// #include "almacen.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <list>
#include <vector>
#endif

using namespace std;

int main() {
    string a;
    bool fin = false;
    
    vector<string> Matrix;

    while(fin == false && cin >> a) {
      if(a == "poner_prod") {}
      else if(a == "quitar_prod") {}
      else if(a == "poner_items") {}
      else if(a == "quitar_items") {}
      else if(a == "distribuir") {}
      else if(a == "compactar") {}
      else if(a == "reorganizar") {}
      else if(a == "redimensionar") {}
      else if(a == "inventario") {}
      else if(a == "escribir") {}
      else if(a == "consultar_pos") {}
      else if(a == "consultar_prod") {}
      else if(a == "fin")
        fin = true;
    }
}

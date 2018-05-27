  /**
   * @mainpage Función main de la pràctica TreeKEA.

En este proyecto se representa un almacén, con sus respectivas salas. Se introducen las clases "Almacen", "Sala" y "Producto". Además se usa alguna eterna como el BInTree.hh.
Los productos se meten en una ista de productos dentro de la clase almacen para poder hacer el inventario y poder acceder a cada uno de los productos en todo momento. Además la clase almacen llama siempre a la clase sala para las funciones, de modo que la estructura del programa se centra en el almacen y deriva los trabajos a otras clases dependiendo de lo que se tenga que hacer.

Sólo se documentan elementos públicos
*/

/** @file main.cc
    @brief Programa principal para el ejercicio "TreeKEA".
*/

#include "producto.hh"
#include "sala.hh"
#include "almacen.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <list>
#endif

using namespace std;

int main() {
  Sala n;
  n.escribir_sala();

}

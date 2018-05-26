/** @file almacen.hh
    @brief Especificación de la clase Almacen

*/

#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_

#include "producto.hh"
#include "bintree.hh"
#include "sala.hh" // XXX: change id_sala by sala
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <list>


#endif


typedef std::vector< std::vector<std::string> > Matrix;

/** @class Almacen
    @brief Representa el almacen de una cadena de tiendas.

*/

class Almacen {
public:

  //Modificadoras

  /** @brief Redimensiona la sala con "id_sala" como identificador
      \pre m>0,n>0
      \post llama a la funcion redimensionar de la clase sala para la sala con identifiador "id_sala"
  */
  void redimensionar(int id_sala,int m, int n);

  /** @brief Rellena la estanteria con un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post llama a la funcion poner_items de la clase sala
  */
  void poner_items (int id_sala,Producto p);

  /** @brief Vacia la estanteria de un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post llama a la funcion quitar_items de la clase sala
  */
  void quitar_items (int id_sala,Producto p);

  /** @brief Distribuye una cantidad de un producto por todas las salas
      \pre identificador del producto existe en la lista de productos
      \post Se reparte on el orden del arbol T la cantidad del producto
  */
  void distribuir(Producto p);

  //Consultoras

  /** @brief Consultora del producto en la posicion m,n de la sala con identificador "id_sala"
      \pre <em>cierto</em>
      \post El resultado es el identificador del producto en esa posición
  */
  void consultar_pos(int id_sala) const;

   /** @brief Consultora de unidades totales de producto
      \pre <em>cierto</em>
      \post El resultado es eel numero de unidades del producto con identificador "id_prod"
  */
  void consultar_prod(int id_prod) const;

  //Escritura de sala

  /** @brief Operación de escritura de sala con identificador "id_sala"
      \pre <em>cierto</em>
      \post Llama a la funcion escribir de la clase Sala
  */
  void escribir_sala(int id_sala) const;

  //Escritura de inventario

  /** @brief Operación de escritura de inventario
      \pre <em>cierto</em>
      \post Escribe para cada producto su identificador y su nombre de unidades
  */
  void inventario() const;



private:
  list <Producto> Productos;
  int salas;
  BinTree <int> T;
  std::vector<Sala> V;


};

#endif

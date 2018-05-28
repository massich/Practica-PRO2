/** @file almacen.hh
    @brief Especificación de la clase Almacen

*/

#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_


#include "sala.hh" // XXX: change id_sala by sala
#ifndef NO_DIAGRAM
#include <vector>
#include "bintree.hh"
#include <string>
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

  /** @brief Compacta la estanteria de la sala con "id_sala" como identificador
      \pre id_sala == cierto
      \post llama a la funcion compactar de la clase sala para la sala con identifiador "id_sala"
  */
  void compactar(int id_sala);

  /** @brief Reorganiza la estanteria de la sala con "id_sala" como identificador
      \pre id sala == cierto
      \post llama a la funcion reorganizar de la clase sala para la sala con identifiador "id_sala"
  */
  void reorganizar(int id_sala);

  /** @brief Rellena la estanteria con un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post llama a la funcion poner_items de la clase sala
  */
  void poner_items (int id_sala,std::string p, int quant);

  /** @brief Vacia la estanteria de un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post llama a la funcion quitar_items de la clase sala
  */
  void quitar_items (int id_sala,std::string p, int quant);

  /** @brief Distribuye una cantidad de un producto por todas las salas
      \pre identificador del producto existe en la lista de productos
      \post Se reparte on el orden del arbol T la cantidad del producto
  */
  void distribuir(std::string p, int quant);

  //Consultoras

  /** @brief Consultora del producto en la posicion m,n de la sala con identificador "id_sala"
      \pre <em>cierto</em>
      \post El resultado es el identificador del producto en esa posición
  */
  void consultar_pos(int id_sala) const;

  //Escritura de sala

  /** @brief Operación de escritura de sala con identificador "id_sala"
      \pre <em>cierto</em>
      \post Llama a la funcion escribir de la clase Sala
  */
  void escribir(int id_sala) const;

 //Lectura de arbol sacada de BinTreeIOint

  /** @brief Operación de lectura de un arbol binario de enteros
      \pre a esta vacio; el canal estandar de entrada contiene el recorrido en preorden de un arbol binario A de enteros 
      \post a = A 
  */
  void read_bintree_int(BinTree<int>& a);

private:
  int salas;
  BinTree <int> T;
  std::vector<Sala> V;


};

#endif

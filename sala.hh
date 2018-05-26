/** @file sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_HH_
#define _SALA_HH_

#include "producto.hh"
#ifndef NO_DIAGRAM
#include <vector>
#include <string>

#endif


typedef vector< vector<string> > Matrix; 

/** @class Sala
    @brief Representa una sala del almacen. 

*/

class Sala {
public:
  /** @brief Creadora con valores concretos. 

      \pre m>0,n>0 y id_sala>0
      \post El resultado es una sala con identifcador de sala "id_sala" y estanteria "estant" de tamaño mxn.  
  */   
  Sala(Matrix estant(m,vector <string> (n)), int id_sala);
  
  //Modificadoras

  /** @brief Redimensiona la sala
      \pre m>0,n>0
      \post El parámetro implícito pasa a tener estanteria "estant de tamaño mxn si aun caben todos los productos
  */
  void redimensionar(int m, int n);
  
  /** @brief Compacta la estanteria
      \pre m>0,n>0
      \post La estanteria no tiene ningun espacio vacío "NULL" entre productos y se mantiene el orden relativo  
  */
  void compactar ();
  
  /** @brief Reorganiza la estanteria
      \pre m>0,n>0
      \post La estanteria queda ordenada por orden alfbético de los identificadores de los productos
  */
  void reorganizar ();
  
  /** @brief Rellena la estanteria con un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post Se llenan los espacios vacíos de la estantería en orden con el producto hasta agotar la cantidad de unidades del producto
  */
  void poner_items (Producto p);
  
  /** @brief Vacia la estanteria de un producto específico
      \pre m>0,n>0 y identificador del producto empieza con una letra
      \post Se quita la cantidad indicada de unidades de un producto, o se retiran todos los que se puede y se indica que cantidad no se ha podido quitar por no haber suficientes
  */
  void quitar_items (Producto p);

  //Consultoras

  /** @brief Consultora del producto en la posicion m,n 
      \pre <em>cierto</em>
      \post El resultado es el identificador del producto en esa posición
  */
  string consul_pos() const;
 
  /** @brief Consultora de los espacios vacíos de la estanteria
      \pre <em>cierto</em>
      \post El resultado es el numero de espacios vacíos de la estanteria
  */
  int consul_capacitat_actual() const;
  
  //Escritura de sala

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los elementos de la matriz de arriba a abajo y de izquierda a derecha y cuantas unidades hay de cada producto por orden de identificador
  */
  void escribir_sala() const;
  
  
private:
  Matrix estanteria(m,vector <string> (n))
  int identificador_sala;
};

#endif
  
  
  
/** @file sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_HH_
#define _SALA_HH_

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#include <map>
#endif


typedef std::vector<std::string> Row;
typedef std::vector<Row> Matrix;

/** @class Sala
    @brief Representa una sala del almacen.

*/

class Sala {
public:
  /** @brief Creadora con valores concretos.

      \pre m>0,n>0 y id_sala>0
      \post El resultado es una sala con estanteria de tamaño mxn.
  */
  Sala(int m, int n);

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
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se llenan los espacios vacíos de la estantería en orden con el producto hasta agotar la cantidad de unidades del producto
  */
  int poner_items(std::string p, int quant); // esta función tiene que ser un int para poder usarla en distribuir

  /** @brief Vacia la estanteria de un producto específico
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se quita la cantidad indicada de unidades de un producto, o se retiran todos los que se puede y se indica que cantidad no se ha podido quitar por no haber suficientes
  */
  int quitar_items(std::string p, int quant);

   /** @brief Suma items al stock de la sala
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se suma la cantidad de unidades indicada al total del stock del producto
  */
  void sumar_stock(std::string p, int quant);

  /** @brief Restar items al stock de la sala
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se quita la cantidad indicada de unidades de un producto del total del stock 
  */
  void restar_stock(std::string p, int quant);

  //Consultoras

  /** @brief Consultora del producto en la posicion m,n
      \pre <em>cierto</em>
      \post El resultado es el identificador del producto en esa posición
  */
  void consultar_pos(int m,int n) const;

  /** @brief Consultora de los espacios ocupados de la estanteria
      \pre <em>cierto</em>
      \post El resultado es el numero de espacios ocupados de la estanteria
  */
  int capacitat_actual() const;

  //Escritura de sala

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los elementos de la matriz de arriba a abajo y de izquierda a derecha y cuantas unidades hay de cada producto por orden de identificador
  */
  void escribir() const;


private:
/** @brief Representa la estanteria de la sala. */
  Matrix estanteria;
  /** @brief Representa el inventario de la sala. Se usa para la funcion escribir. */
  std::map<std::string,int>stock_sala;
};

#endif

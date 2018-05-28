/** @file stock.hh
    @brief Especificación de la clase Stock
*/

#ifndef _STOCK_HH_
#define _STOCK_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif


/** @class Stock
    @brief Representa el control de inventario del almacen.

*/

class Stock {

 public:
  //Modificadoras

  /** @brief añadir producto al sistema
      \pre identificador no existe
      \post El resultado es añadir un producto con 0 unidades e identificador "id" a la lista de productos del almacen
  */
  void poner_prod(std::string id);

 /** @brief Suma items al stock
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se suma la cantidad de unidades indicada al total del stock del producto
  */
  void sumar_stock(std::string p, int quant);

  /** @brief Restar items al stock
      \pre identificador del producto empieza con una letra y quant >= 0
      \post Se quita la cantidad indicada de unidades de un producto del total del stock 
  */
  void restar_stock(std::string p, int quant);

  //Consultoras

  /** @brief Consultora de las unidades
      \pre <em>cierto</em>
      \post El resultado es el numero de unidades del parámetro implícito
  */
  void consultar_prod(std::string id) const;

  /** @brief Consultora del inventario
      \pre <em>cierto</em>
      \post El resultado es el numero de unidades de todos los productos del inventario
  */
  void inventario() const;

  //Destructora

  /** @brief Dar de baja un producto
      \pre identificador empieza por letra y unidades == 0
      \post El resultado es dar de baja el producto con identificador "id" de la lista de productos
  */
  void quitar_prod(std::string id);

private:
  std::map <std::string,int> stock;
};

#endif

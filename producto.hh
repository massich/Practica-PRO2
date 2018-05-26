/** @file producto.hh
    @brief Especificación de la clase Producto
*/

#ifndef _PRODUCTO_HH_
#define _PRODUCTO_HH_

#ifndef NO_DIAGRAM
#include <string>
#include "almacen.hh"
#endif


/** @class Producto
    @brief Representa un tipo de producto del almacen. 

*/

class Producto {
 
 public:
  //Constructora
  
  /** @brief añadir producto al sistema
      \pre identificador no existe
      \post El resultado es añadir un producto con 0 unidades e identificador "id" a la lista de productos del almacen
  */  
  void poner_prod(string id);
  
  //Modificadoras

  /** @brief Modificadora de los atributos
      \pre unidades>=0 y el identifcador empieza con una letra
      \post El parámetro implícito pasa a tener identificador "id" y "ud" unidades.
      */
  void modificar(string id, int ud);
  
  //Consultoras

  /** @brief Consultora del identificador
      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
  */
  int consul_identificador() const;
 
  /** @brief Consultora de las unidades
      \pre <em>cierto</em>
      \post El resultado es el numero de unidades del parámetro implícito
  */
  bool consul_unidades() const;
  
  //Destructora
  
  /** @brief Dar de baja un producto
      \pre identificador empieza por letra y unidades == 0
      \post El resultado es dar de baja el producto con identificador "id" de la lista de productos
  */  
  void quitar_prod(string id);
    
  //Escritura de producto

  /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito el identificador y el numero de unidades del producto
  */
  void escribir_producto() const;

private:
  string identificador;
  int unidades;
};

#endif
  
  
  
  
  
  
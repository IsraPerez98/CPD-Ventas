#pragma once

#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include "matrizdatos.h"

/**
 * quitar las comillas de una variable string
 * 
 * @param valor valor string al que se le quitan las comillas
 */
std::string quitarComillas(std::string valor);

/**
 * Crear matriz con los datos entregados
 * 
 * @param archivo archivo csv con el que se trabaja
 */
MatrizDatos generarMatrizDatos(std::string archivo);

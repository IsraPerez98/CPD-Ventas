#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdint>

/**
 * Implementation de una matriz que contiene los datos de los dias y las ventas correspondientes
 *
 */
class MatrizDatos{
    private:
    /**
    * Inserta los valores de dia y ventas a la matriz
    * @param dia numero de  dias desde fecha_inicial
    * @param ventas cantidad de ventas correspondientes al dia
    */
        void insertarLinea(int dia, int ventas);
        
    public:

        ///vector que contiene los dias, que se cuentan desde la fecha_inicial, partiendo de 0
        std::vector<unsigned int> dia;

        ///vector que contiene las ventas por dia
        std::vector<unsigned int> ventas;

        ///contiene la fecha inicial desde donde se empiezan a contar los dias
        std::time_t fecha_inicial;

        /**
        * Suma los datos de las ventas a un dia existente, o inserta un dia nuevo con las ventas
        * @param fecha fecha correspondiente a los datos a ingresar
        * @param ventas cantidad de ventas correspondientes a esa fecha
        */
        void agregarLinea(std::time_t fecha, int ventas);

        /**
        * Imprime los datos que se encuentran en la matriz
        * @param lineas cantidad de lineas a imprimir
        */
        void print(int lineas);

        /**
        * Imprime los datos que se encuentran en la matriz
        */
        void print();

        /**
        * Devuelve el largo de la matriz
        * @return largo de la matriz
        */
        int size();

        /**
        * Imprime los datos que se encuentran en la matriz con formato csv
        * @param lineas cantidad de lineas a imprimir
        */
        void printcsv(int lineas);

        /**
        * Imprime los datos que se encuentran en la matriz con formato csv
        */
        void printcsv();

        /**
         * Define la fecha inicial para trabajar las demas funciones
         * @param fecha_inicial fecha inicial con la que trabaja la matriz
        */
        void setFechaInicial(std::time_t fecha_inicial);

};
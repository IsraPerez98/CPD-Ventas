#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>


class MatrizDatos{
    private:
        std::vector<std::tm> fecha;
        //std::vector<int> sku;
        //std::vector<int> cantidad;
        //std::vector<int> precio;
        //std::vector<std::string> nombre;
        std::vector<int> ventas;
    public:
        void insertarLinea(std::tm fecha, int ventas);

        void print(int lineas);

        void print();

        int size();

        //std::string skuToNombre(int sku);

        //std::vector<int> generarArregloSku();


};
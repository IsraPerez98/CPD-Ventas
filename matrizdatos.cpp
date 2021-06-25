#include "matrizdatos.h"

int MatrizDatos::size()
{
    return this->fecha.size();
}

void MatrizDatos::insertarLinea(std::tm fecha, int ventas)
{

    this->fecha.push_back(fecha);

    this->ventas.push_back(ventas);

}

void MatrizDatos::print(int lineas)
{
    for (int i = 0; i < lineas; i++)
    {
        
        //std::cout << i + 1 << ":  " << std::put_time(&this->fecha[i], "%c")  << " | " << this->sku[i] << " | " << this->cantidad[i] << " | " << this->precio[i] << " | " << this->nombre[i] << std::endl;
        std::cout << i + 1 << ":  " << std::put_time(&this->fecha[i], "%c") << " | " << this->ventas[i] << std::endl;
    }
}

void MatrizDatos::print()
{
    this->print(this->size());
    std::cout << "Cantidad de Valores: " << this->size() << std::endl;
}
#include "matrizdatos.h"

int MatrizDatos::size()
{
    return this->dia.size();
}


void MatrizDatos::insertarLinea(int dia, int ventas)
{

    this->dia.push_back(dia);
    this->ventas.push_back(ventas);

}


void MatrizDatos::agregarLinea(std::time_t fecha, int ventas)
{
    int ultimo = this->size() - 1;

    /// el dia es la diferencia entre la fecha actual con la fecha inicial, como esta medido en segundos, dividimos por 86400
    int dia = (fecha - this->fecha_inicial) / 86400;

    /**
    * si la fecha ya esta en la matriz, sumamos las ventas
    * en caso contrario, insertamos la fecha y las ventas a una posicion nueva
    */
    if(ultimo >= 0 && dia == this->dia[ultimo]) 
    {
        this->ventas[ultimo] += ventas;
    }
    else
    {
        this->insertarLinea(dia, ventas);
    }

}
 

void MatrizDatos::print(int lineas)
{
    for (int i = 0; i < lineas; i++)
    {
        
        //std::cout << i + 1 << ":  " << std::put_time(&this->fecha[i], "%c")  << " | " << this->sku[i] << " | " << this->cantidad[i] << " | " << this->precio[i] << " | " << this->nombre[i] << std::endl;
        std::cout << i + 1 << ":  " << this->dia[i] << " | " << this->ventas[i] << std::endl;
    }
}


void MatrizDatos::print()
{
    this->print(this->size());
    std::cout << "Cantidad de Valores: " << this->size() << std::endl;
}

void MatrizDatos::printcsv(int lineas)
{
    for (int i = 0; i < lineas; i++)
    {
        std::cout << this->dia[i] << ";" << this->ventas[i] << std::endl;
    }
}

void MatrizDatos::printcsv()
{
    this->printcsv(this->size());
}


void MatrizDatos::setFechaInicial(std::time_t fecha_inicial)
{
    this->fecha_inicial = fecha_inicial;
}
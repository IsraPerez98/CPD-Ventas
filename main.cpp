#include <iostream>
#include <string>
#include <filesystem>
#include <cmath>

#include "leeryescribir.h"
#include "matrizdatos.h"

int main(int argc, char** argv)
{
    if (argc < 2) 
    {
        std::cout << "===Integrantes===" << std::endl;
        std::cout << "Israel Perez" << std::endl;
        std::cout << "Andres Parada" << std::endl;
        std::cout << "Diego Nuñez" << std::endl;
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "Falta el argumento del archivo" << std::endl;
        return (EXIT_FAILURE);
    }

    ///se obtiene la ubicacion del archivo
    std::filesystem::path archivo = std::filesystem::path(argv[1]);

    ///generamos una matriz con los datos de los archivos
    MatrizDatos matriz_datos = generarMatrizDatos(archivo);
    
    int n = matriz_datos.size();

    ///datos para hacer analisis estadistico

    ///sumatoria de todos los dias(x)
    long int sumatoria_x = 0;
    
    ///sumatoria de todas las ventas (x)
    long int sumatoria_y = 0;

    ///sumatoria de todas las log(ventas (x))
    long int sumatoria_y_log = 0;

    ///sumatoria de todos los dias al cuadrado (x**2)
    long int sumatoria_x_cuadrado = 0;

    ///sumatoria de todos las ventas * dias (x*y)
    long int sumatoria_xy = 0;

    ///sumatoria de todos las ventas * log(dias) (x*log(y))
    long int sumatoria_xy_log = 0;

    for(int i=0; i<n; i++)
    {
        int fecha = matriz_datos.dia[i];
        int ventas = matriz_datos.ventas[i];

        double ventas_log = std::log(ventas);

        sumatoria_x += fecha;
        sumatoria_y += ventas;
        sumatoria_y_log += ventas_log;
        sumatoria_x_cuadrado += std::pow(fecha, 2);
        sumatoria_xy += fecha * ventas;
        sumatoria_xy_log += fecha * ventas_log;

    }

    /// transformamos la fecha inicial al dia en string legible
    char tiempo_str[30];
    struct tm * tiempo;
    tiempo = localtime (&matriz_datos.fecha_inicial);
    strftime(tiempo_str, sizeof(tiempo_str), "%Y-%m-%d", tiempo);

    /// realizamos la regresion lineal
    double d_lineal = n*sumatoria_x_cuadrado-sumatoria_x*sumatoria_x;
    double a_lineal = ((double)(sumatoria_x_cuadrado*sumatoria_y-sumatoria_x*sumatoria_xy))/d_lineal;
    double b_lineal = (n*sumatoria_xy-sumatoria_x*sumatoria_y)/d_lineal;

    std::cout << std::fixed;

    std::cout << "Funcion Lineal: Ventas (por dia) = " << a_lineal << " * (Dias desde " << tiempo_str << ")  + " << b_lineal << std::endl;

    ///ajuste exponencial
    /// calculamos la pendiente
    double pendiente_exp = ((long double)(n*sumatoria_xy_log-sumatoria_x*sumatoria_y_log))/(n*sumatoria_x_cuadrado-sumatoria_x*sumatoria_x);
    /// calculamos la intercepcion
    double intercepto_exp = ((long double)(sumatoria_x_cuadrado*sumatoria_y_log-sumatoria_x*sumatoria_xy_log))/(sumatoria_x_cuadrado*n-sumatoria_x*sumatoria_x); 
    double c_exp = pow(2.71828,intercepto_exp);
    
    ///se imprime la formula exponencial
    std::cout << "Funcion Exponencial: Ventas (por dia) = " << c_exp << " * e ^ ( " << pendiente_exp << " * (Dias desde " << tiempo_str << ") )" << std::endl;

    return 0;
}
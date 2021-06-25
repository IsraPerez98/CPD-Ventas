#include <iostream>
#include <string>
#include <filesystem>

#include "leeryescribir.h"


int main(int argc, char** argv)
{
    if (argc < 2) 
    {
        std::cout << "Falta el argumento del archivo" << std::endl;
        return (EXIT_FAILURE);
    }

    std::filesystem::path archivo = std::filesystem::path(argv[1]);

    std::filesystem::path directorio = archivo.parent_path();

    /*
     * Necesitamos la ubicacion del archivo original, para general los archivos de salida
     */
    std::string directorio_str = directorio.u8string() + "/" ;

    MatrizDatos matriz_datos = generarMatrizDatos(archivo);
    matriz_datos.print();
    
    

    return 0;
}
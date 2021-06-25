#include "leeryescribir.h"

std::string quitarComillas(std::string valor)
{
    valor.erase(std::remove(valor.begin(), valor.end(), '\"'), valor.end());
    return valor;
}

MatrizDatos generarMatrizDatos(std::string archivo)
{
    std::ifstream archivo_stream;
    archivo_stream.open(archivo);

    std::string linea;

    MatrizDatos datos = MatrizDatos();

    if (archivo_stream.is_open())
    {
        while (std::getline(archivo_stream, linea))
        {
            std::stringstream ss(linea);

            std::string fecha;
            std::string sku;
            std::string cantidad;
            std::string precio;
            std::string nombre;

            std::getline(ss, fecha, ';');
            std::getline(ss, sku, ';');
            std::getline(ss, cantidad, ';');
            std::getline(ss, precio, ';');
            std::getline(ss, nombre, ';');

            fecha = quitarComillas(fecha);
            //sku = quitarComillas(sku);
            //cantidad = quitarComillas(cantidad);
            precio = quitarComillas(precio);
            //nombre = quitarComillas(nombre);

            try
            {
                //int sku_int = stoi(sku);
                //int cantidad_int = stoi(cantidad);
                int precio_int = stoi(precio);

                std::tm fecha_tm = {};
                std::istringstream ss(fecha);
                ss.imbue(std::locale("es_CL.utf-8"));
                ss >> std::get_time(&fecha_tm, "%Y-%m-%d %H:%M:%S");
                if (ss.fail())
                {
                    std::cout << "Fecha erronea " << fecha << std::endl;
                }

                //datos.insertarLinea(fecha_tm, sku_int, cantidad_int, precio_int, nombre);
                datos.insertarLinea(fecha_tm, precio_int);
            }
            catch (...)
            {
                std::cout << "linea no valida del archivo: " << std::endl
                          << linea << std::endl;
            }
        }
    }
    else
    {
        std::cout << "error al abrir archivo" << std::endl;
    }
    archivo_stream.close();

    return datos;
}
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
            cantidad = quitarComillas(cantidad);
            precio = quitarComillas(precio);

            try
            {

                ///transformamos los valores a int
                //int sku_int = stoi(sku);
                int cantidad_int = stoi(cantidad);
                //std::cout << "precio : " << precio << std::endl;
                int precio_int = stoi(precio);

                int precio_total = cantidad_int * precio_int;

                if(precio_total > 0)
                {
                    ///transformamos la fecha string a time_t
                    std::tm fecha_tm = {};
                    std::istringstream ss(fecha);
                    ss.imbue(std::locale("en_US.utf-8"));
                    ss >> std::get_time(&fecha_tm, "%Y-%m-%d");
                    if (ss.fail())
                    {
                        //std::cout << "Fecha erronea " << fecha << std::endl;
                    }

                    time_t fecha_t = mktime(&fecha_tm);

                    ///si la matriz aun no contiene datos, consideramos la fecha actual como la fecha inicial
                    if (datos.size() == 0)
                    {
                        datos.setFechaInicial(fecha_t);
                    }

                    //std::cout << "leyendo " << fecha << "  " << cantidad << "  " << precio << std::endl;

                    ///insertamos los valores a la matriz
                    datos.agregarLinea(fecha_t, precio_total);
                    //datos.insertarLinea(fecha_tm, precio_int);
                }
            }
            catch (...)
            {
                /*
                std::cout << "linea no valida del archivo: " << std::endl
                          << linea << std::endl;
                */
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
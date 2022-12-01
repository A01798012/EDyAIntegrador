#ifndef BITACORA_HPP_
#define BITACORA_HPP_

#include "ListaDL.hpp"
#include "BST.hpp"
#include "Acceso.hpp"
#include "Ip.hpp"
#include <fstream>

using namespace std;

class Bitacora
{
private:
    ListaDL<Ip *> *direccionesIp;
    BST<Acceso *> *arbolIps;

public:
    Bitacora()
    {
        this->direccionesIp = new ListaDL<Ip *>();
        this->arbolIps = new BST<Acceso *>();
    }

    void leerArchivo(string direccionArchivo)
    {
        /*Función para leer un archivo .txt y almacenar las Ips y sus ocurrencias en la
        lista doblemente ligada (listaIps) de la bitacora
        Complejidad : O(n x m)
        */

        ifstream datos;
        datos.open(direccionArchivo);

        // solo se usará ip
        string mes, dia, hora, ip, puerto, falla;

        while (datos.good())
        {
            getline(datos, mes, ' ');
            getline(datos, dia, ' ');
            getline(datos, hora, ' ');
            getline(datos, ip, ':');
            getline(datos, puerto, ' ');
            getline(datos, falla);

            if (mes != "")
            {
                // Pa las macs, que ahí el newline funciona raro
                if (falla.back() == '\r')
                {
                    falla.pop_back();
                }

                bool yaExisteFalla = false;
                Nodo<Ip *> *ipActual = this->direccionesIp->getHead();
                for (int i = 0; i < this->direccionesIp->getTam(); i++)
                {
                    if (ip == ipActual->getDato()->getDireccionIp())
                    {
                        yaExisteFalla = true;
                        ipActual->getDato()->setCantidad(ipActual->getDato()->getCantidad() + 1);
                        break;
                    }
                    ipActual = ipActual->getSiguiente();
                }
                if (!yaExisteFalla)
                {
                    Ip *nuevaIp = new Ip(ip);
                    this->direccionesIp->agregarInicio(nuevaIp);
                }
            }
        }

        datos.close();
    }

    void guardarNumAccesoIps(string direccionArchivo)
    {
        /*Función para guardar en un archivo .txt las Ips y sus cantidades de accesos
        Complejidad : O(n)
        */

        ofstream archivo(direccionArchivo);

        Nodo<Ip *> *ipActual = this->direccionesIp->getHead();
        for (int i = 0; i < this->direccionesIp->getTam(); i++)
        {
            archivo << ipActual->getDato()->display() << endl;
            ipActual = ipActual->getSiguiente();
        }
    }

    void crearArbol()
    {
        /*Función para crear un arbol binario de busqueda a partir de las Ips y sus ocurrencias
        Complejidad : O(nivel)*/

        Nodo<Ip *> *ipActual = this->direccionesIp->getHead();
        for (int i = 0; i < this->direccionesIp->getTam(); i++)
        {
            this->arbolIps->agregarNodo(ipActual->getDato());
            ipActual = ipActual->getSiguiente();
        }
    }

    void imprimirPorNumAccesos(int cantAccesos)
    {
        /*Función para imprimir las ips por cantidad de accesos
        Complejidad:
        O(nivel) para la busqueda
        O(n) para la impresión de cada ip
        */

        NodoBST<Acceso *> *accesoGanador = arbolIps->buscarNodo(cantAccesos);

        if (accesoGanador)
        {
            cout << "Lista de Ips con #" << cantAccesos << " accesos: "
                 << "\n";
            cout << accesoGanador->getDato()->display();
        }
        else
        {
            cout << "No hay ninguna IP con #" << cantAccesos << " accesos"
                 << "\n\n";
        }
    }

    void imprimirArbol()
    {
        /*Función para imprimir el árbol en orden y preorden
        Complejidad : O(n) para cada impresión*/
        cout << "Impresión en orden: " << endl;
        arbolIps->imprimirInOrder();

        cout << "Impresión en preorden: " << endl;
        arbolIps->imprimirPreOrder();
    }
};

#endif

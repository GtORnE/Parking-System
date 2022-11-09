#ifndef ALMACENAR_H
#define ALMACENAR_H
#include "carro.h"//incluida por las librerias

class Almacenar
{
private:
    string placa;
    string marca;
    int diaIngreso;
    string mes;
public:
    Almacenar();
    bool verificarTemporal(string placa);
    bool verificarPermanente(string placa);
    void escribirTemporal(string placa, string marca, int Hora_entrada, int Min_entrada);//metodo para ficheros
    void escribirPermanente(string placa, string marca, int diaIngreso, string mes);//metodo para ficheros
    int leerRegistro();//metodo para ficheros
    int buscar();//metodo para ficheros
};

#endif // ALMACENAR_H

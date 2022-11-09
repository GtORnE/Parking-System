#ifndef CARRO_H
#define CARRO_H
#include <iostream>
#include <fstream>//permite el manejo de los archivos
#include <stdlib.h>
#include <windows.h>//permite usar Sleep
#include <string>
#include <cstdlib>


using namespace std;

class Carro//clase base
{
protected://parte protected para poder heredarlo
        //datos miembro
    string placa;
    string marca;

public://parte publica con funciones miembro
    Carro();//contructor predeterminado
    Carro(string placa, string marca);//cons
    void setPlaca(string placa);
    void setMarca(string marca);
    string getPlaca();
    string getMarca();
    int menu();
    bool isNumeric(char text[100]);
};

#endif // CARRO_H

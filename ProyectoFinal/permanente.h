#ifndef PERMANENTE_H
#define PERMANENTE_H
#include "carro.h"
#include "almacenar.h"

class Permanente:public Carro//hereda de forma publica de Carro
{
private://parte privada datos miembro
    string mes;
    int diaIngreso;

public://parte publica funciones mimebro
    Permanente();//contructor predeterminado
    Permanente(string mes, int diaIngreso, string placa, string marca);//constructor parametrizado
    void setMes(string mes);//set mes
    void setDiaIngreso(int diaIngreso);//set dia
    string getMes();//get mes
    int getDiaIngreso();//get dia
    void cobrar(string placa);//cobrar permanente
};

#endif // PERMANENTE_H

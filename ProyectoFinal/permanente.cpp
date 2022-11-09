#include "permanente.h"

Permanente::Permanente()//constuctor predeterminado
    :mes("Mes"), diaIngreso(00)
{

}

Permanente::Permanente(string mes, int diaIngreso, string placa, string marca)
    :Carro(placa, marca)//constructor parametrizado con los datos de la herencia
{
    this->mes = mes;
    this->diaIngreso = diaIngreso;
}

void Permanente::setMes(string mes){//set mes
    this->mes = mes;
}

void Permanente::setDiaIngreso(int diaIngreso){//set dia
    this->diaIngreso = diaIngreso;
}

string Permanente::getMes(){//get mes
    return mes;
}

int Permanente::getDiaIngreso(){//get dia
    return diaIngreso;
}

void Permanente::cobrar(string placa)//cobrar
{
    cout << "Placa: " << placa << " --- Paga: " << "$50" << endl;

}

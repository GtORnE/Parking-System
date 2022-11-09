#ifndef TEMPORAL_H
#define TEMPORAL_H
#include "almacenar.h"

class Temporal:public Carro//hereda de forma publica de Carro
{
private://parte privada
    int horaEntrada;
    int horaSalida;

public://parte publica
    Temporal();//constructor predeterminado
    Temporal(int horaEntrada, int horaSalida, string placa, string marca);//constructor
                                                                    //parametrizado
    void setHoraEntrada(int entrada);//set hora
    void setHotaSalida(int salida);//set hora
    int getHoraEntrada();//get hora
    int getHoraSalida();//get hora
    int cobrar(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, string placa);//cobrar
};

#endif // TEMPORAL_H

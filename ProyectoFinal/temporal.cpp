#include "temporal.h"

Temporal::Temporal(){//constructor predeterminado
    horaEntrada = 00;
    horaSalida = 00;
}

Temporal::Temporal(int horaEntrada, int horaSalida, string placa, string marca)
    :Carro(placa, marca)//constructor
                        //parametrizado con los datos de la clase base
{
    this->horaEntrada = horaEntrada;
    this->horaSalida = horaSalida;
}

void Temporal::setHoraEntrada(int entrada){//set hora
    entrada = horaEntrada;
}

void Temporal::setHotaSalida(int salida){//set hora
    salida = horaSalida;
}

int Temporal::getHoraEntrada(){//get hora
    return horaEntrada;
}

int Temporal::getHoraSalida(){//get hora
    return horaSalida;
}

int Temporal::cobrar(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida, string placa)
    //cobrar
{
    //se cobra 1 dolar por cada 50min de parqueo
    float cobro_total;
    int h, m;
    Almacenar a2;

    //horaEntrada, minutoEntrada = a2.obtener_entrada_t(placa);

    if(minutoEntrada > minutoSalida)
    {
        h = horaSalida - (horaEntrada + 1);
        m = (60 - minutoEntrada) + minutoSalida;
        cobro_total = ((h * 60) + m) / 50;
    }
    else if(minutoSalida > minutoEntrada)
    {
        h = horaSalida - horaEntrada;
        m = minutoSalida - minutoEntrada;
        cobro_total = ((h * 60) + m) / 50;
    }
    else
    { //si los minutos son iguales
        h = horaSalida - horaEntrada;
        cobro_total = (h * 60) / 50;
    }

    return cobro_total;
}

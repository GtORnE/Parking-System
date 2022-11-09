#include "carro.h"

Carro::Carro()//constructor predeterminado
    :placa("AAA0000"), marca("Marca")
{}

Carro::Carro(string placa, string marca)//constructor parametrizado
{
    this->placa = placa;
    this->marca = marca;
}

void Carro::setPlaca(string placa){//set placa
    this->placa = placa;
}

void Carro::setMarca(string marca){//set Marca
    this->marca = marca;
}

string Carro::getPlaca(){//get placa
    return placa;
}

string Carro::getMarca(){//get Marca
    return marca;
}

int Carro::menu(){//menu de eleccion
    MENU:
    int opcion;
    char text[100];//arreglo de caracteres para validaciones
    cout << "\n\t---------Menu---------" << endl;
    cout << "1. Ingreso Temporal" << endl;
    cout << "2. Ingreso Mensual" << endl;
    cout << "3. Mostrar Carros Registrados" << endl;
    cout << "4. Buscar en registro" << endl;
    cout << "5. Cobro" << endl;
    cout << "6. Finalizar" << endl;
    cout << "Opcion: ";
    cin >> text;//almacenamiento en el arreglo
    if(isNumeric(text)){//si es true, se acepta, false se rechaza
        opcion = atoi(text);
    }else{
        cout << "******Ingrese una opcion valida******" << endl;
        goto MENU;
    }
    return opcion;
}

bool Carro::isNumeric(char text[100]){//funcion miembro para validaciones
    int val, cont = 0, comp;
    string suplente;
    char letra;

    suplente = text;
    comp = suplente.length(); //ve el tamanio de los caracteres

    int begin = 48;//inicia desde el numero 0 en codigo assci
    int finish = 57;//numero 9 como tope

    for(int i = 0; i <= comp; i++){//lazo para que se almacene cada caracter del
                                    //arreglo y poder compararlo con el intervalo
                                    //permitdo
        letra = text[i];
        val = letra;
        for(int j = begin; j <= finish; j++){ //me recorre todos los valores de 48 a 57
            if(val == j){
                cont ++;//sumamos 1 al contador posincremento
            }
        }
    }

    if(comp == cont){
        return true;//true si esque se cumple
    }else{
        return false;//false si no lo hace
    }
}


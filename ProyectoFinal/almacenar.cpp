#include "almacenar.h"

Almacenar::Almacenar()//constructor predeterminado
    :placa("AAA0000"), marca("Marca"), diaIngreso(00),
      mes("Mes")
{}

bool Almacenar::verificarTemporal(string placaAuxT){
    ifstream leer("CarrosTemporales.txt", ios::in);//in para lectura
    leer >> placa;
    while(!leer.eof()){//llegamos hasta el final del archivo
        leer >> placa;
        if(placa == placaAuxT){//imrpime si existe algo parecido
            cout << "\n\tAdvertencia!!!   Esta placa ya existe" << endl;
            cout << "\t******No sera almacenado el vehiculo******" << endl << endl;
            system("pause");
            leer.close();
            return false;//existe coincidencia
        }
        continue;
    }
    leer.close();
    return true;//no existe coincidencia

}

bool Almacenar::verificarPermanente(string placaAuxP){
    ifstream leer("CarrosPermanentes.txt", ios::in);//in es para lectura
    leer >> placa;
    while(!leer.eof()){//verificamos en todo el archivo que no exista alguna coincidencia
        leer >> placa;
        if(placa == placaAuxP){//si existe coincidencia, imprimimos
            cout << "\n\tAdvertencia!!!   Esta placa ya existe" << endl;
            cout << "\t******No sera almacenado el vehiculo******" << endl << endl;
            system("pause");
            leer.close();
            return false;//existe coincidencia
        }
        continue;
    }
    leer.close();//cerramos el archivo
    return true;//true, no existe coincidencia

}

void Almacenar::escribirTemporal(string placa, string marca, int Hora_entrada, int Min_entrada){
    ofstream respaldoCarrosTemporales;
    //fstream es sintaxis que permite crear, abrir, leer y escribir un archivo
    //respaldoCarros es el nombre de manipulacion
    //ios::app permite que no se sobreescriba el contenido del archivo
    respaldoCarrosTemporales.open("CarrosTemporales.txt", ios::out|ios::app);//se abre el archivo
    //lo que está entre comillas es donde se va a guardar(ahorita
    //está en la carpeta del proyecto
    if(respaldoCarrosTemporales.fail()){//sentencia para verificar si se
        //creó el archivo
        cout << "\t---Error de creacion---" << endl;
        exit(1);//salimos del programa sin un cierre bruto
    }
    if(verificarTemporal(placa))//si es true, se escribe, false, la placa ya existe
        respaldoCarrosTemporales << placa << " " << marca << " " << Hora_entrada << " " << Min_entrada << endl;
    respaldoCarrosTemporales.close();

}

void Almacenar::escribirPermanente(string placa, string marca, int diaIngreso, string mes){
    ofstream respaldoCarrosPermanentes;
    //fstream es sintaxis que permite crear, abrir, leer y escribir un archivo
    //respaldoCarros es el nombre de manipulacion
    //ios::app permite que no se sobreescriba el contenido del archivo
    respaldoCarrosPermanentes.open("CarrosPermanentes.txt", ios::out|ios::app);//se abre el archivo
    //lo que está entre comillas es como se va a guardar
    if(respaldoCarrosPermanentes.fail()){//sentencia para verificar si se
        //creó el archivo
        cout << "\t---Error de creacion---" << endl;
        exit(1);
    }
    if(verificarPermanente(placa))//verificamos si no existe alguno coincidencia
        //formato para almacenar en el fichero
        respaldoCarrosPermanentes << placa << " " << marca << " " << diaIngreso << " " << mes << endl;
    respaldoCarrosPermanentes.close();//cerramos el archivo

}

int Almacenar::leerRegistro(){//leer fichero
    Carro c2;
    ifstream respaldoCarrosTemporales, respaldoCarrosPermanentes;
    respaldoCarrosTemporales.open("CarrosTemporales.txt", ios::in);
    respaldoCarrosPermanentes.open("CarrosPermanentes.txt", ios::in);
    ELECCIONLECTURA:
    int validacion = 0;
    short opcion;
    string placa, marca, mes;
    int diaIngreso, horaIngreso, minutoIngreso;
    char text[100];
    //menu de registros
    cout << "\n=====Registros=====" << endl;
    cout << "1. Carro Temporal" << endl;
    cout << "2. Carro Permanente" << endl;
    cout << "3. Menu Principal" << endl;
    cout << "Opcion: ";
    cin >> text;
    //validacion para entradas del usuario
    if(c2.isNumeric(text)){
        opcion = atoi(text);
        if((opcion < 1) || (opcion > 3)){//verificamos las opciones del menu
            cout << "\t******Ingrese una opcion valida******" << endl;
            Sleep(1000);
            goto ELECCIONLECTURA;
        }
    }else{
        cout << "\t******Ingrese una opcion valida******" << endl;
        Sleep(1000);
        goto ELECCIONLECTURA;
    }

    if(opcion == 1){
        if(respaldoCarrosTemporales.is_open()){
            cout << "=====Carros Temporales Registrados=====" << endl;
            respaldoCarrosTemporales >> placa;
            //lectura del archivo segun las columnas
            while(!respaldoCarrosTemporales.eof()){
                respaldoCarrosTemporales >> marca;
                respaldoCarrosTemporales >> horaIngreso;
                respaldoCarrosTemporales >> minutoIngreso;
                //imprime lo que esta almacenado en las columnas
                cout << "Placa: " << placa << endl;
                cout << "Marca: " << marca << endl;
                cout << "Hora de ingreso: " << horaIngreso << ":" << minutoIngreso << endl;
                cout << "-------------------" << endl;
                respaldoCarrosTemporales >> placa;
            }
            respaldoCarrosTemporales.close();//cerramoe el archivo
            goto ELECCIONLECTURA;
        }else{
            cout << "\t---Error de lectura---" << endl;
            validacion = 1;
            goto VALIDACIONRETURN;
        }
    }

    if(opcion == 2){
        if(respaldoCarrosPermanentes.is_open()){
            cout << "=====Carros Permanentes Registrados=====" << endl;
            respaldoCarrosPermanentes >> placa;
            while(!respaldoCarrosPermanentes.eof()){
                //lectura del archivo segun las columnas
                respaldoCarrosPermanentes >> marca;
                respaldoCarrosPermanentes >> diaIngreso;
                respaldoCarrosPermanentes >> mes;
                //imprime lo que esta almacenado en las columnas
                cout << "Placa: " << placa << endl;
                cout << "Marca: " << marca << endl;
                cout << "Dia de ingreso: " << diaIngreso << endl;
                cout << "Mes de ingreso: " << mes << endl;
                cout << "-------------------" << endl;
                respaldoCarrosPermanentes >> placa;
            }
            respaldoCarrosPermanentes.close();//cerramoe el archivo
            goto ELECCIONLECTURA;
        }else{
            cout << "\t---Error de lectura---" << endl;
            validacion = 1;
            goto VALIDACIONRETURN;
        }
    }

    if(opcion == 3){
        //volvemos al menu
        cout << "------Volviendo al menu principal------" << endl;
        Sleep(1500);//esperamos 1.5 segundos
        system("cls");//limpia la consola
        validacion = 1;
        goto VALIDACIONRETURN;
    }

    VALIDACIONRETURN:
    return validacion;
}

int Almacenar::buscar(){
    ifstream respaldoCarrosTemporales, respaldoCarrosPermanentes;
    Carro c3;
    ELECCIONBUSCAR:
    int value = 0, opcion;
    bool encontrar = false;
    char text[100];
    cout << "\n=====Buscar Carros Registrados=====" << endl;
    cout << "1. Carros Temporales" << endl;
    cout << "2. Carros Permanentes" << endl;
    cout << "3. Menu Principal" << endl;
    cout << "Opcion: ";
    cin >> text;
    //validaciones del usuario y limite entre las opciones
    if(c3.isNumeric(text)){
        opcion = atoi(text);
        if((opcion < 1) || (opcion > 3)){
            cout << "\t******Ingrese una opcion valida******" << endl;
            goto ELECCIONBUSCAR;
        }
    }else{
        cout << "\t******Ingrese una opcion valida******" << endl;
        goto ELECCIONBUSCAR;
    }

    if(opcion == 1){
        cout << "Procesando Carros. Un momento por favor..." << endl;
        Sleep(1300);//esperamso 1.3 segundos
        system("cls");//limpiamos consola
        cout << "\tCarros Temporales" << endl;
        respaldoCarrosTemporales.open("CarrosTemporales.txt", ios::in);
        string placa, marca, placaAuxT;
        int horaIngreso, minutoIngreso;
        cout << "Ingrese la placa: ";
        cin >> placaAuxT;
        if(respaldoCarrosTemporales.is_open()){
            respaldoCarrosTemporales >> placa;
            while(!respaldoCarrosTemporales.eof() && !encontrar){//evitamos recorrer todo
                                                        //el documento
                respaldoCarrosTemporales >> marca;
                respaldoCarrosTemporales >> horaIngreso;
                respaldoCarrosTemporales >> minutoIngreso;
                if(placa == placaAuxT){
                    cout << "Placa: " << placa << endl;
                    cout << "Marca: " << marca << endl;
                    cout << "Hora de ingreso: " << horaIngreso << ":" << minutoIngreso << endl;
                    cout << "-------------------" << endl;
                    encontrar = true;//si no existe esta variable, nunca salimos del lazo
                }
                respaldoCarrosTemporales >> placa;
            }
            system("pause");
            respaldoCarrosTemporales.close();
        }

        if(!encontrar){
            cout << "Vehiculo no registrado...." << endl;
            value = 1;
        }

        goto ELECCIONBUSCAR;
    }

    if(opcion == 2){
        //lo mismo de la anterior parte pero con permanentes
        cout << "Procesando Carros. Un momento por favor..." << endl;
        Sleep(1300);
        system("cls");
        cout << "\tCarros Mensuales" << endl;
        respaldoCarrosPermanentes.open("CarrosPermanentes.txt", ios::in);
        string placa, marca, mes, placaAuxP;
        int diaIngreso;
        cout << "Ingrese la placa: ";
        cin >> placaAuxP;
        if(respaldoCarrosPermanentes.is_open()){
            respaldoCarrosPermanentes >> placa;
            while(!respaldoCarrosPermanentes.eof() && !encontrar){
                respaldoCarrosPermanentes >> marca;
                respaldoCarrosPermanentes >> diaIngreso;
                respaldoCarrosPermanentes >> mes;
                if(placa == placaAuxP){
                    cout << "Placa: " << placa << endl;
                    cout << "Marca: " << marca << endl;
                    cout << "Dia de ingreso: " << diaIngreso << endl;
                    cout << "Mes de ingreso: " << mes << endl;
                    cout << "-------------------" << endl;
                    encontrar = true;
                }
                respaldoCarrosPermanentes >> placa;
            }
            system("pause");
            respaldoCarrosPermanentes.close();
        }

        if(!encontrar){
            cout << "Vehiculo no registrado...." << endl;
            value = 1;
        }
        goto ELECCIONBUSCAR;
    }

    if(opcion == 3){
        //volvemos al menu principal
        cout << "------Volviendo al menu principal------" << endl;
        Sleep(1500);
        system("cls");
        value = 1;
    }

    return value;
}

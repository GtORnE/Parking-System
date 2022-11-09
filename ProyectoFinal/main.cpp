#include "temporal.h"
#include "permanente.h"
//Luciana Valdivieso
//Gustavo Teran

int main(){
    string placa, mes, marca;
    int horaEntrada, minutoEntrada, diaIngreso, opcion, opcion_cobro, horaSalida, minutoSalida;
    char text[100];
    Carro c1;
    Almacenar a1;

    cout << "<<---------Bienvenido--------->>" << endl;
    MENUPRINCIPAL:
    opcion = c1.menu();//menu principal
    if((opcion < 1) || (opcion > 6)){
        cout << "******Entrada invalida******" << endl;
        Sleep(1000);
        system("cls");
        goto MENUPRINCIPAL;
    }

    while(opcion != 6){
        if(opcion == 1){
            system("cls");//limpia la consola
            cout << "\t------Ingreso Temporal------" << endl;
            cout << "Ingrese la placa: ";
            cin >> placa;
            cout << "Ingrese la marca: ";
            cin.ignore();
            getline(cin, marca);//acpetamos caracteres mas largos
            INGRESOHORA:
            cout << "--------Ingrese hora de entrada en formato 24H--------" << endl;
            cout << "Ingrese la hora: ";
            cin >> horaEntrada;
            cout << "Ingrese los minutos: ";
            cin >> minutoEntrada;
            //bloque de validacion
            if (horaEntrada < 8 || horaEntrada > 18){
                cout << "***Horario de Atencion (8AM - 19PM)***" << endl;
                goto INGRESOHORA;
            }

            if (minutoEntrada > 59 || minutoEntrada == 0){
                cout << "** Minutos entre 1 - 59 **" << endl;
                goto INGRESOHORA;
            }

            Temporal t1(horaEntrada, minutoEntrada, placa, marca);
            t1.setHoraEntrada(horaEntrada);
            t1.setHotaSalida(minutoEntrada);
            a1.escribirTemporal(placa, marca, horaEntrada, minutoEntrada);
            cout << "Almacenando datos..." << endl;
            Sleep(1000);//esperamos por 1 segundo
            system("cls");//limpia la consola
            goto MENUPRINCIPAL;
        }

        if(opcion == 2){
            system("cls");//limpia la consola
            cout << "\t------Ingreso Mensual------" << endl;
            cout << "Ingrese la placa: ";
            cin >> placa;
            cout << "Ingrese la marca: ";
            cin.ignore();
            getline(cin, marca);
            SELECCIONDIAMES:
            cout << "Ingrese el dia del registro: ";
            cin >> text;
            if(c1.isNumeric(text)){//validaciones de caracteres del ingreso del usuario
                diaIngreso = atoi(text);
                if((diaIngreso < 1) || (diaIngreso > 31)){
                    cout << "******Ingrese un dia del mes valido******" << endl;
                    Sleep(1000);
                    goto SELECCIONDIAMES;
                }
            }else{
                cout << "******Ingrese un dia del mes valido******" << endl;
                Sleep(1000);
                goto SELECCIONDIAMES;
            }

            cout << "Ingrese el mes de ingreso: ";
            cin >> mes;
            Permanente p1(mes, diaIngreso, placa, marca);
            p1.setMes(mes);
            p1.setDiaIngreso(diaIngreso);
            a1.escribirPermanente(placa, marca, diaIngreso, mes);
            cout << "Almacenando datos..." << endl;
            Sleep(1000);//esperamos 1 segundo
            system("cls");//limpia la consola
            goto MENUPRINCIPAL;

        }

        if(opcion == 3){
            system("cls");//limpia la consola
            int verificar = a1.leerRegistro();
            if(verificar == 1)
                goto MENUPRINCIPAL;

        }

        if(opcion == 4){
            system("cls");//limpia la consola
            int confirmacion = a1.buscar();
            if(confirmacion == 1)
                goto MENUPRINCIPAL;
        }

        if(opcion == 5){//opcion cobro de carros
            system("cls");//limpia la consola
            cout << "\t------Cobro------" << endl;
            cout << "\nIngrese placa: ";
            cin >> placa;
            SELECCIONCOBRO:
            cout << "1. Temporal\n2. Mensual" << endl;
            cout << "Opcion: ";
            cin >> opcion_cobro;
            if(opcion_cobro == 1){
                Temporal t2;
                HORACOBRO:
                //bloque de ingreso de horas
                cout << "\n--------Ingrese hora de entrada en formato 24H--------" << endl;
                cout << "Ingrese la hora: ";
                cin >> horaEntrada;
                cout << "Ingrese los minutos: ";
                cin >> minutoEntrada;
                cout << "--------Ingrese hora de salida en formato 24H---------" << endl;
                cout << "Hora: ";
                cin >> horaSalida;
                cout << "Minutos: ";
                cin >> minutoSalida;
                //bloque de validaciones hora
                if (horaEntrada < 8 || horaEntrada > 18){
                    cout << "***Horario de Atencion (8AM - 19PM)***" << endl;
                    goto HORACOBRO;
                }

                if (minutoEntrada > 59 || minutoEntrada == 0){
                    cout << "** Minutos entre 1 - 59 **" << endl;
                    goto HORACOBRO;
                }

                if (horaSalida < 9 || horaSalida > 19){
                    cout << "***Horario de Atencion (8AM - 19PM)***" << endl;
                    goto HORACOBRO;
                }

                if (minutoSalida > 59 || minutoSalida == 0){
                    cout << "** Minutos entre 1 - 59 **" << endl;
                    goto HORACOBRO;
                }

                cout << "Total a pagar: " << t2.cobrar(horaEntrada, minutoEntrada, horaSalida, minutoSalida, placa) << endl;
                system("pause");
                system("cls");
                goto MENUPRINCIPAL;

            }else if(opcion_cobro == 2){//cobro carros permanentes
                    Permanente p2;
                    p2.cobrar(placa);
                    goto MENUPRINCIPAL;
                    }else{
                        cout << "***Ingrese un tipo de cobro valido***" << endl;
                        goto SELECCIONCOBRO;
                    }
                goto MENUPRINCIPAL;
        }
    }

    cout << "\n\t<<---------Gracias. Hasta la proxima--------->>\n\n" << endl;
    Sleep(1000);//esperamos por 1 segundo
    return 0;
}

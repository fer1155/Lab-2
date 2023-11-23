#include "CicloBasico.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  CicloBasico cicloBasico1("Ciclo basico de instruccion");
  cicloBasico1.mostrarMenu();
  
  int idInstruccion = 0;
  string nombreArchivo;
  
  cout << "Ingrese el nombre del archivo a ejecutar: ";
  cin >> nombreArchivo;

  ifstream archivo(nombreArchivo);

  if (!archivo.is_open()) {
    cerr << "No se pudo abrir el archivo" << endl;
    return 1; //Termina el programa con un código de error
  }

  cout << "Accediendo a " +  nombreArchivo + "..."<< endl;
  cout << "Accediendo a " +  nombreArchivo + "..."<< endl;
  cout << "Accediendo a " +  nombreArchivo + "..."<< endl  << endl;
  
  string linea;
  while (getline(archivo, linea)) {
    //Vector para almacenar las partes de cada linea
    vector<string> partes;

    //istringstream para dividir la cadena en partes
    istringstream stream(linea);
    string parte;

    // Lee cada palabra y la agrega al vector
    while (stream >> parte) {
      partes.push_back(parte);
    }

    string instruccion = partes[0];

    if(instruccion == "SET") {
      
      cout << "Asignando valor de memoria con SET ";
      string direccionEnMemoria = partes[1];
      string valor = partes[2];
      cicloBasico1.setValores(direccionEnMemoria, valor);
      cout << valor + " -> " + direccionEnMemoria << endl;
    
    }else if(instruccion != "SET" and instruccion != "PAUSE" and instruccion !="END"){

      cout << "\nIniciando ejecucion de la linea " + instruccion << endl;
      string valor1 = partes[1];
      string valor2 = partes[2];
      string valor3 = partes[3];
      string valor4 = partes[4];
      
      cicloBasico1.setInstrucciones(idInstruccion, instruccion, valor1, valor2, valor3, valor4);
      cicloBasico1.ejecucionDeCicloBasico();
      idInstruccion++;
      
    }else if (instruccion == "PAUSE"){
      
      while(true){
        string opcion;
        cout << "\nPausa\n" << endl;
        cicloBasico1.funcionalidadPause();
        cout << "¿Desea salir de la pausa? (S/N)" << endl;
        cin >> opcion;

        if(opcion == "S"){
          break;
        }
      } 
    
    }else if (instruccion == "END"){
      
      cout << "\nFinalizacion del programa, ¡hasta la proxima!";
      break;
    
    }
  }
  return 0;
}
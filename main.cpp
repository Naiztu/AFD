#include <iostream>
#include <fstream>
using namespace std;

#include "Variable.h"
#include "Number.h"
#include "simbolo.h"

void lexerAritmetico(string archivo)
{ //Creación de la función principal del archivo

    Variable val = Variable();
    Number num = Number();
    Simbolo sim = Simbolo();

    enum TStatus
    {//Cantidad de casos del autómata que relaciona la identificación de número, variable y símbolo
        q0,
        q1,
        q2,
        q3,
    };
    //Definición de los estados, de line y de la carga del archivo
    TStatus state;
    state = q0;
    string line = "";
    fstream file = fstream(archivo);
    int numline = 1;

    if (file.is_open())//Lectura del archivo
        while (!file.eof())
        { //Si el archivo no se termina, se lee cada línea del archivo para poder realizar el procedimiento, uno por uno.
            int index = 0;
            getline(file, line);
            line.size() != 0 && cout << "\nLINE " << numline << endl;
            numline++;
            while (index != line.size())
            {
                switch (state)
                { //Toma de texto y observación por medio de casos
                case q0: //Redirección
                    if (isdigit(line[index]))
                        state = q1; //Caso de números
                    else if (line[index] == ' ')
                        index++; //Saltar espacios
                    else if (isalpha(line[index]))
                        state = q2; //Caso de variables
                    else
                        state = q3; //Caso de símbolos
                    break;
                case q1: // Número, regresa después al análisis del caso q0
                    index = num.isNumber(line, index);
                    state = q0;
                    break;
                case q2: // Variable, regresa después al análisis del caso q0
                    index = val.isVariable(line, index);
                    state = q0;
                    break;
                case q3: // Símbolo, regresa después al análisis del caso q0
                    index = sim.isSimbolo(line, index);
                    state = q0;
                    break;
                }
            }
        }
}

int main()
{

    string file = "";
    cout << "Nombre del archivo (con extension .txt): "; //El programa pide el nombre del archivo con extensión, en este caso "prueba.txt"
    cin >> file;

    if (".txt" == file.substr(file.size() - 4))
        lexerAritmetico(file); //Se ejecuta la función anterior con el archivo de texto entregado
    else
        cout << "EL archivo tiene que ser de tipo .txt"; //Si no es txt, no se lee
    return 0;
}

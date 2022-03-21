#include <iostream>
#include <fstream>
using namespace std;

#include "Variable.h"
#include "Number.h"
#include "simbolo.h"

void lexerAritmetico(string archivo)
{

    Variable val = Variable();
    Number num = Number();
    Simbolo sim = Simbolo();

    enum TStatus
    {
        q0,
        q1,
        q2,
        q3,
    };
    TStatus state;
    state = q0;
    string line = "";
    fstream file = fstream(archivo);
    int numline = 1;

    if (file.is_open())
        while (!file.eof())
        {
            int index = 0;
            getline(file, line);
            line.size() != 0 && cout << "\nLINE " << numline << endl;
            numline++;
            while (index != line.size())
            {
                switch (state)
                {
                case q0:
                    if (isdigit(line[index]))
                        state = q1;
                    else if (line[index] == ' ')
                        index++;
                    else if (isalpha(line[index]))
                        state = q2;
                    else
                        state = q3;
                    break;
                case q1:
                    index = num.isNumber(line, index);
                    state = q0;
                    break;
                case q2:
                    index = val.isVariable(line, index);
                    state = q0;
                    break;
                case q3:
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
    cout << "Nombre del archivo (con extension .txt): ";
    cin >> file;

    if (".txt" == file.substr(file.size() - 4))
        lexerAritmetico(file);
    else
        cout << "EL archivo tiene que ser de tipo .txt";
    return 0;
}

#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
using namespace std;

class Variable
{ //Creación de clase Variable
public:
    Variable(){};
    int isVariable(string, int);
};

int Variable::isVariable(string text, int index)
{
    enum TStatus
    { //Tres diferentes estados detectados previamente.
        q0,
        q1,
        q2
    };
    TStatus state;
    state = q0;
    int i = index, longitud = text.size();
    while (state != q2) //Si se obtiene el q2, se acaba el while
    {
        switch (state)
        {
        case q0: //Detecta si es letra y se manda al caso q1, si es falso, es un error de la variable
            if (isalpha(text[i]))
            {
                state = q1;
                i++;
            }
            else
                state = q2;
            break;
        case q1:
            if (isalpha(text[i]) || text[i] == '_' || isdigit(text[i])) //Si es letra, guión bajo o número, se podrá reiterar hasta que esto deje de cumplirse.
                i++;
            else
                state = q2;
            break;
        }
    }
    (i != index) &&
        cout << "Variable : " << text.substr(index, i - index) << endl; //Impresión de la variable
    return i;
}

#endif

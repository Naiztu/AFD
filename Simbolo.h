#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include "Number.h"
using namespace std;

class Simbolo
{
public:
    Simbolo(){};
    int isSimbolo(string, int);
};

int Simbolo::isSimbolo(string text, int index)
{
    Number num = Number();
    int i = index;
    switch (text[i])
    {
    case '=':
        i++;
        cout << "Asignacion: =" << endl;
        break;
    case '(':
        i++;
        cout << "Paréntesis que abre: (" << endl;
        break;
    case ')':
        i++;
        cout << "Paréntesis que cierra: )" << endl;
        break;
    case '*':
        i++;
        cout << "Multiplicación: *" << endl;
        break;
    case '/':
        i++;
        if (text[i] == '/')
        {
            cout << "Comentario: " << text.substr(index) << endl;
            i = text.size();
        }
        else
            cout << "División: /" << endl;
        break;
    case '+':
        i++;
        cout << "Suma: +" << endl;
        break;
    case '-':
        i++;
        if (isdigit(text[i]))
        {
            i = num.isNumber(text, index);
        }
        else
            cout << "Resta: -" << endl;
        break;
    case '^':
        i++;
        cout << "Potencia: ^" << endl;
        break;
    }
    return i;
}
#endif
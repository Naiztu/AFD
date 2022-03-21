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

int Simbolo::isSimbolo(string text, int index) //Estudio individual de cada símbolo recordado por la máquina
{
    Number num = Number();
    int i = index;
    switch (text[i]) //Se manejan todos los casos dependiendo de su caracter para hacer la impresión
    {
    case '=':
        i++;
        cout << "Asignacion : =" << endl;
        break;
    case '(':
        i++;
        cout << "Parentesis que abre : (" << endl;
        break;
    case ')':
        i++;
        cout << "Parentesis que cierra : )" << endl;
        break;
    case '*':
        i++;
        cout << "Multiplicacion : *" << endl;
        break;
    case '/':
        i++; //Si en la siguiente iteración se encuentra otra diagonal, es comentario y el resto se convierte en comentario también
        if (text[i] == '/')
        {
            cout << "Comentario: " << text.substr(index) << endl;
            i = text.size();
        }
        else
            cout << "Division : /" << endl;
        break;
    case '+':
        i++;
        cout << "Suma : +" << endl;
        break;
    case '-':
        i++; //Si el siguiente valor es un número, es un número negativo, no una resta
        if (isdigit(text[i]))
            i = num.isNumber(text, index);
        else
            cout << "Resta : -" << endl;
        break;
    case '^':
        i++;
        cout << "Potencia : ^" << endl;
        break;
    case '.':
        i++;
        if (isdigit(text[i])) //Si el siguiente valor es un número, es un número decimal, no un punto
            i = num.isNumber(text, index);
        else
            cout << "Punto : ." << endl;
        break;
    }
    return i;
}
#endif

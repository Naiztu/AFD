#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
using namespace std;

class Number //Definición de clase del Número
{
public:
    Number(){};
    int isNumber(string, int);
};

int Number::isNumber(string text, int index)
{
    enum TStatus
    { //7 casos identificados con autómatas
        q0,
        q1,
        q2,
        q3,
        q4,
        q5,
        q6,
        q7
    };
    TStatus state;
    state = q0; //Se empieza en el primer caso
    bool numFloat = false; //No se detecta que es decimal.
    int i = index, longitud = text.size();
    while (state != q7) // Si no se lleva al séptimo caso, el while se repetirá
    {
        switch (state)
        {
        case q0: // Estudia si es un número negativo, si crashea con una letra/signo, si es un punto o si inicia directamente con un número.
            state = q1;
            if (text[i] == '-' || text[i] == '.')
            {
                if (text[i] == '.')
                    numFloat = true;
                i++;
                if (!isdigit(text[i]))
                {
                    state = q7;
                    cout << "Error in Line : " << text << endl;
                }
            }
            break;
        case q1: //Requiere uso de número, si no da error
            if (isdigit(text[i]))
                state = q2;
            else
            {
                cout << "Error in Line : " << text << endl;
                state = q7;
            }
            break;
        case q2: //Da caminos disponibles para encontrar punto o exponencial
            if (isdigit(text[i])) //Tiene que haber un número antes de las condiciones siguientes.
            {
                i++;
                if (text[i] == '.')
                {
                    numFloat = true; //Se detecta que es decimal gracias al punto
                    i++;
                    state = q3;
                }
                else if (text[i] == 'E' || text[i] == 'e')
                {
                    numFloat = true;
                    state = q4;
                }
            }
            else
                state = q7;
            break;
        case q3: //Exige un número después del punto
            if (isdigit(text[i]))
                state = q5;
            else
            {
                state = q7;
                cout << "Error in Line : " << text << endl;
            }
            break;
        case q4: // Revisión del dato que acompaña a la E/e, que puede ser digito reiterado u otro símbolo.
            if (text[i] == 'E' || text[i] == 'e')
            {
                i++;
                if (isdigit(text[i]))
                    state = q6;
                else if (text[i] == '-' || text[i] == '.')
                {
                    i++;
                    if (!isdigit(text[i]))
                    {
                        state = q7;
                        cout << "Error in Line : " << text << endl;
                    }
                    else
                        state = q3;
                }
                else
                {
                    state = q7;
                    cout << "Error in Line : " << text << endl;
                }
            }
            else
            {
                state = q7;
                cout << "Error in Line : " << text << endl;
            }
            break;
        case q5: //Reiteración de número o exponencial ubicado después de un punto
            if (isdigit(text[i]))
            {
                i++;
                if (text[i] == 'E' || text[i] == 'e')
                {
                    numFloat = true;
                    state = q4;
                }
            }
            else
                state = q7;
            break;
        case q6: //Reiteración de número o punto ubicado después de un exponencial
            if (isdigit(text[i]))
            {
                i++;
                if (text[i] == '.')
                {
                    i++;
                    state = q3;
                }
            }
            else
                state = q7;
            break;
        default:
            break;
        }
    }
    if (i != index)
    {
        if (numFloat) //Detecta si se imprime real o entero
            cout << "Real : " << text.substr(index, i - index) << endl;
        else
            cout << "Entero : " << text.substr(index, i - index) << endl;
    }
    return i;
}

#endif

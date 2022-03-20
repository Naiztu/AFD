#include <iostream>
using namespace std;

#include "Variable.h"
#include "Number.h"
#include "simbolo.h"

int main()
{
    string example = "d = a ^ b // Esto es un comentario";

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
    int index = 0;
    while (index != example.size())
    {
        switch (state)
        {
        case q0:
            if (isdigit(example[index]))
                state = q1;
            else if (example[index] == ' ')
                index++;
            else if (isalpha(example[index]))
                state = q2;
            else
                state = q3;
            break;
        case q1:
            index = num.isNumber(example, index);
            state = q0;
            break;
        case q2:
            index = val.isVariable(example, index);
            state = q0;
            break;
        case q3:
            index = sim.isSimbolo(example, index);
            state = q0;
            break;
        }
    }
    return 0;
}
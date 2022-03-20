#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
using namespace std;

class Variable
{
public:
    Variable(){};
    int isVariable(string, int);
};

int Variable::isVariable(string text, int index)
{
    enum TStatus
    {
        q0,
        q1,
        q2
    };
    TStatus state;
    state = q0;
    int i = index, longitud = text.size();
    while (state != q2)
    {
        switch (state)
        {
        case q0:
            if (isalpha(text[i]))
            {
                state = q1;
                i++;
            }
            else
                state = q2;
            break;
        case q1:
            if (isalpha(text[i]) || text[i] == '_' || isdigit(text[i]))
                i++;
            else
                state = q2;
            break;
        }
    }
    (i != index) &&
        cout << "Variable : " << text.substr(index, i - index) << endl;
    return i;
}

#endif
#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
using namespace std;

class Number
{
private:
    bool nextIsNumber(char);

public:
    Number(){};
    int isNumber(string, int);
};

int Number::isNumber(string text, int index)
{
    enum TStatus
    {
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
    state = q0;
    bool numFloat = false;
    int i = index, longitud = text.size();
    while (state != q7)
    {
        switch (state)
        {
        case q0:
            state = q1;
            if (text[i] == '-' || text[i] == '.')
            {
                i++;
                if (!isdigit(text[i]))
                {
                    state = q7;
                    cout << "Error in Line: " << text << endl;
                }
            }
            break;
        case q1:
            if (isdigit(text[i]))
                state = q2;
            else
            {
                cout << "Error in Line: " << text << endl;
                state = q7;
            }
            break;
        case q2:
            if (isdigit(text[i]))
            {
                i++;
                if (text[i] == '.')
                {
                    numFloat = true;
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
        case q3:
            if (isdigit(text[i]))
                state = q5;
            else
            {
                state = q7;
                cout << "Error in Line: " << text << endl;
            }
            break;
        case q4:
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
                        cout << "Error in Line: " << text << endl;
                    }
                    else
                        state = q3;
                }
                else
                {
                    state = q7;
                    cout << "Error in Line: " << text << endl;
                }
            }
            else
            {
                state = q7;
                cout << "Error in Line: " << text << endl;
            }
            break;
        case q5:
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
        case q6:
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
    (i != index) &&
        cout << "Number: " << text.substr(index, i) << endl;
    return i;
}

#endif
#include <iostream>
using namespace std;

#include "Variable.h"
#include "Number.h"

int main()
{
    string example = "h_olgdg.467E9";
    Variable val = Variable();
    int stop = val.isVariable(example, 0);
    cout << example.substr(stop) << endl;

    Number num = Number();
    int stop5 = num.isNumber(example, stop);
    cout << example.substr(stop5) << endl;
    string example2 = "6.345e-5a";
    string example3 = "-0.001E-3";
    string example4 = ".467E9";
    int stop2 = num.isNumber(example2, 0);
    cout << example2.substr(stop2) << endl;

    int stop3 = num.isNumber(example3, 0);
    cout << example3.substr(stop3) << endl;

    int stop4 = num.isNumber(example4, 0);
    cout << example4.substr(stop4) << endl;

    return 0;
}
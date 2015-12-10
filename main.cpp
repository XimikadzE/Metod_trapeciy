#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <math.h>

using namespace std;
double fun(double ix)
{
    double fx;
    fx = 1 + ix;
    return fx;
}

void methot_trap(double ix1, double ix2, double e1)
{
    double e2, fx1, fx2, S1, S2, dx, ddx;
    double iix1, iix2;
    int n = 2, i;
    e2 = 2*e1;
    dx = ix2 - ix1;
    fx1 = fun(ix1);
    fx2 = fun(ix2);
    if (fx1 <= 0 && fx2 <= 0) { fx1 = fabs(fx1); fx2 = fabs(fx2); }
    S1 = (fx1 + fx2) / 2 * dx;
    S2 = 0;
    while (e2 > e1)
    {
        ddx = dx / n;
        iix1 = ix1;
        iix2 = ix1 + ddx;
        for (i = 0; i < n; i++)
        {
            fx1 = fun(iix1);
            fx2 = fun(iix2);
            if (fx1 <= 0 && fx2 <= 0) { fx1 = fabs(fx1); fx2 = fabs(fx2); }
            S2 = S2 + (fx1 + fx2) / 2 * ddx;
            iix1 = iix2;
            iix2 = iix2 + ddx;
        }
        e2 = fabs(S2 - S1);
        S1 = S2;
        S2 = 0;
        n++;
    }
    cout <<"\n["<<ix1<<";"<<ix2<<"], "<<e1<<" S="<<S1;
}

int main()
{
    double a, b, e1;
    cout << "BBegute uHTepBa/| \n";
    cin >> a >> b;
    cout << "BBeguTe To4HocTb\n";
    cin >> e1;
    methot_trap(a,b,e1);
    return 1;
    system("pause");
}

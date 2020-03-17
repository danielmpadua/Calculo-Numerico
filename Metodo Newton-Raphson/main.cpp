#include <iostream>
#include <math.h>
using namespace std;

double f(double x){
    return x-cos(x);
   // return log(x)-(exp(-3*x));
}

double df(double x){
    return 1+sin(x);
    //return 1+3*exp(-3*x);
}

double calcularErro(double fx, double fxold){
    return fabs(fx-fxold);
}

void exibirResultado(double x, double fx, double dfx, double e){
    cout<< "x: " << x << endl;
    cout<< "fx: " << fx << endl;
    cout<< "dfx: " << dfx << endl;
    cout<< "erro: " << e << endl;
}

int main()
{
    int it=1;
    double x=1,fx=0,dfx=0, fxold=0, e=1;

    while(e > pow(10,-10)){
        cout << endl;
        cout << "Interacao: " << it << endl << endl;
        cout << "Antes:" << endl;
        exibirResultado(x,fx,dfx,e);

        fxold = fx;
        fx = f(x);
        dfx = df(x);
        x = x- (fx/dfx);
        e = calcularErro(fx,fxold);

        cout << endl;
        cout << "Depois:" << endl;
        exibirResultado(x,fx,dfx,e);
        cout << "==================================================================" << endl;
        it ++;
    }
    return 0;
}

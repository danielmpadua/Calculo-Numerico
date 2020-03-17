#include <iostream>
#include <math.h>
using namespace std;

double f(double x){
    return pow(x,(0.5))-5*(exp(-x));
}

double xBarraBisseccao(double a, double b){
    return (a+b)/2;
}

double xBarraCordas(double a, double b, double fa, double fb){
    return ((a*fb) - (b*fa))/(fb-fa);
}

double calcularErro(double xnew, double xold){
    return fabs(xnew-xold);
}

void exibirResultado(double a, double b, double x, double fa, double fb, double fx, double e){
   // cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
    cout<< "a: " << a << endl;
    cout<< "b: " << b << endl;
    cout<< "x: " << x << endl;
    cout<< "fa: " << fa << endl;
    cout<< "fb: " << fb << endl;
    cout<< "fx: " << fx << endl;
    cout<< "e: " << e << endl;
   // cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
}

int main()
{
    double a=1 ,b=2 ,x=0,fa=0,fb=0,fx=0,xold=0, e=1;

    while(e > pow(10,-3)){
        cout << endl;
        cout << "Antes:" << endl;
        exibirResultado(a,b,x,fa,fb,fx,e);

        xold = x;
        fa = f(a);
        fb = f(b);
        x = xBarraCordas(a,b,fa,fb);
        fx = f(x);
        e = calcularErro(x,xold);

        if(fx <0){
            a=x;
        }else{
            b=x;
        }
        cout << endl;
        cout << "Depois:" << endl;
        exibirResultado(a,b,x,fa,fb,fx,e);
        cout << "==================================================================" << endl;
    }
    return 0;
}

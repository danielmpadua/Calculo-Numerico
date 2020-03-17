#include <iostream>
#include <fstream>

using namespace std;

void exibirPontos(int matriz[][2], int ordem){
    cout << "Pontos:" << endl;
    for(int i=0; i<ordem; i++){
        for(int j=0; j<2; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int interpolacao(int x,int matriz[][2],int n){
   int p=0;
   for(int i=0; i<n; i++){
        int l=1;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        for(int j=0;j<n;j++){
            if(i!=j){
                cout << "l = " << l << " * ((" << x << "-" << matriz[j][0] << ")/(" << matriz[i][0] << "-" << matriz[j][0] << "))" << endl;
                l = l * ((x-matriz[j][0])/(matriz[i][0]-matriz[j][0]));
                cout << "l= " << l<< endl<< endl;
            }
        }
        cout << "p = " << p << " + " << matriz[i][1] << " * " << l << endl;
        p = p + matriz[i][1]* l;
        cout << "p= " << p<< endl<< endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
   }
   return p;
}

int main()
{
    cout << "   >> INTERPOLACAO DE POLINOMIOS <<" << endl;
    ifstream entrada;
    int A[100][2], det; /// matriz de pontos
    int n,x,p;               /// n = quantidade de pontos
    entrada.open("pontos.txt");

    entrada >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            entrada >> A[i][j];
        }
    }
    exibirPontos(A,n);
    cout << "Digite um valor: ";
    cin >> x;

    p = interpolacao(x,A,n);
    cout << "O resultado eh: " << p << endl;
    return 0;
}

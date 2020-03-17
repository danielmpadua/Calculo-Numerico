#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void exibirMatriz(double matriz[][100], int ordem){
    cout << endl;
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
///---------------------------------------------------------------------------------------------------------------------------------------------

void trianguloSuperior(double matriz[][100],int ordem){
    for(int i = 0; i < ordem - 1; i++){ /// i e j manipulam as posições da matriz a serem trabalhadas
        for(int j = i + 1; j < ordem; j++){
            double fator = (-1) * matriz[j][i]/matriz[i][i]; /// Fator usado para zerar o numero abaixo do pivo (numero a ser zerado / pivo * -1)
            matriz[j][i] = 0; /// as vezes nao da zero, mas da um numero muito proximo, entao sera forcado a ser zero
            for(int k = i+1; k < ordem; k++){ /// pula a primeira iteracao, controla a coluna onde sera modificado o valor
                matriz[j][k] = matriz[j][k] + fator * matriz[i][k]; /// A linha abaixo do pivo é substituida pelos valores obtidos pela formula
            }                                                       /// onde o fator é multiplicado pelo valor acima do item a ser modificado e somado pelo mesmo
        }
    }
}
///---------------------------------------------------------------------------------------------------------------------------------------------

void trianguloInferior(double matriz[][100],int ordem){ /// igual ao triangulo superior, porem com os parametros invertidos
    for(int i = ordem-1; i >0; i--){
        for(int j = i - 1; j >= 0; j--){
            double fator = (-1) * matriz[j][i]/matriz[i][i];
            matriz[j][i] = 0;
            for(int k = i-1; k >= 0; k--){
                matriz[j][k] = matriz[j][k] + (fator * matriz[i][k]);
            }
        }
    }
}
///---------------------------------------------------------------------------------------------------------------------------------------------

double determinante(double matriz[][100],int ordem){ /// acha o determinante após a matriz estar triangularizada
    double det=1;
    for(int i= 0; i<ordem; i++){ /// percorre a diagonal da matriz atribuindo a multiplicação ao determinante
       det = matriz[i][i] * det;
    }
    return det;
}
///---------------------------------------------------------------------------------------------------------------------------------------------


int main(){
    cout << "Triangularizacao de matriz" << endl;
    ifstream entrada;
    double A[100][100], det; /// A = sitema(matriz), det = determinante da matriz
    int ordem;               /// ordem = tamanho da matriz

    entrada.open("matriz.txt");

    entrada >> ordem;

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            entrada >> A[i][j];
        }
    }
    exibirMatriz(A,ordem);

    trianguloSuperior(A,ordem);
    //trianguloInferior(A,ordem);
    exibirMatriz(A,ordem);

    det = determinante(A,ordem);

    cout << "\nDeterminante: " << det << endl;
    return 0;
}

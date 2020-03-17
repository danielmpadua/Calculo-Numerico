#include <iostream>
#include <fstream>
#include <math.h>


using namespace std;

double detMatriz(double matriz[][100], int ordem){
    int det = 0;
    if (ordem == 1){ /// Se a matriz tiver apenas 1 elemento, ele é o proprio determinante
       det = matriz[0][0];
    }else if (ordem == 2){ ///Se a matriz for de ordem 2, o determinante é dado multiplicando e subtraindo as diagonais
        det = matriz[1][1]*matriz[0][0]-matriz[0][1]*matriz[1][0];
    }else {
        for (int linha = 0; linha < ordem; linha++) { /// controla a linha de referencia
            double subMatriz[100][100];   /// Matriz onde ocorrerá a recursividade
            for (int i = 0; i < ordem-1; i++) { /// controle da subMatriz (ordem -1 pois seu tamanho é reduzido)
                for (int j = 0; j < ordem-1; j++) {

                    int subLinha, subColuna = j+1;
                    if(i<linha){
                        subLinha = i; ///subLinha e subColuna determinam a regiao da matriz a ser acessada
                    }else{
                        subLinha = i+1;
                    }
                    subMatriz[i][j] = matriz[subLinha][subColuna]; /// Determina os valores da subMatriz
                }
            }
            if (linha % 2 == 0){ /// Se o valor da linha for par, o determinante é somado, se for impar é subtraido
             det =  det + matriz[linha][0]*detMatriz(subMatriz, ordem-1); /// Aplicacao da recursividade
            }else{
             det = det - matriz[linha][0]*detMatriz(subMatriz, ordem-1);
            }
        }
    }
    return det;
}

int main()
{
    ifstream entrada;
    double A[100][100]; /// A = sitema(matriz)
    int ordem; /// ordem = tamanho da matriz

    entrada.open("matriz4.txt");

    entrada >> ordem;

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            entrada >> A[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Determinante = " << detMatriz(A,ordem) <<endl;

    return 0;
}

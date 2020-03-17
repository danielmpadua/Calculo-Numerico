#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void gaussSeidel(double matriz[][100], int ordem, double solucaoAtual[100], double b[100]){ /// Usa a solucao atual nas operacoes, atualizando e usando os valores encontrados
    for(int i=0; i<ordem; i++){
            double novoX=0; /// somatorio da linha trabalhada para achar o novo valor de Xi
            for (int j = 0; j < ordem; j++) { /// Encontra o valor de cada variavel x, usando as variaveis ja encontradas
                if (i != j){
                    novoX = novoX + matriz[i][j]*solucaoAtual[j];/// somatorio q utiliza o conjunto solucao anterior para realizar o calculo posteriormente
                }
            }
            solucaoAtual[i] = ((b[i] - novoX)/ matriz[i][i]);/// calcula o valor da variavel x atual isolando-a
        }
}
///---------------------------------------------------------------------------------------------------------------------------
void jacob(double matriz[][100], int ordem, double solucaoAtual[100], double b[100],double solucaoAnterior[100]){ /// Usa a solução anterior nas operacoes, atualizando a solucao após fazer todos os calculos
    for(int i=0; i<ordem; i++){
            double novoX=0; /// somatorio da linha trabalhada para achar o novo valor de Xi
            for (int j = 0; j < ordem; j++) { /// Encontra o valor de cada variavel x, usando as variaveis ja encontradas
                if (i != j){
                    novoX = novoX + matriz[i][j]*solucaoAnterior[j];/// somatorio q utiliza o conjunto solucao anterior para realizar o calculo posteriormente
                }
            }
            solucaoAtual[i] = ((b[i] - novoX)/ matriz[i][i]);
        }
}
///---------------------------------------------------------------------------------------------------------------------------

int main()
{
    ifstream entrada;
    double A[100][100], x[100], xold[100], b[100], e=1; /// A = sitema(matriz) / x= solucao do sistema / xold= solucao anterior / b= resposta do sistema
    int ordem, it=1;

    entrada.open("matriz.txt");

    entrada >> ordem;

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            entrada >> A[i][j];
            cout << A[i][j] << " ";
        }

        entrada >> b[i];
        x[i]=0;
        xold[i]=0;
         cout << "| "<< b[i] << endl;
    }

    while(e > 1e-10){
        cout << endl;
        cout << "=====================================================================" << endl;
        cout << "iteracao: " << it << endl;
        gaussSeidel(A,ordem,x,b);
        //jacob(A,ordem,x,b, xold);
        e=0;
        cout << "X" << it << "={";
        for(int i =0;i<ordem;i++){ /// Mostra a solucao, calcula o erro e atualiza a solucao anterior
            e= e + fabs(x[i]- xold[i]);
            xold[i] = x[i];
            cout << x[i] << ",";
        }
        cout << "}" << endl;
        cout << "Erro: " << e << endl;
        it++;
    }
    return 0;
}

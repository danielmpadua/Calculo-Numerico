#include <iostream>
#include <math.h>

using namespace std;

void newton(float x[],float y[],float Of[],float Ot[],int pontos,int qtdResp){
    int cont = 1; /// Distancia entre a subtração dos pontos
    float auxOt[2]; /// Os dois valores da subtração

    cout << "Valores de O zero: " << endl;
    for(int i=0; i < pontos; i++){
        Ot[i] = y[i];
        cout << Ot[i] << " ";
    }
    cout << endl;

    Of[0] = Ot[0];

    for(int i = 1; i<pontos; i++){
        int k=i;
        for(int j=0; j < qtdResp; j++){
            auxOt[0] = Ot[j];
            auxOt[1] = Ot[j+1];

            Ot[j] = (auxOt[1] - auxOt[0])/(x[k]-x[k-cont]);
            k++;
        }
        Of[i] = Ot[0];
        cont ++;
        qtdResp --;
    }
    cout << "Primeiro valor de cada O: " << endl;
    for(int i=0; i< pontos; i++){
        cout << Of[i] <<" ";
    }
    cout << endl << endl;
    cout << "-------------------" << endl;
    cout << ">> Gerando P(X): <<" << endl;
    cout << "-------------------" << endl;
    cout << endl << endl;
    cout << "P(X) = ";

    for(int i=0; i< pontos; i++){
        int k=0;
        cout << Of[i];
        for(cont = pontos - i; cont < pontos; cont++){
            cout << "(X";
            if(x[k] < 0){
                cout << "+" << fabs(x[k]) << ")";
            }else{
                cout << "-" << x[k] << ")";
            }
            k++;
        }
        if(Of[i+1] >= 0 && i+1<pontos){
            cout <<"+";
        }
    }
    cout << endl << endl;
}
///---------------------------------------------------------------------------------------
void gregoryNewton(float x[],float y[],float Of[],float Ot[],int pontos,int qtdResp){
    int cont = 1; /// Distancia entre a subtração dos pontos
    float auxOt[2]; /// Os dois valores da subtração

    cout << "Valores de O zero: " << endl;
    for(int i=0; i < pontos; i++){
        Ot[i] = y[i];
        cout << Ot[i] << " ";
    }
    cout << endl;

    Of[0] = Ot[0];

    for(int i = 1; i<pontos; i++){
        int k=i;
        float h = x[cont]-x[0];

        for(int j=0; j < qtdResp; j++){
            auxOt[0] = Ot[j];
            auxOt[1] = Ot[j+1];
            Ot[j] = (auxOt[1] - auxOt[0])/h;
            k++;
        }
        Of[i] = Ot[0];
        cont ++;
        qtdResp --;
    }
    cout << "Primeiro valor de cada O: " << endl;
    for(int i=0; i< pontos; i++){
        cout << Of[i] <<" ";
    }
    cout << endl << endl;
    cout << "-------------------" << endl;
    cout << ">> Gerando P(X): <<" << endl;
    cout << "-------------------" << endl;
    cout << endl << endl;
    cout << "P(X) = ";

    for(int i=0; i< pontos; i++){
        int k=0;
        cout << Of[i];
        for(cont = pontos - i; cont < pontos; cont++){
            cout << "(X";
            if(x[k] < 0){
                cout << "+" << fabs(x[k]) << ")";
            }else{
                cout << "-" << x[k] << ")";
            }
            k++;
        }
        if(Of[i+1] >= 0 && i+1<pontos){
            cout <<"+";
        }
    }
    cout << endl << endl;
}
///---------------------------------------------------------------------------------------
int main()
{
    int pontos;

    cout << "Insira a quantidade de pontos que serao usados na interpolacao: ";
    cin >> pontos;
    cout << endl;

    int qtdResposta = pontos-1;
    float X[pontos], Y[pontos], Ofinal[pontos], Otemporario[qtdResposta];
    bool metodo = true;

    cout << ">> Cadastro de pontos: <<" << endl;
    for(int i=0; i<pontos; i++){
        cout << "Insira o valor de X para o ponto " << i+1 << ": ";
        cin >> X[i];
        cout << "Insira o valor de Y para o ponto " << i+1 << ": ";
        cin >> Y[i];
    }
    cout << "Pontos cadastrados com sucesso!" << endl;
    cout << endl;

    float respostaX = X[1] - X[0];

    for(int i=1; i<pontos-1; i++){ /// Verifica se o espaçamento de X é constante e decide qual metodo usar.
        float tempResposta = X[i+1] - X[i];
        if(respostaX != tempResposta){
            metodo = false;
            break;
        }
    }

    if(metodo){
        cout << " /--------------------------------------------\\" << endl;
        cout << "| >> Sera aplicado o metodo Gregory/Newton <<  |" << endl;
        cout << " \\--------------------------------------------/" << endl;
        cout << endl;
        gregoryNewton(X,Y,Ofinal,Otemporario,pontos,qtdResposta);
    }else{
        cout << " /--------------------------------------------\\" << endl;
        cout << "| >>     Sera aplicado o metodo Newton     <<  |" << endl;
        cout << " \\--------------------------------------------/" << endl;
        cout << endl;
        newton(X,Y,Ofinal,Otemporario,pontos, qtdResposta);
    }


    return 0;
}

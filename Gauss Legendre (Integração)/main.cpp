#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double funcao(double x){
    return sin(3*x);
}

double somatorio(double a[], double f[], int pontos){
    double soma=0;
    for(int k=0; k<pontos; k++){
        soma = soma + (a[k]*f[k]);
    }
    return soma;
}

int main()
{
    int numTabela = 77;
    int cont =0;
    int pontos;

    ifstream arquivo;
    arquivo.open("Tabela.txt"); ///Abre o arquivo

    cout << "Insira a quantidade de pontos (de 2 a 8): ";
    cin >> pontos;

    while (pontos < 2 || pontos >8){
        cout << "Valor invalido!" << endl;
        cout << "Insira a quantidade de pontos (de 2 a 8): ";
        cin >> pontos;
    }

    double i[pontos],x[pontos],f[pontos],a[pontos];
    double auxPontos, interA = 0.0,interB = 3.14, resposta;


    while(cont < numTabela){
        arquivo >> auxPontos;
        if(auxPontos == pontos){
            break;
        }
        cont++;
    }
    cout << endl;
    cout << " >> Dados da tabela de acordo com a quantidade de pontos: <<" << endl<< endl;
    cout << "    i     |      A" << endl;
    for(int k= 0; k<pontos; k++){
        arquivo >> i[k];
        arquivo >> a[k];
        x[k] = ((interB-interA)/2)*i[k]+((interB+interA)/2); /// atribui os valores para x
        f[k] = funcao(x[k]); /// atribui os valores para f(x)
        cout << i[k] <<  " | " << a[k] << endl;
    }
    cout << endl;

    resposta = somatorio(a,f,pontos);
    resposta = resposta * ((interB-interA)/2);
    cout << "Resposta: "<< resposta << endl;



    return 0;
}

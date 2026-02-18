#include <iostream>
#include <locale>
#include <windows.h>
#include <iomanip>
#include <ctime>   
#include <cstdlib> 

using namespace std;

char correto = 'O';
char posicaoErrada = 'X';
char errado = '_';

int algarismo1(int resposta){
    return resposta / 1000; 
}

int algarismo2(int resposta){
    return resposta % 1000 / 100; 
}

int algarismo3(int resposta){
    return resposta % 1000 % 100 / 10; 
}

int algarismo4(int resposta){
    return resposta % 1000 % 100 % 10; 
}

bool respostaValida(int algarismo1, int algarismo2, int algarismo3, int algarismo4){
    if ((algarismo1 >= 1 && algarismo1 <= 6 ) &&
        (algarismo2 >= 1 && algarismo2 <= 6 ) &&
        (algarismo3 >= 1 && algarismo3 <= 6 ) &&
        (algarismo4 >= 1 && algarismo4 <= 6 )){
        return true;
    }
    else {
        return false;
    }  
}

char verificacao1(int n1, int n2, int n3, int n4, int algarismo1){
    if (algarismo1 == n1){
        return correto;
    }
    else if (algarismo1 == n2 || algarismo1 == n3 || algarismo1 == n4){
        return posicaoErrada;
    }
    else {
        return errado;
    }
}

char verificacao2(int n1, int n2, int n3, int n4, int algarismo2){
    if (algarismo2 == n2){
        return correto;
    }
    else if (algarismo2 == n1 || algarismo2 == n3 || algarismo2 == n4){
        return posicaoErrada;
    }
    else {
        return errado;
    }
}

char verificacao3(int n1, int n2, int n3, int n4, int algarismo3){
    if (algarismo3 == n3){
        return correto;
    }
    else if (algarismo3 == n1 || algarismo3 == n2 || algarismo3 == n4){
        return posicaoErrada;
    }
    else {
        return errado;
    }
}

char verificacao4(int n1, int n2, int n3, int n4, int algarismo4){
    if (algarismo4 == n4){
        return correto;
    }
    else if (algarismo4 == n1 || algarismo4 == n2 || algarismo4 == n3){
        return posicaoErrada;
    }
    else {
        return errado;
    }
}

bool resultadoFinal(int n1, int n2, int n3, int n4, int algarismo1, int algarismo2, int algarismo3, int algarismo4){
    if (algarismo1 == n1 && algarismo2 == n2 && algarismo3 == n3 && algarismo4 == n4){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    cout << "Esse é um jogo para você, meu caro competidor, que quer ser desafiado a acertar a minha senha secreta de 4 dígitos!" << endl;
    cout << endl;
    cout << "O jogo funciona assim:" << endl;
    cout << "Os algarismos da senha vão de 1 a 6" << endl;
    cout << "Para cada tentativa, você receberá embaixo dos respectivos algarismos, uma dica:" << endl;
    cout << endl;
    cout << "\"_\" significa que não há esse algarismo na senha;" << endl;
    cout << "\"X\" significa que há esse algarismo na senha, mas você errou a sua posição;" << endl;
    cout << "\"O\" significa que há esse algarismo na senha e você acertou a sua posição;" << endl;
    cout << endl;

    srand(time(0)); 

    int senha = (rand() % 6 + 1) + ((rand() % 6 + 1) * 10) + ((rand() % 6 + 1) * 100) + ((rand() % 6 + 1) * 1000); 
    
    int n1 = algarismo1(senha);
    int n2 = algarismo2(senha);
    int n3 = algarismo3(senha);
    int n4 = algarismo4(senha);

    cout << "Digite quantas tentativas gostaria de ter para adivinhar a senha: ";
    int t; 
    cin >> t;

    int resposta;

    int a1; 
    int a2;
    int a3;
    int a4;

    for (int x = 1; x <= t; x++){
        do{
            if (x < t){
                cout << "Tentativa nº" << x << ": ";
            }
            else if (t == 1){
                cout << "Só UMA chance: ";
            }
            else {
                cout << "ÚLTIMA CHANCE: ";
            }

            cin >> resposta;

            if (!cin) { 
                cin.clear();
                cin.ignore(1000, '\n'); 
                cout << "Entrada inválida! Digite apenas 1 número com 4 algarismos de 1 a 6." << endl; 
                continue; 
            }

            char resto = cin.peek(); 
            if (resto != '\n' && resto != ' ') { 
                cin.ignore(1000, '\n');
                cout << "Entrada inválida! Digite exatamente 4 algarismos de 1 a 6." << endl;
                continue;
            }

            cin.ignore(1000, '\n'); 

            a1 = algarismo1(resposta);
            a2 = algarismo2(resposta);
            a3 = algarismo3(resposta);
            a4 = algarismo4(resposta);

            if (!respostaValida(a1, a2, a3, a4)){
                cout << "Entrada inválida! Digite apenas 1 número com 4 algarismos de 1 a 6." << endl;   
                continue;
            }

            break;

        } while (true); 

        cout << setw(16) << verificacao1(n1, n2, n3, n4, a1); 
        cout << verificacao2(n1, n2, n3, n4, a2);
        cout << verificacao3(n1, n2, n3, n4, a3);
        cout << verificacao4(n1, n2, n3, n4, a4);
        cout << endl;

        if (resultadoFinal(n1, n2, n3, n4, a1, a2, a3, a4)){
            cout << "Parabéns! Você acertou a senha!" << endl;
            break;
        }
    }    

    if (!resultadoFinal(n1, n2, n3, n4, a1, a2, a3, a4) && t > 0){
        cout << "Mandou mal!" << endl;
        cout << "A senha era: " << senha << endl;
    }

    return 0;
}
#include <iostream>
#include "Sincronizador.cpp"
#include "Escriba.h"
#include <list>
#include <string>
#include <ctype.h>
#include <sstream>



// TODO: Criar uma classe que somente lê listas informadas pelo usuário
// em diversas sintaxes e "quebra em listas que possam ser processadas
// olhar o arquivo main1.cpp no dropbox

using namespace std;

void exibeMenu(){

    cout << "1) Informar listas (enter, informa; fração é métrica, esc, sai)" << endl;
    cout << "2) Sincronizar listas" << endl;
    cout << "3) Derivar listas numéricas" << endl;
    cout << "4) Reverter lista" << endl;
    cout << "5) Recuperar" << endl;
    cout << "Esc para encerrar" << endl;

}

void preencheListas(list<int> &duracoes, list<string> &alturas, string input){
    int i;
    stringstream ss;
    size_t pos;
	pos = input.find(',');
	while(pos!=string::npos)
	{
		string num = input.substr(0,pos);
		input.erase(0,pos+1);
		ss.str(num);

		ss >> i;

		if (!ss.fail()){
			duracoes.push_back(i);
		}else{

			alturas.push_back(num);

		}
		pos = input.find(',');
		ss.clear();
		ss.str("");
	}
	ss.str(input);
	ss >> i;
	if (!ss.fail()){
		duracoes.push_back(i);
	}else{

		alturas.push_back(input);

	}
	//numbers.push_back(i);
	ss.clear();
	ss.str("");

}


int main(){

    Sincronizador<string> s;
    // Sincronizador<string> alturas;

    list<int> duracoes;
    list<string> alturas;

    string text, line;

    char opcaoMenu =0;

    while( ((int)(opcaoMenu)) != 27 ){

        exibeMenu();
        cin >> opcaoMenu;

        cout << opcaoMenu << endl;
        switch(opcaoMenu){

            case '1':
                cout << "Informar listas" << endl;
                cin >> text;
                preencheListas(duracoes, alturas, text);

                for(auto a : duracoes){
                    cout << a << endl;
                }

                for(auto a : alturas){
                    cout << a << endl;
                }

            break;

            case '2':
                cout << "Sincronizar listas" << endl;
                if (alturas.empty() || duracoes.empty()){
                    cout << "Preencha as duas listas para sincronizá-las!" << endl;
                }else{

                    //s.associaAlturasDuracoes(alturas, duracoes);
                }

            break;

            case '3':
                cout << "Derivar listas numéricas" << endl;

            break;

            case '4':
                cout << "Acumular listas numéricas" << endl;

            break;

            case '5':
                cout << "Reverter listas" << endl;

            break;

            case '6':
                cout << "Recuperar" << endl;

            break;

            case 27:
                system("exit");
            break;


        }

    }


    return 0;
}

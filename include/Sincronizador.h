#ifndef SINCRONIZADOR_H
#define SINCRONIZADOR_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

//!  Classe responsável pelos arquivo de saída
/*!
  Essa classe faz a conversão das alturas e durações para um arquivo .ly,
  entendido pelo Lilypond.
  Também executa a separação em uma lista de alturas e outra de durações a partir
  de uma entrada no formato: a1, c1, d1, e1 (exemplo de entrada)

*/


template <class T> class Sincronizador{

    // usado para armazenar a união das listas desdobradas até o limite do mmc
    map <int, int> uniaoDeTabuadasOrdenadas;


    // inteirosParaSincronizacao -> usada para fazer o desdobramento das listas numéricas.
    // O resultado dos desdobramentos é passado para um map com a união dos valores
    list<int> inteirosParaSincronizacao;

    // entradas -> lista que armazena as entradas de duração do usuário
    list<int> entradas;


    // listaDerivadaDiscreta -> armazena a derivada discreta ou a diferença entre
    // os elementos da lista de união
    list<int> listaDerivadaDiscreta;


    list<string> alturas;
    list<string> alturasDesdobradas;





    int resultadoMMC;



    list<int> lista1, lista2;

    public:
        Sincronizador();
        virtual ~Sincronizador();



        //! Une listas de durações através de um dicionário
        /*!
            inteirosParaSincronizacao contém os inteiros a serem sincronizados. Cada elemento é multiplicado
            por um contador de 0 ao mmc informado. Dessa forma, é feita uma tabuada (multiplicação)
            de 0 ao MMC, tendo como base o elemento da lista.
            Ex: mmc = 6, elementos: 2 e 3
            0*2=0, 1*2=2, 2*2=4, 3*2=6, 4*2=8, 5*2=10, 6*2=12
            0*3=0, 1*3=3, 2*3=6, 3*3=9, 4*3=12
            Une esses elementos no dicinonário usando cada resultado da tabuada como
            chave do dicinonário, garantindo que eles só ocorram uma vez
            A união dos elementos da inteirosParaSincronizacao fica: 0,2,3,4,6,8,9,10,12

            @param inteirosParaSincronizacao: lista com durações que serão sincronizadas
            @param resultadoMMC: limite para sincronização das listas
            @param uniaoDeTabuadasOrdenadas: dicionário contendo as listas unidas, sem repetições e ordenadas
        */
        void uneListasDeDuracoes(list<int>&inteirosParaSincronizacao, int resultadoMMC, map <int,int> &uniaoDeTabuadasOrdenadas);


       //! Faz associação um a um entre durações e alturas
        /*!
            Dadas uma lista com as alturas e outra com as durações,
            retorna um dicinonário com a combinação das alturas e durações (listas unitárias apenas)

            @param listaAlturas: alturas que serão associadas
            @param listaDesdobramentoAlturas: contém as repetições de alturas quando a listaAlturas é desdobrada
            @param duracoes: lista com as durações que serão associadas
        */
        void associaAlturasDuracoes(list<string> &listaAlturas, list<int> &duracoes);

        int coeficienteDeRepeticoes(int MMClistasEnvolvidas, int somatorioElementosLista);


        //! Calcula o MMC.
        /*!
            recebe dois valores numéricos inteiros e calcula o MMC.

            @param num1: primeiro valor para calcular MMC
            @param num2: segundo valor para calcular MMC
            @param return: retorna o mmc das entradas
        */
        int mmc(int num1, int num2);


        //! Calcula o MMC com mais de dois elementos.
        /*!
            recebe uma lista de valores numéricos para calcular o MMC.

            @param entradas: lista com todos os valores para serem calculados o MMC
            @param inteirosParaSincronizacao: recebe os valores da lista de entrada (backup da lista)
            @param return: retorna o mmc das entradas
        */
        int calculaMMC(list<int> &entradas, list<int> &inteirosParaSincronizacao);


        //! Ordena listas.
        /*!
            Recebe uma lista desordenada como parâmetro e a ordena.
            Esse ordenação é somente de tipos que já possuam operadores definidos (tipos numéricos e alfanuméricos).

            @param listaNaoOrdenada: lista que será ordenada.
        */
        void ordenaLista(list<T> &listaNaoOrdenada);




        //! Acumula (soma) os valores de uma lista.
        /*!
            Recebe na entrada uma lista que terá seus elementos somados, iniciando em zero
            até o elemento final da lista.
            Os valores são colocados na listaAcumulada de forma crescente.

            @param listaParaAcumular: lista que será somada.
            @param listaAcumulada: lista contendo o resultado.

        */
        void acumuladorDeListas(list<T> &listaParaAcumular, list<T> &listaAcumulada);

        //! Desdobra/Repete uma lista.
        /*!
            Desdobra/repete o parâmetro listaParaDesdobrar n vezes e guarda o
            resultado em listaResultante.

            @param listaParaDesdobrar: lista que será desdobrada/repetida
            @param numeroDeRepeticoes: quantidade de vezes que a listaParaDesdobrar será repetida
            @param listaResultante: guarda as repetições. É a saída da função
        */
        void desdobraListas (list<T> &listaParaDesdobrar, int numeroDeRepeticoes, list<T> &listaResultante);


        //! Sincroniza o tamanho de duas listas numéricas.
        /*!
            Informadas duas listas numéricas, elas são desdobradas (repetidas)
            até possuírem o mesmo tamanho e tem seus elementos unidos, ordenados e
            com repetições removidas. Só funciona com números, já que a saída é o vetor
            intervalar (derivada discreta) das duas listas.


            @param lista1: primeira lista de entrada para ser sincronizada.
            @param lista2: segunda lista de entrada para ser sincronizada.

        */
        void sincronizaListasApenasNumeros(list<T> &lista1, list<T> &lista2);


        //! Dadas duas listas, realiza uma união entre elas.
        /*!
            Dadas duas listas na entrada, faz uma operação de união
            entre elas duas colocando o resultado dentro de listaUnida.

            @param lista1: primeira lista de entrada para a união.
            @param lista2: segunda lista de entrada para a união.
            @param listaUnida: resultado da união das duas listas.

        */
        void uneListas(list<T> &lista1, list<T> &lista2, list<T> &listaUnida);

        //! Dada uma lista contendo repetições de elementos, faz uma remoção desses valores.
        /*!

            @param listaComRepeticoes: lista para remover repetições.
            @param listaSemRepeticoes: lista sem repetições de elementos.


        */
        void removeRepeticoes(list<T> &listaComRepeticoes, list<T> &listaSemRepeticoes);


        //! Calcula o vetor intervalar de uma lista.
        /*!

            Dada uma lista numérica, retorna como resultado uma
            lista contendo a derivada discreta (elemento sucessor menos elemento antecessor)
            dessa lista. Apenas lista numéricas.

            @param listaParaDerivar: entrada contendo os valores numéricos.
            @param listaDerivadaDiscreta: lista resultante.


        */
        void calculaDerivadaDiscreta (list<T> &listaParaDerivar, list<T> &listaDerivadaDiscreta);

        //! Calcula o vetor intervalar de uma lista.
        /*!

            Sobrecarga do método descrito acima. Usa um dicionário
            para calcular o vetor intervalar da lista informada na entrada.

            @param uniaoDeTabuadasOrdenadas: mapa contendo o vetor intervalar unido, sem repetições e ordenado.
            @param listaDerivadaDiscreta: lista resultante.


        */
        void calculaDerivadaDiscreta (map <int,int> &uniaoDeTabuadasOrdenadas, list<int> &listaDerivadaDiscreta);

    protected:

    private:
        T accumulate (T first, T last, T init);
};

#endif // SINCRONIZADOR_H

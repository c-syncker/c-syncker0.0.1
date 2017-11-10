#ifndef ESCRIBA_H
#define ESCRIBA_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;


//!  Classe responsável pelos arquivo de saída
/*!
  Essa classe faz a conversão das alturas e durações para um arquivo .ly,
  entendido pelo Lilypond.
  Também executa a separação em uma lista de alturas e outra de durações a partir
  de uma entrada no formato: a1, c1, d1, e1 (exemplo de entrada)

*/

class Escriba
{

    // Declaração do dicionário contendo as notas
    unordered_map<int, string> dicionarioDuracoesFigLilypond;


    string filename;


    list<string> listaNotasParaEscriba;
    list<string> alturasExtraidasDaMelodia;
    list<string> listaDuracoes;


    public:
        //! Construtor da classe Escriba.
        /*!
            Construtor sem parâmetros de Escriba.
            Inicializa o dicionário com alturas coringa e atribui um nome padrão
            ao arquivo lilypond (notas.ly)
        */
        Escriba();

        //! Construtor sobrecarregado da classe Escriba.
        /*!
            Construtor que recebe como parâmetro o nome do arquivo ly.
            Inicializa o dicionário com alturas coringa e atribui o nome
            ao arquivo lilypond.
        */

        Escriba(string filename);
        virtual ~Escriba();

        //! Separa alturas e durações.
        /*!
            recebe uma entrada no formato altura+duracao (a2, c1, d1, e2),
            uma lista de alturas e uma lista de durações vazias. Devolve, após
            processamento, a entrada separada em alturas e durações (a c d e | 2 1 1 2)
            dentro de suas respectivas listas;

            @param input: uma lista com as alturas e durações. Ex: (a2, c1, d1, e2)
            @param alturasExtraidasDaMelodia: saída contendo todas as alturas extraídas da entrada
            @param listaDuracoes: saída contendo todas as durações extraídas da entrada
        */
        void separaAlturasDeDuracoes(string input,list<string> &alturasExtraidasDaMelodia, list<string> &listaDuracoes);


        //! Substitui uma altura e duração no dicionário de durações.
        /*!
            recebe como entrada um dicionario contedo as alturas e durações, uma lista
            com alturas e uma lista com durações.
            Usa cada elemento da lista de durações como índice do dicionário para
            buscar um shape (forma?) que processe a altura dada corretamente
            (dicionário = a16          entrada =>  altura = c duração  1)
            se transforma em:
            dicionario[1] = a16 -> a = c --> c16 essa é a string final enviada para o lilypond


            @param dicionarioDuracoes: dicionário com os caracteres reconhecidos pelo Lilypond
            @param listaAlturas: alturas que irão ser escritas no arquivo Lilypond
            @param listaDuracoes: durações usadas como índices do dicionário para achar a altura correspondente
            @param saida: string contendo as notas que serão escritas no arquivo a ser compilado pelo Lilypond
        */
        string substituiAlturaCoringaDoDicionarioDeDuracoes(unordered_map<int, string> &dicionarioDuracoes, list<string> &listaAlturas,
                                                            list<string> &listaDuracoes);

        //! Retorna o nome do arquivo .ly.
        string getFilename();

        //! Gera o arquivo de saída do Lilypond.
        /*!
            recebe como parâmetros uma lista com as alturas e durações
            e as escreve no arquivo passado como parâmetro com extensão
            .ly


            @param listaNotasParaEscriba: notas já substituídas no dicionario de durações para escrever no Lilypond
            @param filename: nome do arquivo gerado na saída
        */
        void geraArquivoLilypond(list<string> listaNotasParaEscriba, string filename);


        //! Executa o Lilypond
        /*!
            Realiza uma chamada de sistema que executa o lilypond para converter o arquivo
            gerado pela função geraArquivoLilypond em arquivo PDF

           @param filename: nome do arquivo gerado na saída
        */
        void initLilypond(string filename);

    protected:

    private:


};

#endif // ESCRIBA_H

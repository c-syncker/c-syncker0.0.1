#include "Escriba.h"


Escriba::Escriba(){
    filename = "notas.ly";
    dicionarioDuracoesFigLilypond[1] = "c16";
    dicionarioDuracoesFigLilypond[2] = "c8";
    dicionarioDuracoesFigLilypond[3] = "c8.";
    dicionarioDuracoesFigLilypond[4] = "c4";
    dicionarioDuracoesFigLilypond[5] = "c4~c16";
    dicionarioDuracoesFigLilypond[6] = "c4.";
    dicionarioDuracoesFigLilypond[7] = "c4.~c16";
    dicionarioDuracoesFigLilypond[8] = "c2";
    dicionarioDuracoesFigLilypond[9] = "c2~c16";
    dicionarioDuracoesFigLilypond[10] = "c2~c8";
    dicionarioDuracoesFigLilypond[11] = "c2~c8.";
    dicionarioDuracoesFigLilypond[12] = "c2.";
    dicionarioDuracoesFigLilypond[13] = "c2.~c16";
    dicionarioDuracoesFigLilypond[14] = "c2.~c8";
    dicionarioDuracoesFigLilypond[15] = "c2.~c8.";
    dicionarioDuracoesFigLilypond[16] = "c1";
    dicionarioDuracoesFigLilypond[17] = "c1~c16";
    dicionarioDuracoesFigLilypond[18] = "c1~c8";
    dicionarioDuracoesFigLilypond[19] = "c1~c8.";
    dicionarioDuracoesFigLilypond[20] = "c1~c4";
    dicionarioDuracoesFigLilypond[21] = "c1~c4~c16";
    dicionarioDuracoesFigLilypond[22] = "c1~c4.";
    dicionarioDuracoesFigLilypond[23] = "c1~c4~c8.";
    dicionarioDuracoesFigLilypond[24] = "c1.";
    dicionarioDuracoesFigLilypond[25] = "c1.~c16";
    dicionarioDuracoesFigLilypond[26] = "c1.~c8";
    dicionarioDuracoesFigLilypond[27] = "c1.~c8.";
    dicionarioDuracoesFigLilypond[28] = "c1.~c4";
    dicionarioDuracoesFigLilypond[29] = "c1.~c4~c16";
    dicionarioDuracoesFigLilypond[30] = "c1.~c4";
    dicionarioDuracoesFigLilypond[31] = "c1~c2.~c8.";
}

Escriba::Escriba(string filename){
    this->filename = filename;
    dicionarioDuracoesFigLilypond[1] = "c16";
    dicionarioDuracoesFigLilypond[2] = "c8";
    dicionarioDuracoesFigLilypond[3] = "c8.";
    dicionarioDuracoesFigLilypond[4] = "c4";
    dicionarioDuracoesFigLilypond[5] = "c4~c16";
    dicionarioDuracoesFigLilypond[6] = "c4.";
    dicionarioDuracoesFigLilypond[7] = "c4.~c16";
    dicionarioDuracoesFigLilypond[8] = "c2";
    dicionarioDuracoesFigLilypond[9] = "c2~c16";
    dicionarioDuracoesFigLilypond[10] = "c2~c8";
    dicionarioDuracoesFigLilypond[11] = "c2~c8.";
    dicionarioDuracoesFigLilypond[12] = "c2.";
    dicionarioDuracoesFigLilypond[13] = "c2.~c16";
    dicionarioDuracoesFigLilypond[14] = "c2.~c8";
    dicionarioDuracoesFigLilypond[15] = "c2.~c8.";
    dicionarioDuracoesFigLilypond[16] = "c1";
    dicionarioDuracoesFigLilypond[17] = "c1~c16";
    dicionarioDuracoesFigLilypond[18] = "c1~c8";
    dicionarioDuracoesFigLilypond[19] = "c1~c8.";
    dicionarioDuracoesFigLilypond[20] = "c1~c4";
    dicionarioDuracoesFigLilypond[21] = "c1~c4~c16";
    dicionarioDuracoesFigLilypond[22] = "c1~c4.";
    dicionarioDuracoesFigLilypond[23] = "c1~c4~c8.";
    dicionarioDuracoesFigLilypond[24] = "c1.";
    dicionarioDuracoesFigLilypond[25] = "c1.~c16";
    dicionarioDuracoesFigLilypond[26] = "c1.~c8";
    dicionarioDuracoesFigLilypond[27] = "c1.~c8.";
    dicionarioDuracoesFigLilypond[28] = "c1.~c4";
    dicionarioDuracoesFigLilypond[29] = "c1.~c4~c16";
    dicionarioDuracoesFigLilypond[30] = "c1.~c4";
    dicionarioDuracoesFigLilypond[31] = "c1~c2.~c8.";
}

Escriba::~Escriba(){

}

void Escriba::geraArquivoLilypond(list<string> listaNotasParaEscriba, string filename){

    /*
        recebe como parâmetros uma lista com as alturas e durações
        e as escreve no arquivo passado como parâmetro com extensão
        .ly

    */

    cout <<"Abrindo o arquivo " << filename << " ..." <<endl;

    ofstream wrt;
    wrt.open(filename);

    if(wrt.is_open()){
        for (std::list<string>::const_iterator listIterator = listaNotasParaEscriba.begin(); listIterator != listaNotasParaEscriba.end(); ++listIterator)
        {
            wrt << *listIterator;
        }
        wrt.close();
        cout << "Arquivo gravado com sucesso!" << endl;
    }else{
        cout << "Arquivo não encontrado!" << endl;
    }
}

void Escriba::initLilypond(string filename){

    /*
        inicia o lilypond para converter o arquivo
        gerado pela função geraArquivoLilypond em arquivo PDF
    */

    string command, pdf_file;
    //inicializa o lilypond para a conversão
    cout << "Iniciando o Lilypond!" << endl;
    command = "lilypond " + filename;
    const char *x = command.c_str();
    system(x);

    // inicializa o evince para renderizar o pdf
    pdf_file = filename + ".pdf";
    command = "evince " + pdf_file;
    x = command.c_str();
    system(x);
}


void Escriba::separaAlturasDeDuracoes(string input,list<string> &listaAlturas, list<string> &listaDuracoes){


    /*
        recebe uma entrada no formato altura+duracao (a2, c1, d1, e2),
        uma lista de alturas e uma lista de durações vazias. Devolve, após
        processamento, a entrada separada em alturas e durações (a c d e | 2 1 1 2)
        dentro de suas respectivas listas;
    */


    string entrada, alturas, duracoes;
    entrada = input;
    // expressão regular para ler os valores numéricos de 0..9 da entrada
    regex altura("[[:digit:]]+");
     // expressão regular que trata todas as palavras na entrada
    regex duracao("[[:alpha:]]+");

    // formata a entrada com espaços vazios para separar altura e duração
    const string format="";

    // primeiro separa todas as listaAlturas da entrada
    alturas = regex_replace(entrada, altura, format, regex_constants::format_default);
    // separa as durações na entrada
    duracoes = regex_replace(entrada, duracao, format, regex_constants::format_default);

    // adiciono cada altura da string de listaAlturas (a) numa lista removendo os separadores
    for(auto it: alturas){
        if(it != ','){
            if(it != ' ')
            listaAlturas.push_back(string(1, it));
        }

    }

    // adiciono cada duração da string de durações (d) numa lista removendo os separadores
    string aux_string;
    for(auto it: duracoes){ // itera pela string para substituir as vírgulas
        if(it == ','){
            it = '0'; // substitui a vírgula com um caractere de vazio
        }else{
            aux_string += it;
        }
    }

    istringstream iss(aux_string); // cria um stream sobre a string sem vírgulas
    string subs;
    do{
        iss >> subs; // a cada espaço, substitui o conteúdo em subs pelo valor antes do espaço
        listaDuracoes.push_back(subs); // adiciono na lista de durações
    }while(getline(iss, subs, ' ')); // a string de durações é da forma [2 1 1 2]
                                    // remove os espaços colocando cada elemento na lista de durações

}



string Escriba::substituiAlturaCoringaDoDicionarioDeDuracoes(unordered_map<int, string> &dicionarioDuracoes, list<string> &listaAlturas,
                                list<string> &listaDuracoes){

    /*
        recebe como entrada um dicionario contedo as alturas e durações, uma lista
        com alturas e uma lista com durações.
        Usa cada elemento da lista de durações como índice do dicionário para
        buscar um shape (forma?) que processe a altura dada corretamente
        (dicionário = a16          entrada =>  altura = c duração  1)
        se transforma em:
        dicionario[1] = a16 -> a = c --> c16 essa é a string final enviada para o lilypond

    */

    string aux;
    int indice;

    while(listaDuracoes.size() != 0){
        string formataDuracoes = listaAlturas.front(); // substitui no dicionário de durações com a primeira
                                                     // ocorrência (topo) da lista de alturas
        listaAlturas.pop_front();   // apaga o topo para avançar na lista

        // essa regex vai substituir as alturas no dicionário pela altura desejada
        regex substituiAlturasDicionarioDuracoes("[[:alpha:]]+");

        indice = stoi( listaDuracoes.front() ); // converto para inteiro as durações para usar como
                                                // índices no dicionário

        // utiliza a regex_replace para pegar o valor do dicionário de durações
        // e substituir pela entrada do usuário
        aux += regex_replace(dicionarioDuracoes[indice], substituiAlturasDicionarioDuracoes,
                            formataDuracoes, regex_constants::format_default) + " ";
        listaDuracoes.pop_front();
    }
    // cout << aux << " "; // exibo os resultados que irão ser impressos no lilypond
    return aux;
}

string Escriba::getFilename(){
    return filename;
}
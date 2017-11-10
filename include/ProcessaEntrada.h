#ifndef PROCESSAENTRADA_H
#define PROCESSAENTRADA_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

class ProcessaEntrada
{
    public:
        ProcessaEntrada();
        virtual ~ProcessaEntrada();
        void converteEmListas(string entrada, list<string> listaDeSaida);
        void converteEmListas(string entrada, list<int> listaDeSaida);


    protected:

    private:
};

#endif // PROCESSAENTRADA_H

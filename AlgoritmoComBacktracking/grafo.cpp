/*
 ===============================================================================
 ARQUIVO............: grafo.cpp
 COMENTARIOS........: Codigo responsavel por implementar o grafo que usamos no
            ........: trabalho, sobre o sudoku
 ===============================================================================
 AUTOR..............: Samuel Nata
                      Thales Aguiar
                      Vitor Godeiro
                      Disciplina: Grafos - DIM0549
                      Instituto Metropole Digital
                      Universidade Federal do Rio Grande do Norte
                      Natal, Rio Grande do Norte, Brasil
 ULTIMA MODIFICACAO.: 28 de maio de 2016
 ===============================================================================
*/

/* ========================================================================= */
/* INCLUDES                                                                  */
/* ------------------------------------------------------------------------- */
#include "grafo.h"
#include <iostream>
#include <thread>

/* ========================================================================= */
/* CLASSE GRAFO                                                              */
/* ------------------------------------------------------------------------- */
Grafo::Grafo(unsigned int ordem)
{
    this->_ordem = ordem;
    this->_ordem0 = geraRaiz(ordem);
    this->_numeroVertices = ordem*ordem;

    this->_matrizAdjacencia = new bool*[this->_numeroVertices];
    for (unsigned int i = 0; i < this->_numeroVertices; i++)
        this->_matrizAdjacencia[i] = new bool[this->_numeroVertices];
    geraMatrizAdjacencia();


    _saturacao = new int[_numeroVertices];

    for(unsigned int i = 0; i < _numeroVertices; i++)
        _saturacao[i] = 0;

}

Grafo::~Grafo()
{
    for (unsigned int i = 0; i < this->_numeroVertices; i++)
        delete []this->_matrizAdjacencia[i];
    delete[]this->_matrizAdjacencia;
}


unsigned int Grafo::geraRaiz(unsigned int numero)
{
    unsigned int auxiliar = numero/2;
    for(unsigned int n = 0; n <= auxiliar; n++)
    {
       if((n*n) == numero)
           return n;
    }
    return 0;
}

void Grafo::geraMatrizAdjacencia()
{

    for (unsigned int i = 0; i <_numeroVertices; i++)
    {
        for(unsigned int j = 0; j < _numeroVertices; j++)
        {
            if(j >= (i/_ordem)*_ordem && j < (i/_ordem)*_ordem + _ordem)
                _matrizAdjacencia[i][j] = true;
            else
                if(j%_ordem == i%_ordem)
                    _matrizAdjacencia[i][j] = true;
            else
                _matrizAdjacencia[i][j] = false;

        }
    }

    for (unsigned int i = 0; i < _numeroVertices; i++)
    {
        for(unsigned int f = 0; f < _ordem0;f++)
        {
            for(unsigned int k = 0; k < _ordem0; k++)
            {
                if((i/_ordem)%_ordem0 == 0 )
                    for(unsigned int j =0; j < _ordem0; j ++)
                    {
                        _matrizAdjacencia[i+_ordem*f][(i/_ordem0)*_ordem0+j + _ordem*k] = true;
                    }
            }
       }
    }

}

bool Grafo::grafoColorindo(unsigned int color[])
{


    int *saturacao = new int[_numeroVertices];

    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(!color[i])
            saturacao[i] = 0;
        else
            saturacao[i] = -1;
    }





    if(!grafoColorindoAuxiliar(color,0, saturacao))
        return false;
    else
        return true;

}

unsigned int Grafo::numeroVertices() const
{
    return _numeroVertices;
}

unsigned int Grafo::ordem0() const
{
    return _ordem0;
}

unsigned int Grafo::ordem() const
{
    return _ordem;
}

int Grafo::getSaturacaoMaior(int saturacao[],unsigned int cor[])
{

    int contador = 0;

    int auxiliar;
    int pos = 0;
    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(saturacao[i] != -1 || cor[i] == 0)
        {
            auxiliar = 0;
            for(unsigned int j = 0; j < _numeroVertices; j++)
            {

                if(_matrizAdjacencia[i][j]  && cor[j] > 0 )
                    auxiliar ++;
            }

            if(pos < auxiliar)
            {
                pos = auxiliar;
                contador = i;
            }

        }
    }

    saturacao[contador] = -1;
    return contador;
}

bool Grafo::saturacaoCheia(int saturacao[])
{
    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(saturacao[i] != -1)
            return true;

    }

    return false;
}

void Grafo::geraSaturacao(unsigned int color[])
{
     for(unsigned int i = 0; i < _numeroVertices; i++)
     {
        if(color[i])
        {
            _saturacao[i] = -1;
        }
        else
            if(_saturacao[i] == -1)
                _saturacao[i] = 0;
    }
}

void Grafo::incrementaSaturacao(int contador, int saturacao[])
{
    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(_matrizAdjacencia[contador][i] &&  saturacao[i] != -1)
        {
            saturacao[i]++;
        }
    }
}

void Grafo::decrementaSaturacao(int contador,int saturacao[])
{
    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(_matrizAdjacencia[contador][i] &&  saturacao[i] > 0)
        {
            saturacao[i]--;
        }
    }
}


bool Grafo::grafoColorindoAuxiliar(unsigned int color[], unsigned int contador, int saturacao[])
{


    if(!saturacaoCheia(saturacao))
        return true;

    int cor = getSaturacaoMaior(saturacao, color);

    if(color[cor])
    {
        saturacao[cor] = -1;
        if(grafoColorindoAuxiliar(color, contador +1, saturacao))
            return true;
        else
            return false;
    }

    for(unsigned int i = 1; i <= _ordem; i++)
    {
        if(verificaCor(cor,color,i))
        {
            if(color[cor] == 0)
            {
                color[cor] = i;
                saturacao[cor]    = -1;

            }

            if(grafoColorindoAuxiliar(color, contador +1, saturacao))
                return true;

            color[cor] = 0;

        }
    }


    saturacao[cor] = 0;
    return false;
}

bool Grafo::verificaCor(unsigned int contador, unsigned int color[], unsigned int aux)
{
    for(unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(_matrizAdjacencia[contador][i] && aux == color[i])
            return false;
    }

    return true;
}


/*
 ===============================================================================
 ARQUIVO............: grafo.h
 COMENTARIOS........: Codigo responsavel por implementar o tabuleiro do jogo
            ........: sudoku
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
#include "tabuleiro.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* ========================================================================= */
/* CLASSE TABULEIRO                                                          */
/* ------------------------------------------------------------------------- */

Tabuleiro::Tabuleiro(unsigned int ordem)
{
    _ordem = ordem;
    _numeroVertices = _ordem*_ordem;

    _tabelaJogo = new unsigned int [_numeroVertices];
    //inicializa as cores da tabela
    for (unsigned int i = 0; i < _numeroVertices; i++)
        _tabelaJogo[i] = 0;
}

Tabuleiro::~Tabuleiro()
{
    delete [] _tabelaJogo;
}

std::string  Tabuleiro::imprimeJogo()
{
    std::string auxiliar;
    for (unsigned int i = 0; i < _numeroVertices; i++)
    {
        if(i % _ordem == 0 && i)
            auxiliar += "\n";
        if(_tabelaJogo[i] < 10)
            auxiliar += "0";
        auxiliar += std::to_string(_tabelaJogo[i]) + " ";
    }
    auxiliar += "\n";
    return auxiliar;
}

void Tabuleiro::gerarTabuleiroAleatorio()
{
    int x, y;

    srand (time(NULL));
    int vetor[_ordem] = {0};
    for(unsigned int i = 1; i < _ordem ; i++)
    {

        x = rand()%_ordem +1;

        y = rand()%_numeroVertices;
        if(!vetor[x])
        {
            vetor[x] = 1;
            _tabelaJogo[y] = x;
        }
        else
            i--;

    }
}

void Tabuleiro::zerarTabuleiro()
{
    for(unsigned int i = 0; i < _numeroVertices; i++)
        _tabelaJogo[i] = 0;
}


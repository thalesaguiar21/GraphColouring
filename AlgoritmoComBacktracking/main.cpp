/*
 ===============================================================================
 ARQUIVO............: main.cpp
 COMENTARIOS........: Codigo-fonte principal.
 ===============================================================================
 AUTOR..............: Samuel Nata
                      Thales Aguiar
                      Vitor Godeiro
                      Disciplina: Grafos - DIM0549
                      Instituto Metropole Digital
                      Universidade Federal do Rio Grande do Norte
                      Natal, Rio Grande do Norte, Brasil
 ULTIMA MODIFICACAO.: 28 de maio de 2016
 PARA COMPILAR......: QtCreator
 PARA EXECUTAR......:
 ===============================================================================
*/


/* ========================================================================= */
/* INCLUDES                                                                  */
/* ------------------------------------------------------------------------- */

#include "grafo.h"
#include "tabuleiro.h"
#include "mainwindow.h"
#include <iostream>
#include <QApplication>


/* ========================================================================= */
/* FUNCAO PRINCIPAL                                                          */
/* ------------------------------------------------------------------------- */



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


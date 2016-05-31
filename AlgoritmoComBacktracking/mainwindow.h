/*
 ===============================================================================
 ARQUIVO............: mainwindow.cpp
 COMENTARIOS........: Codigo responsavel por implementar a interface
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
#include <QMainWindow>
#include "grafo.h"
#include "tabuleiro.h"

/* ========================================================================= */
/* CLASSE MAINWINDOW                                                         */
/* ------------------------------------------------------------------------- */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    static void solucionaJogo(MainWindow *window);


private slots:
    void on_btn_Atualizar_clicked();
    void on_btn_GerarVazio_clicked();
    void on_btn_GerarJogo_clicked();
    void on_btn_Solucionar_clicked(bool checked);
    void on_btn_Solucionar_clicked();

private:
    Ui::MainWindow *ui;
    Grafo *_grafo;
    Tabuleiro *_tabela;
    unsigned int _ordem;

    /**
     * @brief   verificaRaiz, metodo responsavel por verificar se o numero possui raiz quardada.
     * @param   numero, é um unsigned int, a qual sera analisado.
     * @return  true, se a variavel (numero) possui raiz quadrada.
     * @return  false, se a variavel (numero) não possuir raiz.
     */
    bool verificaRaiz(unsigned int numero);

    bool auxiliar;

};

#endif // MAINWINDOW_H

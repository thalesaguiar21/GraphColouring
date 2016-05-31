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
#include <string>
#include <thread>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*========================================================================== */
/* CLASSE Interface                                                          */
/* ------------------------------------------------------------------------- */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Solucionador de Sudoku");
    _grafo = new Grafo(0);
    _tabela = new Tabuleiro(0);
    auxiliar = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _grafo;
    delete _tabela;
}

void MainWindow::on_btn_Atualizar_clicked()
{
    QString aux = ui->lE_Ordem->text();
    unsigned int ordem = aux.toInt();
    _ordem = ordem;
    if(aux == "")
    {
        ui->tb_Informacoes->setText("Entrada vazia, por favor entre com um número válido.");
    }
    else
        if(verificaRaiz(ordem))
        {
            std::string info;
            delete _grafo;
            delete _tabela;
            _grafo = new Grafo(ordem);
            _tabela = new Tabuleiro(ordem);

            info = "Ordem do sudoku: " + std::to_string(_grafo->ordem()) ;
            info += "\nOrdem da grade menor: " + std::to_string(_grafo->ordem0());
            info+= "\nNúmero de vértices: " + std::to_string(_grafo->numeroVertices());
            ui->tb_Informacoes->setText(QString::fromStdString(info));
        }
    else
        ui->tb_Informacoes->setText("Número da entrada não possui raiz quadrada, por favor entre com um número válido.");

}

bool MainWindow::verificaRaiz(unsigned int numero)
{
    unsigned int auxiliar = numero/2;
    for(unsigned int n = 0; n <= auxiliar; n++)
    {
       if((n*n) == numero)
           return true;
    }
    return false;
}

void MainWindow::solucionaJogo(MainWindow *window)
{
    window->_grafo->grafoColorindo(window->_tabela->_tabelaJogo);
    window->auxiliar = true;
}

void MainWindow::on_btn_GerarVazio_clicked()
{
     _tabela->zerarTabuleiro();
    ui->tb_Jogo->setText(QString::fromStdString(_tabela->imprimeJogo()));
}

void MainWindow::on_btn_GerarJogo_clicked()
{
    _tabela->zerarTabuleiro();
    _tabela->gerarTabuleiroAleatorio();
    ui->tb_Jogo->setText(QString::fromStdString(_tabela->imprimeJogo()));
}

void MainWindow::on_btn_Solucionar_clicked(bool checked)
{

}

void MainWindow::on_btn_Solucionar_clicked()
{

    QString aux = ui->tb_Jogo->toPlainText();
    QStringList list2 = aux.split(" ", QString::SkipEmptyParts);

    for(unsigned int i = 0; i <_grafo->numeroVertices(); i++)
        _tabela->_tabelaJogo[i] = list2[i].toInt();

    std::clock_t clock_1, clock_2;
    clock_1 = std::clock();
    bool verificaSucesso =_grafo->grafoColorindo(_tabela->_tabelaJogo);
    clock_2 = std::clock();
    ui->tb_Jogo->setText(QString::fromStdString(_tabela->imprimeJogo()));
    std::string info;
        info = "Ordem do sudoku: " + std::to_string(_grafo->ordem()) ;
        info += "\nOrdem da grade menor: " + std::to_string(_grafo->ordem0());
        info+= "\nNúmero de vértices: " + std::to_string(_grafo->numeroVertices());
        ui->tb_Informacoes->setText(QString::fromStdString(info));
        aux = ui->tb_Informacoes->toPlainText();
        aux += "\nTempo para solucionar: ";
        aux += QString::number((double)(clock_2-clock_1)/(double)CLOCKS_PER_SEC) + "s";
        if(verificaSucesso)
            aux+= "\nColoriu com sucesso.";
        else
            aux+= "\nProblema ao colorir, verifique o sudoku.";
        ui->tb_Informacoes->setText(aux);

}



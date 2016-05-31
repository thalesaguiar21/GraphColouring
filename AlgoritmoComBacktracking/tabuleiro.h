/*
 ===============================================================================
 ARQUIVO............: tabuleiro.h
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
#include <string>


/* ========================================================================= */
/* CLASSE TABULEIRO                                                          */
/* ------------------------------------------------------------------------- */


#ifndef TABULEIRO_H
#define TABULEIRO_H



class Tabuleiro
{
public:
    Tabuleiro(unsigned int ordem);
    ~Tabuleiro();

    unsigned int *_tabelaJogo; //Responsavel pro armazenar as cores da tabela do jogo

    /**
     * @brief   imprimeJogo, metodo responsavel por retornar a tabela do jogo
     * @param   void
     * @return  string, que é a string da tabela do jogo
     */
    std::string imprimeJogo();

    /**
     * @brief   gerarTabuleiroAleatorio, metodo responsavel por gerar uma configuracao inicial valida para o
     *          tabuleiro do sudoku
     * @param   void
     * @return  void
     */
    void gerarTabuleiroAleatorio();

    /**
     * @brief   zerarTabuleiro, metodo responsavel por zerar todo o sudoku, limpando todo o tabuleiro
     * @param   void
     * @return  void
     */
    void zerarTabuleiro();
private:
    unsigned int _ordem;
    unsigned int _numeroVertices;

};

#endif // TABULEIRO_H

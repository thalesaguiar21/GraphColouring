/*
 ===============================================================================
 ARQUIVO............: grafo.h
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
#ifndef GRAFO_H
#define GRAFO_H


class Grafo
{
public:
    Grafo(unsigned int ordem);
    ~Grafo();

    /**
     * @brief   grafoColorindo, metodo responsavel por geir a  coloracao do sudoku.
     * @param   color, é o vetor de cores pre-existentes no sudoku.
     * @return  true, se deu certo.
     * @return  false, se deu errado.
     */
    bool grafoColorindo(unsigned int color[]);


    unsigned int numeroVertices() const;
    unsigned int ordem0() const;
    unsigned int ordem() const;

private:
    bool **_matrizAdjacencia;
    unsigned int _ordem;
    unsigned int _ordem0; // ordem da raiz, do quadrado menor exemplo se o sudoku tiver odem 9 , _ordem0 == 3
    unsigned int _numeroVertices;


    /**
     * @brief   geraRaiz, metodo responsavel por verificar se o numero possui raiz quardada.
     * @param   numero, é um unsigned int, a qual sera analisado.
     * @return  se a variavel (numero) possui raiz quadrada retorna a raiz.
     * @return  se a variavel (numero) não possuir raiz retorna zero (0).
     */
    unsigned int geraRaiz(unsigned int numero);


    /**
     * @brief   geraMatrizAdjacencia, metodo responsavel por gerar a matriz de adjancencia para um sudoku, com a ordem == _ordem.
     * @param   void.
     * @return  void.
     */
    void geraMatrizAdjacencia();


    /**
     * @brief   grafoColorindoAuxiliar, metodo recursivo responsavel por fazer a coloracao dos vertices.
     * @param   color, vetor de inteiros contendo todas as cores que colorem cada vertice.
     * @param   contador,inteiro representando qual o vertice estamos verificando no momento.
     * @return  true, se posso colorir com aquela cor o determinado vertice.
     * @return  false, se nao posso colorir com aquele cor o determinado vertice.
     */
    bool grafoColorindoAuxiliar(unsigned int color[], unsigned int contador);


    /**
     * @brief   verificaCor, metodo responsavel por verificar se os vertices adjacentes estao colorido com a mesma
     *          cor que eu desejo colorir.
     * @param   contador, inteiro representando qual o vertice estamos verificando no momento.
     * @param   color, vetor de inteiros contendo todas as cores que colorem cada vertice.
     * @param   aux, inteiro indicando a cor que quero colorir.
     * @return  true, se os vertices adjacentes nao possuem a cor que quero colorir.
     * @return  false, se os vertices adjacentes possuem a cor que quero colorir.
     */
    bool verificaCor(unsigned int contador,unsigned int color[], unsigned int aux);

};

#endif // GRAFO_H

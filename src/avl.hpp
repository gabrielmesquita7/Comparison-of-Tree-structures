#ifndef AVL_HPP
#define AVL_HPP

#include "tree.hpp"

typedef struct AvlTree AvlTree;

struct AvlTree
{
	Record reg;
	AvlTree *left, *right;
	int weight;
};

AvlTree *Avl_CreateTree();
void Avl_insertTree(AvlTree **t, Record r);
void Avl_pesquisa(AvlTree **t, AvlTree **aux, Record r);
int Avl_isInTree(AvlTree *t, Record r);

// muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void Avl_removeTree(AvlTree **t, AvlTree **f, Record r);
void Avl_antecessor(AvlTree **t, AvlTree *aux);
void Avl_rebalanceTree(AvlTree **t);

int getWeight(AvlTree **t);
int getMaxWeight(int left, int right);

void Avl_preordem(AvlTree *t);
void Avl_central(AvlTree *t);
void Avl_posordem(AvlTree *t);

void rotacaoSimplesDireita(AvlTree **t);
void rotacaoSimplesEsquerda(AvlTree **t);
void rotacaoDuplaDireita(AvlTree **t);
void rotacaoDuplaEsquerda(AvlTree **t);

#endif

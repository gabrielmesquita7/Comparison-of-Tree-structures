#include "avl.hpp"

AvlTree *Avl_CreateTree()
{
	return NULL;
}

void Avl_insertTree(AvlTree **t, Record r)
{

	if (*t == NULL)
	{
		*t = (AvlTree *)malloc(sizeof(AvlTree));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r;
	}
	else
	{

		if (r.key < (*t)->reg.key)
		{
			Avl_insertTree(&(*t)->left, r);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2)
			{
				if (r.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}

		if (r.key > (*t)->reg.key)
		{
			Avl_insertTree(&(*t)->right, r);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2)
			{
				if (r.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void Avl_pesquisa(AvlTree **t, AvlTree **aux, Record r)
{

	if (*t == NULL)
	{
		return;
	}

	if ((*t)->reg.key > r.key)
	{
		Avl_pesquisa(&(*t)->left, aux, r);
		return;
	}
	if ((*t)->reg.key < r.key)
	{
		Avl_pesquisa(&(*t)->right, aux, r);
		return;
	}

	*aux = *t;
}

int Avl_isInTree(AvlTree *t, Record r)
{

	if (t == NULL)
	{
		return 0;
	}

	return t->reg.key == r.key || Avl_isInTree(t->left, r) || Avl_isInTree(t->right, r);
}

void Avl_antecessor(AvlTree **t, AvlTree *aux)
{

	if ((*t)->right != NULL)
	{
		Avl_antecessor(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void Avl_rebalanceTree(AvlTree **t)
{
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);
}

void Avl_removeTree(AvlTree **t, AvlTree **f, Record r)
{
	AvlTree *aux;

	if (*t == NULL)
	{
		return;
	}

	if (r.key < (*t)->reg.key)
	{
		Avl_removeTree(&(*t)->left, t, r);
		return;
	}
	if (r.key > (*t)->reg.key)
	{
		Avl_removeTree(&(*t)->right, t, r);
		return;
	}

	if ((*t)->right == NULL)
	{
		aux = *t;
		*t = (*t)->left;
		free(aux);
		Avl_rebalanceTree(f);
		return;
	}

	if ((*t)->left != NULL)
	{
		Avl_antecessor(&(*t)->left, *t);
		Avl_rebalanceTree(t);
		Avl_rebalanceTree(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	Avl_rebalanceTree(t);
	Avl_rebalanceTree(f);
}

void Avl_preordem(AvlTree *t)
{
	if (!(t == NULL))
	{
		cout << setprecision(6) << fixed << "" << t->reg.key << ":" << t->weight << "\t";
		Avl_preordem(t->left);
		Avl_preordem(t->right);
	}
}

void Avl_central(AvlTree *t)
{
	if (!(t == NULL))
	{
		Avl_central(t->left);
		cout << " \t" << t->reg.key;
		Avl_central(t->right);
	}
}

void Avl_posordem(AvlTree *t)
{
	if (!(t == NULL))
	{
		Avl_posordem(t->left);
		Avl_posordem(t->right);
		cout << " \t" << t->reg.key;
	}
}

int getWeight(AvlTree **t)
{
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right)
{
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(AvlTree **t)
{
	AvlTree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(AvlTree **t)
{
	AvlTree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(AvlTree **t)
{
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(AvlTree **t)
{
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}

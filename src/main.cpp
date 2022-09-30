#include "avl.hpp"

int main()
{
	int reg[] = {10, 2, 7, 5, 3, 9, 16, 4, 11, 1, 6, 23, 14};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	AvlTree *Avlraiz = Avl_CreateTree();

	for (int i = 0; i < 13; i++)
	{
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
		Avl_insertTree(&Avlraiz, r);
	}

	cout << "Arvore Binaria: { ";
	preordem(raiz);
	cout << "}\n\n";

	cout << "Arvore Avl: { ";
	Avl_preordem(Avlraiz);
	cout << "}\n\n";
}
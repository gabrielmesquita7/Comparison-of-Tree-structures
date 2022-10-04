#include "avl.hpp"
#include "rb.hpp"

int main()
{
	int reg[] = {10, 2, 7, 5, 3, 9, 16, 4, 11, 1, 6, 23, 14};
	Record r;
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	AvlTree *Avlraiz = Avl_CreateTree();
	RBTree bst;

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

	bst.insert(30);
	bst.insert(20);
	bst.insert(15);
	bst.insert(17);
	bst.insert(44);
	bst.insert(25);
	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(9);
	bst.insert(10);
	bst.insert(1);
	bst.insert(89);
	bst.insert(13);
	bst.insert(100);
	bst.insert(200);
	bst.prettyPrint();
	return 0;
}

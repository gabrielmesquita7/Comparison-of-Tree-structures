#include "tree.hpp"

int main()
{
	int reg[] = {5, 3, 7, 2, 4, 6, 1};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	cout << "Árvore vazia: " << TVazia(&raiz) << endl;

	cout << "ELEMENTOS DA ARVORE: {";

	for (int i = 0; i < 7; i++)
	{
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
		cout << " " << reg[i];
	}

	cout << "}" << endl;

	cout << "Árvore vazia: " << TVazia(&raiz) << "\n\n";

	cout << "METODO PREORDEM: { ";
	preordem(raiz);
	cout << "}\n\n";

	cout << "METODO CENTRAL: { ";
	central(raiz);
	cout << "}\n\n";

	cout << "METODO POSORDEM: { ";
	posordem(raiz);
	cout << "}\n\n";

	r.key = 3;
	pesquisa(&raiz, &aux, r);

	cout << "PESQUISA 2 E IMPRIME A SUBARVORE { ";
	preordem(aux);
	cout << "}\n\n";

	r.key = 3;
	removeTree(&raiz, r);

	cout << "REMOVE 3 E IMPRIME A ARVORE { ";
	central(raiz);
	cout << "}\n\n";
}
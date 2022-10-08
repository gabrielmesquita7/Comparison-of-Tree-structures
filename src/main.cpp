#include "tools.hpp"

int main()
{
	Record r;
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	AvlTree *Avlraiz = Avl_CreateTree();
	RBTree Rb;

	// raiz = InsertDataBinaryT("data.txt", 500000);
	// Avlraiz = InsertDataAvlT("data.txt", 500000);
	Rb = InsertDataRbT("data.txt", 10);

	Rb.prettyPrint();
	string word;
	ifstream file;
	file.open("search.txt");
	if (file.is_open() == false)
	{
		cout << "Arquivo nao encontrado!" << endl;
		abort();
	}
	while (file.good())
	{
		string buffer;
		while (getline(file, buffer))
		{
			stringstream ss(buffer);
			ss.imbue(locale(locale(), new word_reader(" ")));
			while (ss >> word)
			{
				r.key = StringToNumber<float>(word);
				Rb.deleteNode(StringToNumber<float>(word));
			}
		}
	}
	// RemoveDataRbT("search.txt", Rb);
	// RemoveDataAvlT("search.txt", Avlraiz);
	// RemoveDataBinaryT("search.txt", raiz);

	Rb.prettyPrint();
	// cout << "Arvore Binaria: { ";
	// preordem(raiz);
	// cout << "}\n\n";

	// cout
	// 	<< "Arvore Avl: { ";
	// Avl_preordem(Avlraiz);
	// cout << "}\n\n";

	for (auto i : deleted_elements)
	{
		cout << setprecision(6) << fixed << i << " ";
	}
	cout << "\n";
	return 0;
}

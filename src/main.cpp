#include "time.hpp"

int main()
{
	measure_timeInsert(500);
	cout << "-----------------------------------------------------------" << endl;
	cout << "500 ENTRADAS:" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de ordenação do vetor: " << VectorTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	measure_timeInsert(5000);
	cout << "-----------------------------------------------------------" << endl;
	cout << "5.000 ENTRADAS:" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de ordenação do vetor: " << VectorTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	measure_timeInsert(50000);
	cout << "-----------------------------------------------------------" << endl;
	cout << "50.000 ENTRADAS:" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de ordenação do vetor: " << VectorTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	measure_timeInsert(500000);
	cout << "-----------------------------------------------------------" << endl;
	cout << "500.000 ENTRADAS:" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de insercao Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de ordenação do vetor: " << VectorTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	measure_timeSearch();
	cout << "-----------------------------------------------------------" << endl;
	cout << "500.000 ENTRADAS : PESQUISA" << endl;
	cout << setprecision(9) << fixed << "Tempo de pesquisa Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de pesquisa Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de pesquisa Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	measure_timeRemove();
	cout << "-----------------------------------------------------------" << endl;
	cout << "500.000 ENTRADAS : REMOCAO" << endl;
	cout << setprecision(9) << fixed << "Tempo de remocao Arvore Binaria: " << binaryTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de remocao Arvore Avl: " << AvlTime << "(segundos)" << endl;
	cout << setprecision(9) << fixed << "Tempo de remocao Arvore RedBlack: " << RBTime << "(segundos)" << endl;
	cout << "-----------------------------------------------------------" << endl;
	resetTimes();

	// for (auto i : deleted_elements)
	// {
	// 	cout << setprecision(6) << fixed << i << " ";
	// }
	// cout << "\n";
	return 0;
}

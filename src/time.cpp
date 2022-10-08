#include "time.hpp"

double binaryTime;
double AvlTime;
double RBTime;

void resetTimes()
{
    binaryTime = 0.000000000;
    AvlTime = 0.000000000;
    RBTime = 0.000000000;
}

void measure_timeInsert(int qtd)
{
    auto start1 = chrono::high_resolution_clock::now();
    Tree *raiz = CreateTree();
    raiz = InsertDataBinaryT("data.txt", qtd);
    auto end1 = chrono::high_resolution_clock::now();
    binaryTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

    auto start2 = chrono::high_resolution_clock::now();
    AvlTree *Avlraiz = Avl_CreateTree();
    Avlraiz = InsertDataAvlT("data.txt", qtd);
    auto end2 = chrono::high_resolution_clock::now();
    AvlTime = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();

    auto start3 = chrono::high_resolution_clock::now();
    RBTree Rb;
    Rb = InsertDataRbT("data.txt", qtd);
    auto end3 = chrono::high_resolution_clock::now();
    RBTime = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();

    // convert to seconds
    binaryTime *= 1e-9;
    AvlTime *= 1e-9;
    RBTime *= 1e-9;
}

void measure_timeSearch()
{
    Tree *raiz = CreateTree();
    AvlTree *Avlraiz = Avl_CreateTree();
    RBTree Rb;

    raiz = InsertDataBinaryT("data.txt", 500000);
    Avlraiz = InsertDataAvlT("data.txt", 500000);
    Rb = InsertDataRbT("data.txt", 500000);

    auto start1 = chrono::high_resolution_clock::now();
    searchDataBinaryT("search.txt", raiz);
    auto end1 = chrono::high_resolution_clock::now();
    binaryTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    auto start2 = chrono::high_resolution_clock::now();
    searchDataAvlT("search.txt", Avlraiz);
    auto end2 = chrono::high_resolution_clock::now();
    AvlTime = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();

    auto start3 = chrono::high_resolution_clock::now();
    searchDataRB("search.txt", Rb);
    auto end3 = chrono::high_resolution_clock::now();
    RBTime = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();

    // convert to seconds
    binaryTime *= 1e-9;
    AvlTime *= 1e-9;
    RBTime *= 1e-9;
}

void measure_timeRemove()
{
    string word;
    ifstream file;
    Tree *raiz = CreateTree();
    AvlTree *Avlraiz = Avl_CreateTree();
    RBTree Rb;

    raiz = InsertDataBinaryT("data.txt", 500000);
    Avlraiz = InsertDataAvlT("data.txt", 500000);
    Rb = InsertDataRbT("data.txt", 500000);

    auto start1 = chrono::high_resolution_clock::now();
    RemoveDataBinaryT("search.txt", raiz);
    auto end1 = chrono::high_resolution_clock::now();
    binaryTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

    auto start2 = chrono::high_resolution_clock::now();
    RemoveDataAvlT("search.txt", Avlraiz);
    auto end2 = chrono::high_resolution_clock::now();
    AvlTime = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();

    auto start3 = chrono::high_resolution_clock::now();
    // remove data Rb tree//
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
                Rb.deleteNode(StringToNumber<float>(word));
            }
        }
    }
    // remove data Rb tree//
    auto end3 = chrono::high_resolution_clock::now();
    RBTime = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();

    // convert to seconds
    binaryTime *= 1e-9;
    AvlTime *= 1e-9;
    RBTime *= 1e-9;
}
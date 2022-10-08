#include "time.hpp"

double binaryTime;
double AvlTime;
double RBTime;
double VectorTime;
double MapTime;
double UnorderedMapTime;

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

    auto start4 = chrono::high_resolution_clock::now();
    vector<float> vetor;
    vetor = InsertDataVector("data.txt", qtd);
    sort(vetor.begin(), vetor.end());
    auto end4 = chrono::high_resolution_clock::now();
    VectorTime = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();

    // convert to seconds
    binaryTime *= 1e-9;
    AvlTime *= 1e-9;
    RBTime *= 1e-9;
    VectorTime *= 1e-9;
}

void measure_timeSearch()
{
    map<float, int> datamap;
    unordered_map<float, int> unordmap;
    Tree *raiz = CreateTree();
    AvlTree *Avlraiz = Avl_CreateTree();
    RBTree Rb;

    datamap = InsertDataMap("data.txt");
    unordmap = InsertDataUnordMap("data.txt");
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

    auto start4 = chrono::high_resolution_clock::now();
    searchDataUnordMap("search.txt", unordmap);
    auto end4 = chrono::high_resolution_clock::now();
    MapTime = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();

    auto start5 = chrono::high_resolution_clock::now();
    searchDataMap("search.txt", datamap);
    auto end5 = chrono::high_resolution_clock::now();
    UnorderedMapTime = chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();

    // convert to seconds
    binaryTime *= 1e-9;
    AvlTime *= 1e-9;
    RBTime *= 1e-9;
    MapTime *= 1e-9;
    UnorderedMapTime *= 1e-9;
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

void measure_time()
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
    cout << setprecision(9) << fixed << "Tempo de pesquisa Map: " << MapTime << "(segundos)" << endl;
    cout << setprecision(9) << fixed << "Tempo de pesquisa Unordered_Map: " << UnorderedMapTime << "(segundos)" << endl;
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
}
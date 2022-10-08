#include "tools.hpp"

Tree *InsertDataBinaryT(string filename, int qtd)
{
    Tree *raiz = CreateTree();
    int iz = 0;
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                if (iz == qtd)
                {
                    break;
                }
                r.key = StringToNumber<float>(word);
                insertTree(&raiz, r);
                iz++;
            }
        }
    }
    return raiz;
}

AvlTree *InsertDataAvlT(string filename, int qtd)
{
    AvlTree *Avlraiz = Avl_CreateTree();
    int iz = 0;
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                if (iz == qtd)
                {
                    break;
                }
                r.key = StringToNumber<float>(word);
                Avl_insertTree(&Avlraiz, r);
                iz++;
            }
        }
    }
    return Avlraiz;
}

RBTree InsertDataRbT(string filename, int qtd)
{
    RBTree Rb;
    int iz = 0;
    string word;
    ifstream file;
    file.open(filename);
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
                if (iz == qtd)
                {
                    break;
                }
                Rb.insert(StringToNumber<float>(word));
                iz++;
            }
        }
    }
    return Rb;
}

vector<float> InsertDataVector(string filename, int qtd)
{
    vector<float> vetor;
    vector<float>::iterator it;
    int iz = 0;
    string word;
    ifstream file;
    file.open(filename);
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
                if (iz == qtd)
                {
                    break;
                }
                it = vetor.begin();
                vetor.insert(it, StringToNumber<float>(word));
                iz++;
            }
        }
    }
    return vetor;
}

map<float, int> InsertDataMap(string filename)
{
    map<float, int> datamap;
    int iz = 1;
    string word;
    ifstream file;
    file.open(filename);
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
                datamap.insert(pair<float, int>(StringToNumber<float>(word), iz));
                iz++;
            }
        }
    }
    return datamap;
}
unordered_map<float, int> InsertDataUnordMap(string filename)
{
    unordered_map<float, int> dataunordmap;
    int iz = 1;
    string word;
    ifstream file;
    file.open(filename);
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
                dataunordmap.insert(pair<float, int>(StringToNumber<float>(word), iz));
                iz++;
            }
        }
    }
    return dataunordmap;
}

void searchDataBinaryT(string filename, Tree *raiz)
{
    Tree *aux;
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                pesquisa(&raiz, &aux, r);
            }
        }
    }
}

void searchDataAvlT(string filename, AvlTree *Avlraiz)
{
    AvlTree *aux;
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                Avl_pesquisa(&Avlraiz, &aux, r);
            }
        }
    }
}

void searchDataRB(string filename, RBTree rb)
{
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                rb.searchTree(r.key);
            }
        }
    }
}

void searchDataMap(string filename, map<float, int> datamap)
{
    map<float, int>::iterator it;
    string word;
    ifstream file;
    file.open(filename);
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
                it = datamap.find(StringToNumber<float>(word));
            }
        }
    }
}
void searchDataUnordMap(string filename, unordered_map<float, int> unordmap)
{
    unordered_map<float, int>::iterator it;
    string word;
    ifstream file;
    file.open(filename);
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
                it = unordmap.find(StringToNumber<float>(word));
            }
        }
    }
}

void RemoveDataBinaryT(string filename, Tree *raiz)
{
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                removeTree(&raiz, r);
            }
        }
    }
}

void RemoveDataAvlT(string filename, AvlTree *Avlraiz)
{
    Record r;
    string word;
    ifstream file;
    file.open(filename);
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
                Avl_removeTree(&Avlraiz, &Avlraiz, r);
            }
        }
    }
}

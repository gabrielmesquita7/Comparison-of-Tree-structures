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

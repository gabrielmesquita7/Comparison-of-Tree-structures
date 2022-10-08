#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "rb.hpp"
#include "avl.hpp"

struct word_reader : ctype<char> // tokenizer
{
    word_reader(string const &delims) : ctype<char>(get_table(delims)) {}
    static ctype_base::mask const *get_table(string const &delims)
    {
        static vector<ctype_base::mask> rc(table_size, ctype_base::mask());

        for (char ch : delims)
            rc[ch] = ctype_base::space;
        return &rc[0];
    }
};

template <typename T>
T StringToNumber(const std::string &numberAsString)
{
    T valor;

    std::stringstream stream(numberAsString);
    stream >> valor;
    if (stream.fail())
    {
        std::runtime_error e(numberAsString);
        throw e;
    }
    return valor;
}

Tree *InsertDataBinaryT(string filename, int qtd);
AvlTree *InsertDataAvlT(string filename, int qtd);
RBTree InsertDataRbT(string filename, int qtd);

void RemoveDataBinaryT(string filename, Tree *raiz);
void RemoveDataAvlT(string filename, AvlTree *Avlraiz);

#endif
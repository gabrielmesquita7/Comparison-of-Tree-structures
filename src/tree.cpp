#include "tree.hpp"

vector<float> deleted_elements;

Tree *CreateTree()
{
  return NULL;
}

bool TVazia(Tree **t)
{
  return *t == NULL;
}

void insertTree(Tree **t, Record r)
{

  if (TVazia(t))
  {
    *t = (Tree *)malloc(sizeof(Tree));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->reg = r;
  }
  else
  {

    if (r.key < (*t)->reg.key)
    {
      insertTree(&(*t)->esq, r);
    }

    if (r.key > (*t)->reg.key)
    {
      insertTree(&(*t)->dir, r);
    }
  }
}

Tree *pesquisa(Tree *t, Record r)
{
  if (r.key == t->reg.key || t == NULL)
  {
    return t;
  }

  if (t->reg.key > r.key)
  {
    return pesquisa(t->esq, r);
  }
  return pesquisa(t->dir, r);
}

int isInTree(Tree *t, Record r)
{

  if (t == NULL)
  {
    return 0;
  }

  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void antecessor(Tree **t, Tree *aux)
{

  if ((*t)->dir != NULL)
  {
    antecessor(&(*t)->dir, aux);
    return;
  }

  aux->reg = (*t)->reg;
  aux = *t;
  *t = (*t)->esq;
  free(aux);
}

void removeTree(Tree **t, Record r)
{
  Tree *aux;

  if (*t == NULL)
  {
    return;
  }

  if (r.key < (*t)->reg.key)
  {
    removeTree(&(*t)->esq, r);
    return;
  }
  if (r.key > (*t)->reg.key)
  {
    removeTree(&(*t)->dir, r);
    return;
  }

  deleted_elements.push_back((*t)->reg.key);

  if ((*t)->dir == NULL)
  {
    aux = *t;
    *t = (*t)->esq;
    free(aux);
    return;
  }

  if ((*t)->esq != NULL)
  {
    antecessor(&(*t)->esq, *t);
    return;
  }
  aux = *t;
  *t = (*t)->dir;
  free(aux);
}

void preordem(Tree *t)
{
  if (!(t == NULL))
  {
    cout << setprecision(6) << fixed << " " << t->reg.key;
    preordem(t->esq);
    preordem(t->dir);
  }
}

void central(Tree *t)
{
  if (!(t == NULL))
  {
    central(t->esq);
    cout << " " << t->reg.key;
    central(t->dir);
  }
}

void posordem(Tree *t)
{
  if (!(t == NULL))
  {
    posordem(t->esq);
    posordem(t->dir);
    cout << " " << t->reg.key;
  }
}

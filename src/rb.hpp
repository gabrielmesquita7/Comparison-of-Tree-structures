#ifndef RB_HPP
#define RB_HPP

#include "tree.hpp"

struct Node
{
    float data;
    Node *pai;
    Node *left;
    Node *right;
    int color; // 1 -> Red, 0 -> Black
};

typedef Node *NodePtr;

class RBTree
{
private:
    NodePtr root;
    NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr pai);
    void preOrderHelper(NodePtr node);
    void inOrderHelper(NodePtr node);
    void postOrderHelper(NodePtr node);
    NodePtr searchTreeHelper(NodePtr node, float key);
    void fixDelete(NodePtr x);
    void rbTransplant(NodePtr u, NodePtr v);
    void deleteNodeHelper(NodePtr node, float key);
    void fixInsert(NodePtr k);
    void printHelper(NodePtr root, string indent, bool last);

public:
    RBTree();
    void preorder();
    void inorder();
    void postorder();
    NodePtr searchTree(float k);
    NodePtr minimum(NodePtr node);
    NodePtr maximum(NodePtr node);
    NodePtr successor(NodePtr x);
    NodePtr predecessor(NodePtr x);
    void leftRotate(NodePtr x);
    void rightRotate(NodePtr x);
    void insert(float key);
    NodePtr getRoot();
    void deleteNode(float data);
    void prettyPrint();
};

#endif

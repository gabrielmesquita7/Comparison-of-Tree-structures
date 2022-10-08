#include "rb.hpp"

void RBTree::initializeNULLNode(NodePtr node, NodePtr pai)
{
    node->data = 0.0;
    node->pai = pai;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

void RBTree::preOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

void RBTree::inOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

void RBTree::postOrderHelper(NodePtr node)
{
    if (node != TNULL)
    {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        cout << node->data << " ";
    }
}

NodePtr RBTree::searchTreeHelper(NodePtr node, float key)
{
    if (node == TNULL || key == node->data)
    {
        return node;
    }

    if (key < node->data)
    {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

// faz o balanceamento da arvore apos a remoção
void RBTree::fixDelete(NodePtr x)
{
    NodePtr s;
    while (x != root && x->color == 0)
    {
        if (x == x->pai->left)
        {
            s = x->pai->right;
            if (s->color == 1)
            {
                // case 3.1
                s->color = 0;
                x->pai->color = 1;
                leftRotate(x->pai);
                s = x->pai->right;
            }

            if (s->left->color == 0 && s->right->color == 0)
            {
                // case 3.2
                s->color = 1;
                x = x->pai;
            }
            else
            {
                if (s->right->color == 0)
                {
                    // case 3.3
                    s->left->color = 0;
                    s->color = 1;
                    rightRotate(s);
                    s = x->pai->right;
                }

                // case 3.4
                s->color = x->pai->color;
                x->pai->color = 0;
                s->right->color = 0;
                leftRotate(x->pai);
                x = root;
            }
        }
        else
        {
            s = x->pai->left;
            if (s->color == 1)
            {
                // case 3.1
                s->color = 0;
                x->pai->color = 1;
                rightRotate(x->pai);
                s = x->pai->left;
            }

            if (s->right->color == 0 && s->right->color == 0)
            {
                // case 3.2
                s->color = 1;
                x = x->pai;
            }
            else
            {
                if (s->left->color == 0)
                {
                    // case 3.3
                    s->right->color = 0;
                    s->color = 1;
                    leftRotate(s);
                    s = x->pai->left;
                }

                // case 3.4
                s->color = x->pai->color;
                x->pai->color = 0;
                s->left->color = 0;
                rightRotate(x->pai);
                x = root;
            }
        }
    }
    x->color = 0;
}

void RBTree::rbTransplant(NodePtr u, NodePtr v)
{
    if (u->pai == nullptr)
    {
        root = v;
    }
    else if (u == u->pai->left)
    {
        u->pai->left = v;
    }
    else
    {
        u->pai->right = v;
    }
    v->pai = u->pai;
}

void RBTree::deleteNodeHelper(NodePtr node, float key)
{
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL)
    {
        if (node->data == key)
        {
            z = node;
        }

        if (node->data <= key)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    if (z == TNULL)
    {
        return;
    }

    // termina busca
    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL)
    {
        x = z->right;
        rbTransplant(z, z->right);
    }
    else if (z->right == TNULL)
    {
        x = z->left;
        rbTransplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->pai == z)
        {
            x->pai = y;
        }
        else
        {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->pai = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->pai = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 0)
    {
        fixDelete(x);
    }
}

// fix the red-black tree
void RBTree::fixInsert(NodePtr k)
{
    NodePtr u;
    while (k->pai->color == 1)
    {
        if (k->pai == k->pai->pai->right)
        {
            u = k->pai->pai->left; // uncle
            if (u->color == 1)
            {
                // case 3.1
                u->color = 0;
                k->pai->color = 0;
                k->pai->pai->color = 1;
                k = k->pai->pai;
            }
            else
            {
                if (k == k->pai->left)
                {
                    // case 3.2.2
                    k = k->pai;
                    rightRotate(k);
                }
                // case 3.2.1
                k->pai->color = 0;
                k->pai->pai->color = 1;
                leftRotate(k->pai->pai);
            }
        }
        else
        {
            u = k->pai->pai->right; // uncle

            if (u->color == 1)
            {
                // mirror case 3.1
                u->color = 0;
                k->pai->color = 0;
                k->pai->pai->color = 1;
                k = k->pai->pai;
            }
            else
            {
                if (k == k->pai->right)
                {
                    // mirror case 3.2.2
                    k = k->pai;
                    leftRotate(k);
                }
                // mirror case 3.2.1
                k->pai->color = 0;
                k->pai->pai->color = 1;
                rightRotate(k->pai->pai);
            }
        }
        if (k == root)
        {
            break;
        }
    }
    root->color = 0;
}

void RBTree::printHelper(NodePtr root, string indent, bool last)
{
    // print the tree structure on the screen
    if (root != TNULL)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "     ";
        }
        else
        {
            cout << "L----";
            indent += "|    ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << setprecision(6) << fixed << root->data << "(" << sColor << ")" << endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
    // cout<<root->left->data<<endl;
}

RBTree::RBTree()
{
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

// Pre-Order traversal
// Node->Left Subtree->Right Subtree
void RBTree::preorder()
{
    preOrderHelper(this->root);
}

// In-Order traversal
// Left Subtree -> Node -> Right Subtree
void RBTree::inorder()
{
    inOrderHelper(this->root);
}

// Post-Order traversal
// Left Subtree -> Right Subtree -> Node
void RBTree::postorder()
{
    postOrderHelper(this->root);
}

NodePtr RBTree::searchTree(float k)
{
    return searchTreeHelper(this->root, k);
}

// nó com a menor key
NodePtr RBTree::minimum(NodePtr node)
{
    while (node->left != TNULL)
    {
        node = node->left;
    }
    return node;
}

// nó com a maior key
NodePtr RBTree::maximum(NodePtr node)
{
    while (node->right != TNULL)
    {
        node = node->right;
    }
    return node;
}

// sucessor do nó x
NodePtr RBTree::successor(NodePtr x)
{
    if (x->right != TNULL)
    {
        return minimum(x->right);
    }
    NodePtr y = x->pai;
    while (y != TNULL && x == y->right)
    {
        x = y;
        y = y->pai;
    }
    return y;
}

// predecessor do nó x
NodePtr RBTree::predecessor(NodePtr x)
{
    if (x->left != TNULL)
    {
        return maximum(x->left);
    }

    NodePtr y = x->pai;
    while (y != TNULL && x == y->left)
    {
        x = y;
        y = y->pai;
    }

    return y;
}

void RBTree::leftRotate(NodePtr x)
{
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL)
    {
        y->left->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr)
    {
        this->root = y;
    }
    else if (x == x->pai->left)
    {
        x->pai->left = y;
    }
    else
    {
        x->pai->right = y;
    }
    y->left = x;
    x->pai = y;
}

void RBTree::rightRotate(NodePtr x)
{
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
    {
        y->right->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == nullptr)
    {
        this->root = y;
    }
    else if (x == x->pai->right)
    {
        x->pai->right = y;
    }
    else
    {
        x->pai->left = y;
    }
    y->right = x;
    x->pai = y;
}

void RBTree::insert(float key)
{
    NodePtr node = new Node;
    node->pai = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1; // novo nó deve ser vermelho

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    node->pai = y;
    if (y == nullptr)
    {
        root = node;
    }
    else if (node->data < y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    if (node->pai == nullptr)
    {
        node->color = 0;
        return;
    }

    if (node->pai->pai == nullptr)
    {
        return;
    }

    // Fix the tree
    fixInsert(node);
}

NodePtr RBTree::getRoot()
{
    return this->root;
}

void RBTree::deleteNode(float data)
{
    deleteNodeHelper(this->root, data);
}

// print the tree structure on the screen
void RBTree::prettyPrint()
{
    if (root)
    {
        printHelper(this->root, "", true);
    }
}

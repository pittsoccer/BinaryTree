
#include <iostream>
using namespace std;

class BNode
{
    int data;
    BNode *left;
    BNode *right;
    BNode(int d);
    BNode(int d, BNode *l, BNode *r);
    friend class BST;
};

BNode::BNode(int d) : data(d), left(nullptr), right(nullptr) {}
BNode::BNode(int d, BNode *l, BNode *r) : data(d), left(l), right(r) {}

class BST
{
    BNode *root;
    void InsertHelper(int e, BNode *&subroot);
    void PrintInHelper(BNode *subroot) const;

public:
    BST();
    void Insert(int e);
    void PrintIn() const;
    void PrintPre() const;  // FIXME: PrintPre()
    void PrintPost() const; // FIXME: PrintPost()
    void Search() const;    // FIXME: Search()
};

BST::BST() : root(nullptr) {}

void BST::InsertHelper(int e, BNode *&subroot)
{
    if (subroot == nullptr)
    {
        subroot = new BNode(e);
    }
    else if (e == subroot->data)
    {
        cout << "NO DUPES" << endl;
    }
    else if (e < subroot->data)
    {
        InsertHelper(e, subroot->left);
    }
    else // e > subroot->data
    {
        InsertHelper(e, subroot->right);
    }
}

void BST::Insert(int e)
{
    InsertHelper(e, root);
}

void BST::PrintInHelper(BNode *subroot) const
{
    if (subroot != nullptr)
    {
        PrintInHelper(subroot->left);
        cout << subroot->data << endl;
        PrintInHelper(subroot->right);
    }
}

void BST::PrintIn() const
{
    PrintInHelper(root);
}

void BST::PrintPre() const // FIXME: PrintPre()
{
}

void BST::PrintPost() const // FIXME: PrintPost()
{
}

void BST::Search() const // FIXME: Search()
{
}

int main()
{
    BST b;

    // 50
    b.Insert(50);
    b.PrintIn();
    cout << "******" << endl;

    // 25
    b.Insert(25);
    b.PrintIn();
    cout << "******" << endl;

    // 70
    b.Insert(70);
    b.PrintIn();
    cout << "******" << endl;

    // 10
    b.Insert(10);
    b.PrintIn();
    cout << "******" << endl;

    // 30
    b.Insert(30);
    b.PrintIn();
    cout << "******" << endl;

    // 60
    b.Insert(60);
    b.PrintIn();
    cout << "******" << endl;

    // 100
    b.Insert(100);
    b.PrintIn();
    cout << "******" << endl;

    return 0;
}

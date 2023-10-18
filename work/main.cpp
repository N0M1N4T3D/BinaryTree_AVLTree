#include <iostream>
using namespace std;

struct Node {
    int Key;
    Node *Left, *Right;
};
typedef Node *PNode;

PNode MakeTree (int &from, int size)
{
    PNode Tree;
    int n1, n2, value;
    int data[size];
    if ( size == 0 ) return NULL;
    cout << "Введите элемент: ";
    cin >> value;
    data[from] = value;
    Tree = new Node;
    Tree->Key = data[from];
    n1 = size / 2;
    n2 = size - n1 - 1;
    Tree->Left = MakeTree(from, n1);
    Tree->Right = MakeTree(from, n2);
    return Tree;
}

void PrintTree (Node *q, long n)
{
    long i;
    if (q)
    {
        PrintTree(q->Right, n+5);
        for (i = 0; i < n; i++)
            cout << " ";
        cout << q->Key << endl;
        PrintTree(q->Left, n+5);
    }
}


int main() {
    int size;
    cout << "Введите количество значений для дерева: ";
    cin >> size;
    PNode Tree;
    int start = 0;
    Tree = MakeTree (start, size);
    PrintTree(Tree, 0);
    return 0;
}

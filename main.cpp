//
// Created by Master64k on 15/9/2017.
//

#include "BinaryTree.h"

int main()
{

    BinaryTree b;

    b.SetRootValue(4);

    b.InsertLeft(5);

    Sleep(1000);

    b.InsertLeft(6);

    b.InsertLeft(8);

    cout << endl << "quantidade de niveis da arvore: " << b.GetTreeSize() << endl;

}
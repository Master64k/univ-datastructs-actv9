//
// Created by Master64k on 15/9/2017.
//

#include <iostream>
#include <windows.h>

using namespace std;

class BinaryTree
{

    typedef class _Node
    {
    public:
        int i;
        class _Node* pLft;
        class _Node* pRgt;

        _Node()
        {
            this->i = 0;
            this->pLft = nullptr;
            this->pRgt = nullptr;
        }

        void Insert(int a)
        {
            if(a > this->i)
                this->pRgt->Insert(a);
            else this->pLft->Insert(a);
        }

        ~_Node()
        {

            cout << "DBG -- deleting node with value " << this->i << endl;

            if(this->pLft != nullptr)
            {
                cout << "DBG -- deleting pointer to node with number: " << this->pLft->i << endl;
                delete this->pLft;
                this->pLft = nullptr;
            }

            if(this->pRgt != nullptr)
            {
                cout << "DBG -- deleting pointer to node with number: " << this->pRgt->i << endl;
                delete this->pRgt;
                this->pRgt = nullptr;
            }
        }
    }Node, *pNode;

    pNode Root;
    pNode Current;
    int iCurrentLevel, iLevelCount;

public:

    BinaryTree()
    {

        Root = new Node;
        Current = nullptr;
        this->iLevelCount = 0, this->iCurrentLevel = 0;
    }

    int GetTreeSize()
    {
        return this->iLevelCount;
    }

    // get the current level of the tree
    int GetCurrentLevel()
    {
        return this->iCurrentLevel;
    }

    // this sets the value of the root element
    void SetRootValue(int a)
    {
        if(this->Root) // redundant check
            this->Root->i = a;
    }

    void Insert(int a)
    {
        if(a >= this->Root->i)
            this->Root->pRgt->Insert(a);
        else this->Root->pLft->Insert(a);
    }

    pNode InsertLeft(int a)
    {
        // if the root has no sub items
        if(this->Current == 0)
        {

            this->Root->pLft = new Node;
            this->Current = Root->pLft;
            this->Current->i  = a;

            if(this->Root->pRgt == nullptr)
            {
                this->iLevelCount++;
                this->iCurrentLevel++;
            }

            return this->Root->pLft;
        }
        else
        {
            this->Current->pLft = new Node;
            this->Current = this->Current->pLft;
            Current->i = a;

            if(this->Root->pRgt == nullptr)
            {
                this->iLevelCount++;
                this->iCurrentLevel++;
            }

            return Current;
        }

    }

    pNode InsertRight(int a)
    {
        if(this->Current == 0)
        {
            this->Root->pRgt = new Node;
            this->Current = this->Root->pRgt;
            this->Current->i = a;

            if(this->Root->pRgt == nullptr)
            {
                this->iLevelCount++;
                this->iCurrentLevel++;
            }

            return Root->pRgt;
        }
        else
        {
            this->Current->pRgt = new Node;
            this->Current = this->Current->pRgt;
            Current->i = a;

            if(this->Root->pLft == nullptr)
            {
                this->iLevelCount++;
                this->iCurrentLevel++;
            }

            return Current;
        }
    }

    ~BinaryTree()
    {
        cout << "DBG -- Binary Tree destructor: " << endl;
        if(Root->pLft != nullptr)
        {
            delete this->Root->pLft;
            this->Root->pLft = 0;
        }

        if(Root->pRgt != nullptr)
        {
            delete this->Root->pRgt;
            this->Root->pRgt = 0;
        }
        delete this->Root;

    }
};


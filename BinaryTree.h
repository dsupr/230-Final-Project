#include "BinaryTreeNode.h"
#include "Stack.h"

//#include "StudentRecord.h"

#include <string>

class BinaryTree
{
    private:
        BinaryTreeNode *root;
        BinaryTreeNode *current;

        TStack tstack;

        void insert(BinaryTreeNode *d, BinaryTreeNode * &p);
        //void insert(string d, BinaryTreeNode * &p);
        bool search(BinaryTreeNode *d, BinaryTreeNode * &p);
        void slideLeft();

    public: 
        BinaryTree() {root = nullptr; current = nullptr;};

        void insert(BinaryTreeNode *d) {insert(d, root);};
        void gotoFirst();
        bool getCurrent(string &d);
        void gotoNext();
        bool search (BinaryTreeNode *d) {return search(d,root);};
};


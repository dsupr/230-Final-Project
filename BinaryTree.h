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
        bool search(string d, BinaryTreeNode * &p);
        void slideLeft();

    public: 
        BinaryTree() {root = nullptr; current = nullptr;};

        void insert(BinaryTreeNode *d) {insert(d, root);};
        void gotoFirst();
        bool getCurrent(BinaryTreeNode *&d);
        void gotoNext();
        bool search (string d) {return search(d,root);};
};


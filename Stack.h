#include "StackNode.h"

#pragma once

class TStack
{
    private:
        TStackNode *top;

    public:
        TStack() {top = nullptr;};

        void push(BinaryTreeNode *p);
        bool pop(BinaryTreeNode * &p);
        bool empty() {return (top == nullptr);};
};

//#include "stack.cpp"

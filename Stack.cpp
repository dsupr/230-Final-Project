#include "Stack.h"

void TStack::push(BinaryTreeNode *p)
{
    TStackNode *newNode = new TStackNode();
    newNode->data = p;
    newNode->next = top;
    top = newNode;
}


bool TStack::pop(BinaryTreeNode * &p)
{
    if (top == nullptr)
    {
        return false;
    }
    p = top->data;
    TStackNode *delNode = top;              //tracing top
    top = top->next;
    delete delNode;                         //delete
    return true;
}

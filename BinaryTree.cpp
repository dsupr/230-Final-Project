#include "BinaryTree.h"
//#include "BinaryTreeNode.h"
//#include "StudentRecord.h"

void BinaryTree::insert(BinaryTreeNode *d, BinaryTreeNode * &p) 
{
    if (p == nullptr)
    {   
        p = new BinaryTreeNode();
        p->data = d->data;
        return;
    }
    if (d->data->name <= p->data->name)
    {   
        insert (d,p->left);
    }
    else
    {
        insert (d,p->right);
    }
}


void BinaryTree::slideLeft()
{
    if (current->left == NULL)
    {
        return;
    }
    tstack.push(current);
    current = current->left;
    slideLeft();
}


void BinaryTree::gotoFirst()
{
    while (tstack.pop(current));
    current = root;
    if (current == NULL)
    {
        return;
    }
    slideLeft();
}


bool BinaryTree::getCurrent(BinaryTreeNode *&d)
{
    if (current == NULL)
    {
        return false;
    }
    d->data = current->data;
    return true;
}


void BinaryTree::gotoNext()
{
    if (current == NULL)
    {
        return;
    }
    if (current->right != NULL)
    {
        current = current->right;
        slideLeft();
        return;
    }
    if(!tstack.pop(current))
    {
        current = NULL;
    }
}

bool BinaryTree::search(string d, BinaryTreeNode * &p)
{   
    if (p == NULL)
    {
        return false;
    }
    if (p->data->name == d)
    {
        current = p;
        return true;
    }
    if (d < p->data->name)
    {
        
        return search(d, p->left);
    }
    return search(d, p->right);
}

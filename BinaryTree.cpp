#include "BinaryTree.h"

void BinaryTree::insert(BinaryTreeNode *d, BinaryTreeNode * &p)             //new node and root in parameters
{
    if (p == nullptr)                   //once null, node is where it needs to be
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
    tstack.push(current);                   //leaving a trail
    current = current->left;
    slideLeft();                            //recursive, calls itself
}


void BinaryTree::gotoFirst()
{
    while (tstack.pop(current));            //while you can take something from the stack, retrace steps; no matter where you are go back 
    current = root;
    if (current == NULL)                    //if tree is empty
    {
        return;
    }
    slideLeft();                            //slide left (least value)
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
    if (d > p->data->name)                                    //needed an if statement because p==null condition would be met and it would try to search again in right
    {
        return search(d, p->right);
    }
}

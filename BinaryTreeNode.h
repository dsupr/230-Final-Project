//#include "Stack.h"

//#pragma once

#include "StudentRecord.h"
#include <string>

class BinaryTreeNode
{
    public:

        StudentRecord *data;

    
        BinaryTreeNode *left, *right;

        BinaryTreeNode() {left = nullptr; right = nullptr;};
};

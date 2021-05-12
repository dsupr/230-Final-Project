#include "StudentRecord.h"
#include <string>

class BinaryTreeNode
{
    public:

        StudentRecord *data;                //BinaryTreeNode has data value of pointer to student record

    
        BinaryTreeNode *left, *right;

        BinaryTreeNode() {left = nullptr; right = nullptr;};
};

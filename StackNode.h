#include "StudentRecord.h"

class TStackNode
{
    public:
        BinaryTreeNode *data;
        TStackNode *next;

        TStackNode() {next = nullptr;};
};

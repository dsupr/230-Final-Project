#pragma once

class TStackNode
{
    public:
        BinaryTreeNode *data;       //stacknode has data type of pointer to binarytreenode
        TStackNode *next;

        TStackNode() {next = nullptr;};
};

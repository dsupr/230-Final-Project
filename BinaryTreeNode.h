//#include "Stack.h"

//#pragma once

#include "StudentRecord.h"
#include <string>

class BinaryTreeNode
{
    public:

        /*
        int studentID;
        std::string name;
        std::string curriculuum;
        double gpa;
        */

        StudentRecord *data;

    
        BinaryTreeNode *left, *right;

        BinaryTreeNode() {left = nullptr; right = nullptr;};
};

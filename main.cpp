#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//#include "BinaryTree.h"
//#include "BinaryTreeNode.h"
#include "BinaryTree.cpp"

//#include "HashTable.h"
#include "HashTable.cpp"

//#include "StackNode.h"
//#include "Stack.h"
#include "Stack.cpp"

#include "StudentRecord.h"

//BRUH
/*
#include "StudentRecord.h"
#include "StackNode.h"
#include "HashTable.h"

#include "BinaryTree.cpp"
#include "Stack.cpp"

#include "HashTable.cpp"
*/
int main()
{   

    //cout << "Hello bruh" << endl;
    //cout << "mutha flippin nani???" << endl;
    
    HashTable table;
    BinaryTree tree;

    StudentRecord *student, *bruh;
    BinaryTreeNode *treenode, *bruhh;
    fstream fin;

    int studentID;
    string name;
    string curriculuum;
    double gpa;
    

    fin.open ("students.txt");

    while (fin >> studentID >> name >> curriculuum >> gpa)  
    {
        student = new StudentRecord;
        student->studentID = studentID;
        student->name = name;
        student->curriculuum = curriculuum;
        student->gpa = gpa;
        
        table.insert(student);

        //bruhh->data = student;

        //tree.insert(bruhh);
        //yooo ^
        
        //treenode = new BinaryTreeNode;
        //treenode->data = student;
        
        
        
        //treenode->data->curriculuum

        
        //tree.insert(treenode->data->name);
    }
    fin.close();

    int test = 0;
    test = table.indexCount();
    cout << "TEST: " << test << endl;

    
    while (studentID != 42069)
    {
        cout << "Enter studentID: ";
        cin >> studentID;
        if (table.get(studentID, student))
        {
            cout << student->name << endl;
            cout << student->curriculuum << endl;
            cout << student->gpa << endl << endl;
            
        }
        else
        {
            cout << studentID  << " not found" << endl << endl;
        }
    }
    

    
    
    // yooooooo

    string f ;
    tree.getCurrent(f);
    
    cout << "F: " << f << endl;


    


    return 0;
}

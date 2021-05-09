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
    
    HashTable table;
    BinaryTree tree;

    StudentRecord *student;
    BinaryTreeNode *treenode, *printout;
    fstream fin;

    int studentID;
    string name;
    string curriculuum;
    double gpa;

    tree.gotoFirst();

    fin.open ("students.txt");

    while (fin >> studentID >> name >> curriculuum >> gpa)  
    {
        student = new StudentRecord;
        student->studentID = studentID;
        student->name = name;
        student->curriculuum = curriculuum;
        student->gpa = gpa;
        
        table.insert(student);

        treenode = new BinaryTreeNode;
        treenode->data = student;

        tree.insert(treenode);  
    }
    fin.close();

    tree.gotoFirst();

    printout = new BinaryTreeNode;
    while (tree.getCurrent(printout)) 
    {
        tree.getCurrent(printout);

        cout << printout->data->studentID << "   " << printout->data->name << "   " << printout->data->curriculuum << "   " << printout->data->gpa << endl; 

        tree.gotoNext();
    }

    string entry;
    cout << "Enter name to search: " << endl;
    cin >> entry;
    if (tree.search(entry))
    {
        cout << entry << endl;
    }
    else
    {
        cout << "***** NOT FOUND *****" << endl;
    }

    /*
    tree.getCurrent(yoo);

    cout << "yoo: " << yoo << endl; 

    tree.gotoNext();

    tree.getCurrent(yoo);

    cout << "yoo: " << yoo << endl; 

*/

    /*

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


    */


    return 0;
}

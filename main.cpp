#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


#include "BinaryTree.cpp"
#include "HashTable.cpp"
#include "Stack.cpp"

#include "StudentRecord.h"


int main()
{

    HashTable table;
    BinaryTree tree;

    StudentRecord *student;
    BinaryTreeNode *treenode;
    fstream fin;

    int studentID;
    string name;
    string curriculuum;
    double gpa;

    tree.gotoFirst();

    fin.open("students.txt");

    while (fin >> studentID >> name >> curriculuum >> gpa)
    {
        student = new StudentRecord;                //creates pointer to newstudent record
        student->studentID = studentID;
        student->name = name;
        student->curriculuum = curriculuum;
        student->gpa = gpa;

        table.insert(student);                      //insert pointer into hash table

        treenode = new BinaryTreeNode;              //binarytreenode with data pointing to student
        treenode->data = student;

        tree.insert(treenode);                      //insert treenode to binary tree
    }
    fin.close();

    int userAction = -1;

    while (userAction != 0)
    {
        
        cout << endl; 
        cout << "1. List all students in alphabetical order" << endl;
        cout << "2. Find a student by name" << endl;
        cout << "3. Find a student by student ID." << endl;
        cout << "0. Exit." << endl;

        cout << "Enter action: ";
        cin >> userAction;

        string entry;

        switch (userAction)
        {

            case 0:                             //"0. Exit.""
                cout << endl;
                cout << "See you next time! =)" << endl;
                cout << endl;
                break;

            case 1:                             //"1. List all students in alphabetical order"
                tree.gotoFirst();

                treenode = new BinaryTreeNode;
                cout << endl;
                while (tree.getCurrent(treenode))
                {
                    tree.getCurrent(treenode);

                    cout << left << setw(10) << treenode->data->studentID << left << setw(15) << treenode->data->name
                        << left << setw(25) << treenode->data->curriculuum << left << setw(50) << treenode->data->gpa << endl;

                    tree.gotoNext();
                }
                break;

            case 2:                             //"2. Find a student by name"
                cout << "Enter name to search: " << endl;
                cin >> entry;
                entry[0] = toupper(entry[0]);       //in case user inputs name with lowercase first letter
                if (tree.search(entry))
                {
                    
                    tree.getCurrent(treenode);
                    cout << endl;
                    cout << left << setw(10) << treenode->data->studentID << left << setw(15) << treenode->data->name
                        << left << setw(25) << treenode->data->curriculuum << left << setw(50) << treenode->data->gpa << endl;
                    
                }
                else
                {
                    cout << "***** NOT FOUND *****" << endl;
                }
                break;

            case 3:                             //"3. Find a student by student ID."
                

                cout << "Enter studentID: ";
                cin >> studentID;
                if (table.get(studentID, student))
                {   
                    cout << endl;
                    cout << left << setw(10) << student->studentID << left << setw(15) << student->name
                        << left << setw(25) << student->curriculuum << left << setw(50) << student->gpa << endl;
                }
                else
                {
                    cout << endl << "ID " << studentID << " NOT FOUND" << endl << endl;         //error message if ID is not found in data
                }
                
                break;

            default:
                cout << "INVALID COMMAND!" << endl;
                break;
            }
    }

    return 0;
}

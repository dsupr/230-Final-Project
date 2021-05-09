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
    BinaryTreeNode *treenode, *printout;
    fstream fin;

    int studentID;
    string name;
    string curriculuum;
    double gpa;

    tree.gotoFirst();

    fin.open("students.txt");

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

            case 0:
                cout << endl;
                cout << "See you next time! =)" << endl;
                cout << endl;
                break;

            case 1:
                tree.gotoFirst();

                printout = new BinaryTreeNode;
                cout << endl;
                while (tree.getCurrent(printout))
                {
                    tree.getCurrent(printout);

                    cout << left << setw(10) << printout->data->studentID << left << setw(15) << printout->data->name
                        << left << setw(25) << printout->data->curriculuum << left << setw(50) << printout->data->gpa << endl;

                    tree.gotoNext();
                }
                break;

            case 2:
                cout << "Enter name to search: " << endl;
                cin >> entry;
                if (tree.search(entry))
                {
                    tree.getCurrent(printout);
                    cout << endl;
                    cout << left << setw(10) << printout->data->studentID << left << setw(15) << printout->data->name
                        << left << setw(25) << printout->data->curriculuum << left << setw(50) << printout->data->gpa << endl;
                    
                }
                else
                {
                    cout << "***** NOT FOUND *****" << endl;
                }
                break;

            case 3:
                

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
                    cout << studentID << " not found" << endl
                        << endl;
                }
                
                break;

            default:
                cout << "INVALID COMMAND!" << endl;
                break;
            }
    }

    /*
    tree.gotoFirst();

    printout = new BinaryTreeNode;
    while (tree.getCurrent(printout))
    {
        tree.getCurrent(printout);

        cout << left << setw(10) << printout->data->studentID << left << setw(15) << printout->data->name
             << left << setw(25) << printout->data->curriculuum << left << setw(50) << printout->data->gpa << endl;

        tree.gotoNext();
    }

    /*
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
    

    while (studentID != '0')
    {
        cout << "Enter studentID: ";
        cin >> studentID;
        if (table.get(studentID, student))
        {
            cout << left << setw(10) << student->studentID << left << setw(15) << student->name
                 << left << setw(25) << student->curriculuum << left << setw(50) << student->gpa << endl;
        }
        else
        {
            cout << studentID << " not found" << endl
                 << endl;
        }
    }

    */

    return 0;
}

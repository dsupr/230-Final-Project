#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//#include "StudentRecord.h"
//#include "HashTable.h"

#include "HashTable.cpp"

int main()
{
    HashTable table;
    StudentRecord *student;
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
    }
    fin.close();

    int test = 0;
    test = table.indexCount();
    cout << "TEST: " << test << endl;


    while (studentID != '0')
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
    

    return 0;
}

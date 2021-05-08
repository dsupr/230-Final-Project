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

    cout << "ohhhh very nice" << endl;

    /*
    while (gender != '0')
    {
        cout << "Enter gender and number: ";
        cin >> gender >> number;
        if (table.get(gender, number, person))
        {
            cout << person->name << endl << endl;
        }
        else
        {
            cout << gender << " " << number << " not found" << endl << endl;
        }
    }
    */

    return 0;
}

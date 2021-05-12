#include "HashTable.h"

HashTable::HashTable()  //constructor
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        data[i] = nullptr;
    }
}


void HashTable::insert(StudentRecord *d)
{
    int index;

    index = d->studentID % TABLESIZE;   //module hash, simple
    data[index] = d;

}


bool HashTable::get (int id, StudentRecord *&d)
{
    if ((id < TABLESIZE) || (id >= 2 * TABLESIZE))                 //makes it so that user input 4 doesn't get table[4],  user has to input id correctly
    {
        return false;
    }
    id = id % TABLESIZE;                //done here again so user doesn't have to adjust their input
    
    if (data[id] != nullptr)
    {
        d = data[id];
        return true;
    }
    return false;
}

int HashTable::indexCount()             
{
    int count = 0;
    int index = 0;

    if (data[index] == nullptr) 
    {
        return count;
    }
    else 
    {
        while (data[index] != nullptr)
        {
            count++;
            index++;
        }
    }
    return count;

}

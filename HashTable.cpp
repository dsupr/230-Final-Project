#include "HashTable.h"


HashTable::HashTable()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        data[i] = nullptr;
    }
}


void HashTable::insert(StudentRecord *d)
{
    int index;

    index = d->studentID % TABLESIZE;
    data[index] = d;

}


bool HashTable::get (int id, StudentRecord *&d)
{
    id = id % TABLESIZE;
    d = data[id];

   return true;
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

#include "HashTable.h"


HashTable::HashTable()
{
    for (int i = 0; i < 1000; i++)
    {
        data[i] = nullptr;
    }
}


void HashTable::insert(StudentRecord *d)
{
    int index;

    /*
    switch (d->gender)
    {
        case 'F':
            index = (d->number - 1) * 2;
            break;
        case 'M':
            index = (d->number - 1) * 2 + 1;
            break;
        default:
            index = 1000;
    }

    data[index] = d;
    */
}


bool HashTable::get (char g, int n, StudentRecord *&d)
{
    int index;
    /*
    switch (g)
    {
        case 'F':
            index = (n - 1) * 2;
            break;
        case 'M':
            index = (n - 1) * 2 + 1;
            break;
        default:
            index = 1000;
    }
    if ((index < 0) || (index >= 1000))
    {
        return false;
    }
    if (data[index] == nullptr)
    {
        return false;
    }

    d = data[index];
    return true;
    */
   return true;
}

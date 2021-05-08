#include "StudentRecord.h"

class HashTable
{
    private:
        StudentRecord *data[1000];

    public:
        HashTable();
        void insert(StudentRecord *d);
        bool get (char g, int n, StudentRecord *&d);
};



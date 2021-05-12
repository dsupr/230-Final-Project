
class HashTable
{
    private:
        static const int TABLESIZE = 1000;
        StudentRecord *data[TABLESIZE];

    public:
        HashTable();
        void insert(StudentRecord *d);
        bool get (int id, StudentRecord *&d);
        int indexCount();                           //not really used in this program but can be helpful
};



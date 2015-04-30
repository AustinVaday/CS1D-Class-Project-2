#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


template<class objectType,  class keyType>
class hashTable
{
    public:
        hashTable();
        hashTable(int sizeOfTable);
        //	hashTable()
        ~hashTable();


        //Retrieves object given a key
        objectType &     retreive(string key);

        //Remove object given a key
        void           remove(keyType key);

        //Inserts an object into the hash table an
        void           insert(objectType object, string key);
        void           makeEmpty();
        int            getHash(string key);
        float          returnLoadFactor();
        //	hashTable<objectType, keyType>& operator = ();
        int            getCount();
        void           rehashTable();
        int            calcLoadFactor();
        vector<string> returnKeyList();
    private:

        //P R I V A T E
        vector<objectType> * _table;
        vector<string>       _keyList;
        int                  _count;
        int                  _sizeOfTable;
        //	int hashFunc(*hashFunc(), const keyType);
        void compress();
};

template<class objectType, class keyType>
hashTable<objectType, keyType>::hashTable()
{
    _sizeOfTable = 100;
    _count       = 0;

    _table       = new vector<objectType>[_sizeOfTable];

}

template<class objectType, class keyType>
hashTable<objectType, keyType>::hashTable(const int sizeOfTable)
{
    _sizeOfTable = sizeOfTable;
    _count       = 0;
    _table       = new vector<objectType>[_sizeOfTable];
}

template<class objectType, class keyType>
hashTable<objectType, keyType>::~hashTable()
{

}

template<class objectType, class keyType>
int hashTable<objectType, keyType>::getHash(string key)
{
    int sum = 0;
    for(int i = 0; i< key.length(); i++)
    {
        sum += key[i];
    }
    return sum % (_sizeOfTable - 1);

}

template<class objectType, class keyType>
void hashTable<objectType, keyType>::insert(objectType object, string key)
{


    _table[getHash(key)].push_back(object);

    _keyList.push_back(key);
}

template<class objectType, class keyType>
objectType & hashTable<objectType, keyType>::retreive(string key)
{
    int hash;

    hash = getHash(key);
    objectType newObject;


    newObject = _table[hash];

    return newObject;

}

template<class objectType, class keyType>
vector<string> hashTable<objectType, keyType>::returnKeyList()
{
    return _keyList;
}

template<class objectType, class keyType>
int hashTable<objectType, keyType>::getCount()
{
    return _count;
}

template<class objectType, class keyType>
void hashTable<objectType, keyType>::makeEmpty()
{
    //going to work on this in a bit
}



#endif // HASHTABLE_CPP

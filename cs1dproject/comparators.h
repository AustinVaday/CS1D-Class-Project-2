/**************************************************************************
* AUTHOR        : Austin Vaday
**************************************************************************/
#ifndef COMPARATORS_H
#define COMPARATORS_H

template <typename Type>
class TopGreatest
{
public:
    bool operator()(const Type& greater, const Type& less)
    {
        return (greater.getData() > less.getData());
    }
};

template <typename Type>
class TopLowest
{
public:
    bool operator()(const Type& less, const Type& greater)
    {
        return (less.getData() < greater.getData());
    }
};

template <typename Type>
class TopLowestWeight
{
public:
    bool operator()(const Type& less, const Type& greater)
    {
        if (less.getData() != NULL && greater.getData() != NULL)
        {
            return (less.getData()->getWeight() < greater.getData()->getWeight());
        }
        else
        {
            return false; // in case of extra loop in heapheader
        }
    }
};

template <typename Type>
struct HospitalPriority
{
    Type key;

    HospitalPriority()
    { key = Type();}

    HospitalPriority(Type newKey)
    { key = newKey;}

    bool operator >= (const HospitalPriority<Type>& lesser)
    {
        return (this->key >= lesser.key);
    }


    // ADD OVERLOADED operator <<

};


template <typename KeyType, typename DataType>
struct HospitalPrioritySTL
{
    KeyType key;
    DataType data;

    HospitalPrioritySTL()
    {
      key = KeyType();
      data = DataType();}

    HospitalPrioritySTL(KeyType newKey, DataType newData)
    {
      key = newKey;
      data = newData;
    }

    bool operator () (const HospitalPrioritySTL<KeyType, DataType>& greater, const HospitalPrioritySTL<KeyType, DataType>& lesser)
    {
        return (greater.key <= lesser.key);
    }
};

#endif // COMPARATORS_H

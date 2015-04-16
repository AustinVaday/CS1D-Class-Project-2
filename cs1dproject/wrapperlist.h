#ifndef WRAPPERLIST_H
#define WRAPPERLIST_H

#include <QList>

/******************************************************
 * WrapperList
 *
 *  Updates information in 3 different ways
 *      1) Adds/Removes/Edits from list
 *      2) Adds/Removes/Edits from hashTable
 *      3) Adds/Removes/Edits from database
 *
 ******************************************************/
template <typename DataType>
class WrapperList
{
public:
/*==================================================
 * C O N S T R U C T O R S
 * ================================================*/
    WrapperList();
    ~WrapperList();
/*==================================================
 * T Y P E D E F S
 * ================================================*/
    typedef list::iterator iterator;
/*==================================================
 * A C C E S S O R S
 * ================================================*/
    bool  contains(const DataType& val) const;
    int   indexOf(const DataType& value);
    const DataType& at(int i) const;
    iterator begin() const;
    iterator end()   const;
    int  count() const;
    bool empty() const;
    int  size()  const;
/*==================================================
 * M U T A T O R S
 * ================================================*/
    void insert(int i, const DataType& value);
    void push_back(const DataType& value);
    void push_front(const DataType& value);
    iterator erase(iterator begin, iterator end);
    iterator erase(iterator pos);
    DataType& pop_back();
    DataType& pop_front();
    void removeAt(int i);
    void clear();

/*==================================================
 * O V E R L O A D E D   O P E R A T O R S
 * ================================================*/
    QList<DataType>& operator= (const QList<DataType> &other);
    DataType& operator[](int i);
    const DataType& operator[](int i) const;
private:
    QList list<DataType>;
    // --> hash table goes here <--
    // --> database variable may go here <--
};

/*==================================================
 * C O N S T R U C T O R S
 * ================================================*/
template <typename DataType>
WrapperList::WrapperList()
           : list() // call default constructor for QList object
{

}

template <typename DataType>
WrapperList::~WrapperList()
{
    // empty, no pointed-to data
}

/*==================================================
 * A C C E S S O R S
 * ================================================*/
template <typename DataType>
bool  WrapperList::contains(const DataType& val) const
{
    return list.contains(val);
}
template <typename DataType>
int   WrapperList::indexOf(const DataType& value)
{
    return list.indexOf(value);
}
template <typename DataType>
const DataType& WrapperList::at(int i) const
{
    return list.at(i);
}
template <typename DataType>
iterator WrapperList::begin() const
{
    return list.begin();
}
template <typename DataType>
iterator WrapperList::end()   const
{
    return list.end();
}
template <typename DataType>
int  WrapperList::count() const
{
    return list.count();
}
template <typename DataType>
bool WrapperList::empty() const
{
    return list.empty();
}
template <typename DataType>
int  WrapperList::size()  const
{
    return list.size();
}

/*==================================================
* M U T A T O R S
* ================================================*/
template <typename DataType>
void WrapperList::insert(int i, const DataType& value)
{
    list.insert(i, value);
}
template <typename DataType>
void WrapperList::push_back(const DataType& value)
{
    list.push_back(value);
}
template <typename DataType>
void WrapperList::push_front(const DataType& value)
{
    list.push_front(value);
}
template <typename DataType>
iterator WrapperList::erase(iterator begin, iterator end)
{
    list.erase(begin,end);
}
template <typename DataType>
iterator WrapperList::erase(iterator pos)
{
    list.erase(pos);
}
template <typename DataType>
DataType& WrapperList::pop_back()
{
    DataType* tempPtr = nullptr;
    tempPtr = &(list.back());

    list.pop_back();

    return *tempPtr;
}
template <typename DataType>
DataType& WrapperList::pop_front()
{
    DataType* tempPtr = nullptr;
    tempPtr = &(list.front());

    list.pop_front();

    return *tempPtr;
}
template <typename DataType>
void WrapperList::removeAt(int i)
{
    list.removeAt(i);
}
template <typename DataType>
void WrapperList::clear()
{
    list.clear();
}

/*==================================================
* O V E R L O A D E D   O P E R A T O R S
* ================================================*/
template <typename DataType>
QList<DataType>& WrapperList::operator= (const QList<DataType> &other)
{
    return list.operator =(other);
}
template <typename DataType>
DataType& WrapperList::operator[](int i)
{
    return list.operator [](i);
}
template <typename DataType>
const DataType& WrapperList::operator[](int i) const
{
    return list.operator [](i);
}

#endif // WRAPPERLIST_H

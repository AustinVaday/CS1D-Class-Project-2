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

}
template <typename DataType>
int   WrapperList::indexOf(const DataType& value)
{

}
template <typename DataType>
const DataType& WrapperList::at(int i) const
{

}
template <typename DataType>
iterator WrapperList::begin() const
{

}
template <typename DataType>
iterator WrapperList::end()   const
{

}
template <typename DataType>
int  WrapperList::count() const
{

}
template <typename DataType>
bool WrapperList::empty() const
{

}
template <typename DataType>
int  WrapperList::size()  const
{

}



/*==================================================
* M U T A T O R S
* ================================================*/
template <typename DataType>
void WrapperList::insert(int i, const DataType& value)
{

}
template <typename DataType>
void WrapperList::push_back(const DataType& value)
{

}
template <typename DataType>
void WrapperList::push_front(const DataType& value)
{

}
template <typename DataType>
iterator WrapperList::erase(iterator begin, iterator end)
{

}
template <typename DataType>
iterator WrapperList::erase(iterator pos)
{

}
template <typename DataType>
DataType& WrapperList::pop_back()
{

}
template <typename DataType>
DataType& WrapperList::pop_front()
{

}
template <typename DataType>
void WrapperList::removeAt(int i)
{

}
template <typename DataType>
void WrapperList::clear()
{

}



/*==================================================
* O V E R L O A D E D   O P E R A T O R S
* ================================================*/
template <typename DataType>
QList<DataType>& WrapperList::operator= (const QList<DataType> &other)
{

}
template <typename DataType>
DataType& WrapperList::operator[](int i)
{

}
template <typename DataType>
const DataType& WrapperList::operator[](int i) const
{

}

#endif // WRAPPERLIST_H

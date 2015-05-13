/**************************************************************************
* AUTHOR        : Austin Vaday
**************************************************************************/
#ifndef HEAP_H
#define HEAP_H

#include "heapitem.h"
#include "exceptionclasses.h"
#include <QDebug>

/**************************************************************************
* HEAP DATASTRUCTURE:
* 	template arguments: <Key/Comparator, Value>
*
* 	Implemented using a dynamically allocated array.
* 	Once you enter in a size, the heap does not grow/expand automatically
*
* 	GROWTH RATE ANALYSIS:
* 		operator=	: O(n)
* 		insert		: O(log(n)) *heapifyUp   included here*
* 		removeTop	: O(log(n)) *heapifyDown included here*
* 		getHeight	: O(1)
* 		printAll	: O(n)
* 		isLeftChild	: O(1)
*
**************************************************************************/
template <typename KeyType, typename DataType>
class Heap
{
     public:
          Heap(int size = 30);                     			// Parameterized constructor
          Heap(const Heap<KeyType, DataType>& otherHeap);	// Copy constructor
          ~Heap();                                 			// Destructor
          Heap<KeyType,DataType>& operator= (const Heap<KeyType, DataType>& otherHeap);
                                                            // Perform hard copy
          void insert(HeapItem<DataType> &item);   			// Add an item to the heap
          void insert(DataType data);      					// Add an item to the heap
          HeapItem<DataType> removeTop();        			// Get item at the root
          int getNumElements();                    			// Return number of elements in the heap
          int getHeight();									// Return height of tree
          void printAll();                         			// Print all the elements in the heap


     private:
          void heapifyDown();   							// Reheap after removing item
          void heapifyUp();     							// Reheap after inserting item
          bool isLeftChild(int pos);						// Determine if position is left child


          HeapItem<DataType>     *elements;        			// Pointer to dynamically allocated array
          KeyType	   comparator;							// A comparator that specifies KEY relationship
          int          numElements;              			// Number of elements in the heap
          int          heapSize;               				// Size of the array
          int		   root;								// Location of root element
          int		   last;								// Location of last element



};
/**************************************************************************
 * Default constructor with base initialization to a type of its own
 *************************************************************************/
template <typename KeyType, typename DataType>
Heap<KeyType, DataType>::Heap(int size)
                        : elements(NULL),
                          numElements(0),
                          heapSize(size),
                          root(1),
                          last(0)
{
    // elements will be NULL if no memory allocated

    elements = new HeapItem<DataType>[size];
}
/**************************************************************************
 * Copy constructor
 *************************************************************************/
template <typename KeyType, typename DataType>
Heap<KeyType, DataType>::Heap(const Heap<KeyType, DataType>& otherHeap)
{
    // overloaded assignment operator
    *this = otherHeap;
}
/**************************************************************************
 * Destructor : Get rid of pointed-to data!
 *************************************************************************/
template <typename KeyType, typename DataType>
Heap<KeyType, DataType>::~Heap()
{
    // deallocate memory if no memory has been allocated
    if (elements != NULL)
    {

        delete [] elements;
        elements = NULL;
    }
}
/**************************************************************************
 * Perform hard copy
 *************************************************************************/
template <typename KeyType, typename DataType>
Heap<KeyType,DataType>& Heap<KeyType, DataType>::operator= (const Heap<KeyType, DataType>& otherHeap)
{
    // if not the same object
    if (this != &otherHeap)
    {
        if (otherHeap.heapSize > 0)
        {


            // deallocate previous memory
            if (elements != NULL)
            {



                delete [] elements;
                elements = NULL;



            }

;
            // perform actions to allocate more memory
            elements 	= new HeapItem<DataType>[otherHeap.heapSize];

            numElements = otherHeap.numElements;
            heapSize 	= otherHeap.heapSize;
            root 		= otherHeap.root;
            last 		= otherHeap.last;


            int index = 0;
            while (index < heapSize)
            {
                elements[index].setData(otherHeap.elements[index].getData());
                index++;
            }
        }
    }

    return *this;
}
/**************************************************************************
 * Add an item to the heap
 *************************************************************************/
template <typename KeyType, typename DataType>
void Heap<KeyType, DataType>::insert(HeapItem<DataType> &item)
{
    // else if have space for more data
    if (numElements < heapSize)
    {
        // REMOVE THIS FOR MORE GENERIC STUFF
//		qDebug() << "**Inserting data " << item.getData()->getWeight() << "**" << endl;

        // update last element position
        last++;

        numElements++;

        elements[last] = item;

        heapifyUp();


//		qDebug() << "**TOP IS " << elements[root].getData()->getWeight() << "**" << endl;


    }
    else
    {
        throw Full();
    }
}
/**************************************************************************
 * Add an item to the heap
 *************************************************************************/
template <typename KeyType, typename DataType>
void Heap<KeyType, DataType>::insert(DataType data)
{
    if (numElements < heapSize)
    {
        HeapItem<DataType> temp;

//		temp.setKey(key);
        temp.setData(data);

        insert(temp);

        // heapifyUp is performed when you call the above insert...
        // numElements is changed when you call the above insert...
    }
    else
    {
        throw Full();
    }

}

/**************************************************************************
 * Get item at the root
 *************************************************************************/
template <typename KeyType, typename DataType>
HeapItem<DataType> Heap<KeyType, DataType>::removeTop()
{
    // only remove if not zero elements
    if (numElements != 0)
    {

        HeapItem<DataType> temp;


        temp = elements[root];

        numElements--;

        // restores heap order (swaps root and last, deletes last, and changes last)
        heapifyDown();
//		printAll();


        return temp;
    }
    else
    {

        throw Empty();
    }
}

/**************************************************************************
* Return number of elements in the heap
*************************************************************************/
template <typename KeyType, typename DataType>
int Heap<KeyType, DataType>::getNumElements()
{
     return numElements;
}
/**************************************************************************
 * Return height of tree
 *************************************************************************/
template <typename KeyType, typename DataType>
int Heap<KeyType, DataType>::getHeight()
{
    return log2(numElements);
}

/**************************************************************************
* Print all the elements in the heap
*************************************************************************/
template <typename KeyType, typename DataType>
void Heap<KeyType, DataType>::printAll()
{
    if (numElements == 0)
    {
        qDebug() << "Nothing to display, empty heap!";
    }
    else
    {
        qDebug() << "Elements of Heap: " << endl;
        for (int i = 1; i < heapSize; i ++)
        {
            // output data ONLY if there exists a data type
            if (elements[i].getData() != DataType())
            {
                qDebug() << elements[i].getData() << ' ';
            }

        }

    }

    qDebug() << endl;

}

/**************************************************************************
 * Reheap after removing item
 * 	GREATEST KEY ON TOP
 *************************************************************************/
template <typename KeyType, typename DataType>
void Heap<KeyType, DataType>::heapifyDown()
{
    // if just root
    if (last == root)
    {
        // reset defaults
        elements[root].setData(DataType());
    }
    else
    {
        int leftChild = root  * 2;
        int rightChild  = root * 2 + 1;
        int current = root;
        bool finished = false;
        int index = 0;
        HeapItem<DataType> temp;
        // swap root and last element (discard root)
        elements[root] = elements[last];

        // set last to initialized value
        elements[last].setData(DataType());

        //decrement last node
        last--;

        // numElements ALREADY decremented

        // loop until order is restored
        // or loop until index equals height of tree or no longer need to swap
        while (index < this->getHeight() && !finished)
        {
            // swap with the GREATER child
            temp = elements[current];

            // operate with left child only if left child is comparable
            // to right child OR if right child is set to it's DataType
            // (no val)
            if (comparator(elements[leftChild] , elements[rightChild])
                    || elements[rightChild].getData() == DataType())
            {
                // do not swap with empty positions
                if (comparator(elements[leftChild], elements[current])
                        && elements[leftChild].getData() != DataType())
                {
                    elements[current] = elements[leftChild];
                    elements[leftChild] = temp;
                    current = leftChild;
                }
                else
                {
                    finished = true;
                }
            }
            // swap with the GREATER child
            else if (comparator(elements[rightChild], elements[leftChild])/*
                    && elements[rightChild].getData() != DataType()*/)
            {
                // do not swap with empty positions
                if (comparator(elements[rightChild], elements[current])
                        && elements[rightChild].getData() != DataType())
                {
                    elements[current] = elements[rightChild];
                    elements[rightChild] = temp;
                    current = rightChild;
                }
                else
                {
                    finished = true;
                }
            }
            // if the same, don't swap
            else
            {
                //
                if (elements[rightChild].getData() == DataType())
                {

                }
                else if (elements[leftChild].getData() == DataType())
                {

                }
                else
                {
                    finished = true;
                }
            }
            // update left and right childs
            leftChild = current  * 2;
            rightChild  = current * 2 + 1;

            index++;
        }


    }
}
/**************************************************************************
 * Reheap after inserting item
 * 	GREATEST KEY ON TOP
 *************************************************************************/
template <typename KeyType, typename DataType>
void Heap<KeyType, DataType>::heapifyUp()
{

    // skip if last is root
    if (last != root)
    {
        int parent;
        int current;

        HeapItem<DataType> temp;

        current = last;

        if (isLeftChild(current))
        {
            parent = current / 2;
        }
        else
        {
            parent = (current - 1) / 2;
        }

        // loop until we hit root
        // OR until parent element is finally greater than the current element
        while (comparator (elements[current], elements[parent])  && current != root)
        {
            // swap current and parent
            temp = elements[parent];
            elements[parent] = elements[current];
            elements[current] = temp;

            // set current to parent
            current = parent;

            // find new parent
            if (isLeftChild(current))
            {
                parent = current / 2;
            }
            else
            {
                parent = (current - 1) / 2;
            }

        }

    }

}
/**************************************************************************
 * Determine if position is left child
 *************************************************************************/
template <typename KeyType, typename DataType>
bool Heap<KeyType, DataType>::isLeftChild(int pos)
{
    // if position is even, it is a left child
    // if it is odd, it is not a left child
    if (pos % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


#endif // HEAP_H

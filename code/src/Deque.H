#ifndef DEQUE_H 
#define DEQUE_H



#include "Node.H"

using namespace std;
template <typename T>
class Deque
{
    private:
       
        Node<T>* mHead;
        Node<T>* mTail; 
        size_t mCount;

    public:

        Deque();
        Deque(T defaultParm, size_t sizeParm);
        virtual ~Deque();
        
        void pushBack(T elementParm);
        void pushFront(T elementParm);
        
        void popFront();
        void popBack();
        
        T getFirstElement();
        T getLastElement();
        
        size_t size();
        void resize(size_t sizeParm, int directionParm, T defaultValueParm = T());
        
        void clear();
        void printAll();

        T& operator[](size_t positionParm);
        bool isDequeEmpty();

        virtual void processDeque() = 0;

};

//--------------------------------------------------------------------------//

template <typename T>
bool Deque<T>::isDequeEmpty()
{
    return mHead == NULL;
}

template <typename T>
T& Deque<T>::operator[](size_t positionParm)
{
    if (positionParm < 0 || positionParm >= mCount)
    {
        throw out_of_range("Index out of range\n");
    }

    Node<T>* sCurrentNode = mHead;
    for (int sIndex = 0; sIndex < positionParm; sIndex++)
        sCurrentNode = sCurrentNode->getNext();

    return sCurrentNode->getData();
}


template <typename T>
Deque<T>::Deque()
{
    mCount = 0;
    mHead = NULL;
    mTail = NULL;
    cout << "Called deque default constructor\n";
}


template <typename T>
Deque<T>::Deque(T defaultParm, size_t sizeParm):mHead(NULL), mTail(NULL), mCount(0)
{
    for(size_t sIndex=0;sIndex<sizeParm;sIndex++)
        pushBack(defaultParm);
    cout << "Called deque Parmterized constructor\n";
}

template <typename T>
Deque<T>::~Deque()
{
    clear();
    cout << "Called Deque destructor\n";
}

template <typename T>
void Deque<T>::pushFront(T elementParm)
{
   Node<T>* sNewNode = new Node<T>(elementParm);

   if(mHead == NULL)
   {
        mHead = sNewNode;
        mTail = sNewNode;
   }
   else
   {
        sNewNode->setNext(mHead);
        mHead->setPrev(sNewNode);
        mHead = sNewNode;
   }
   mCount++;
} 

template <typename T>
void Deque<T>::pushBack(T elementParm)
{
   Node<T>* sNewNode = new Node<T>(elementParm);

   if(mHead == NULL)
   {
        mHead = sNewNode;
        mTail = sNewNode;
   }
   else
   {
        mTail->setNext(sNewNode);
        sNewNode->setPrev(mTail);
        mTail = sNewNode;
   }
   mCount++;
}

template <typename T>
void Deque<T>::popFront()
{
    if(mHead == NULL)
    {
        //error 
        throw underflow_error("Empty Deque\n");
    }
    Node<T>* sNode = mHead;
    mHead = mHead->getNext();
    if(mHead)
    {
            mHead->setPrev(NULL);
    }
    else
    {
        // removed last element
            mTail = NULL;
    }

    delete sNode;
    mCount--;
}

template <typename T>
void Deque<T>::popBack()
{
    if(mTail == NULL)
    {
        //throw error 
        throw underflow_error("Empty Deque\n");
    }

    Node<T>* sCurrentNode = mTail;
    mTail = mTail->getPrev();
    if(mTail)
    {
        mTail->setNext(NULL);
    }
    else
    {
        // removed first element
        mHead = NULL;
    }

    delete sCurrentNode;
   mCount--;
}

template <typename T>
T Deque<T>::getFirstElement()
{
    if(mHead == NULL)
    {
        //throw error
        throw underflow_error("Empty Deque\n");
    }
    return mHead->getData();
}

template <typename T>
T Deque<T>::getLastElement()
{
    if(mTail == NULL)
    {
        //throw error
        throw underflow_error("Empty Deque\n");
    }
    return mTail->getData();
}

template <typename T>
size_t Deque<T>::size()
{
    return mCount;
}

template <typename T>
void Deque<T>::printAll()
{
    if(mCount == 0)
   {
        cout << "Empty deque \n";
        return;
   }
   Node<T>* sCurrentNode = mHead;
   cout << "Deque : \n";

    while (sCurrentNode) 
    {
        cout << sCurrentNode->getData();
        if (sCurrentNode->getNext()) cout << " ";
        sCurrentNode = sCurrentNode->getNext();
    }
       cout << "\n";
}

template <typename T>
void Deque<T>::clear()
{
    Node<T>* sCurrentNode = mHead;
    while(sCurrentNode)
    {
        Node<T>* sNextNode = sCurrentNode->getNext();
        delete sCurrentNode;
        sCurrentNode = sNextNode;
    }
    mHead = NULL;
    mTail = NULL;
    mCount = 0;
    cout << "Deque cleared\n";
}

template <typename T>
void Deque<T>::resize(size_t sizeParm, int directionParm, T defaultValueParm)
{
    if (sizeParm < 0) 
    {
        cout<<"Invalid Size for resize operation\n";
        return;
    }

    if(!(directionParm == 1 || directionParm == -1))
    {
        throw invalid_argument("Invalid direction in resize: must be +1 or -1");
    }
    
    size_t sCurrentSize = mCount;

    if(sizeParm > sCurrentSize)
    {
        // need to add elements

        size_t sCountToAdd = sizeParm - sCurrentSize;
        if (directionParm == 1) 
        {
            // add at end
            for (int sIndex = 0; sIndex < sCountToAdd; ++sIndex) {
                pushBack(defaultValueParm);
            }
        }
        else if (directionParm == -1)
        {
            // add at front
            for (int sIndex = 0; sIndex < sCountToAdd; ++sIndex) 
            {
                pushFront(defaultValueParm);
            }
        } 
        else 
        {
            cout << "Invalid direction in resize\n";
        }
    }
    else if(sizeParm < sCurrentSize)
    {
        // sizeParm < sCurrentSize

        int toRemove = sCurrentSize - sizeParm;
        if (directionParm == 1) 
        {
            // remove from end
            for (int sIndex = 0; sIndex < toRemove; ++sIndex) {
                popBack();
            }
        }
        else if (directionParm == -1)
        {
            // remove from front
            for (int sIndex = 0; sIndex < toRemove; ++sIndex) {
                popFront();
            }
        } 
        else 
        {
            cout << "Invalid direction in resize\n";
        }
    }

}




#endif
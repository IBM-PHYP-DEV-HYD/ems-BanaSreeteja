#ifndef EDLL_H
#define EDLL_H

#include "Deque.H"

template <typename T>
class Edll : public Deque<T>
{
    public:
        void insertAtMiddle(int indexParm, const T& dataParm);
        void removeAtMiddle(int indexParm);
};

template <typename T>
void Edll<T>::insertAtMiddle(int indexParm, const T& dataParm)
{
    if(indexParm < 0 || indexParm > this->mCount)
    {
        cout << "Out of range\n"; 
        return;
    }
    // insert at front
    if(indexParm == 0)
    {
        this->pushFront(dataParm);
        return;
    }
    // insert at back
    if(indexParm == this->mCount)
    {
        this->pushBack(dataParm);
        return;
    }

    Node<T>* sCurrent = this->mHead;
    for (int sIndex = 0; sIndex < indexParm; ++sIndex)
    {
        sCurrent = sCurrent->getNext();
    }
    Node<T>* sNewNode = new Node<T>(dataParm);
    sNewNode->setPrev(sCurrent->getPrev());
    sNewNode->setNext(sCurrent);

    sCurrent->getPrev()->setNext(sNewNode);
    sCurrent->setPrev(sNewNode);

    ++this->mCount;
}

template <typename T>
void Edll<T>::removeAtMiddle(int indexParm)
{
    if (indexParm < 0 || indexParm >= this->mCount)
    {
        cout << "Out of range\n"; 
        return;
    }

    if (indexParm == 0)
    {
        this->popFront();
        return;
    }

    if (indexParm == this->mCount - 1)
    {
        this->popBack();
        return;
    }

    Node<T>* sCurrent = this->mHead;
    for (int sIndex = 0; sIndex < indexParm; ++sIndex)
    {
        sCurrent = sCurrent->getNext();
    }
    sCurrent->getPrev()->setNext(sCurrent->getNext());
    sCurrent->getNext()->setPrev(sCurrent->getPrev());

    delete sCurrent;
    --this->mCount;
}


#endif
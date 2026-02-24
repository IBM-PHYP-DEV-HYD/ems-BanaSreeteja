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
        std::cout << "Out of range\n"; 
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

    Node<T>* sCurrent = this->getFirstElement;
    for (int sIndex = 0; sIndex < indexParm; ++sIndex)
    {
        sCurrent = sCurrent->mNext;
    }
    Node<T>* sNewNode = new Node<T>(dataParm);
    sNewNode->mPrev = sCurrent->mPrev;
    sNewNode->mNext = sCurrent;

    sCurrent->mPrev->mNext = sNewNode;
    sCurrent->mPrev = sNewNode;

    ++this->mCount;
}

template <typename T>
void Edll<T>::removeAtMiddle(int indexParm)
{
    if (indexParm < 0 || indexParm >= this->mCount)
    {
        std::cout << "Out of range\n"; 
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

    Node<T>* sCurrent = this->getFirstElement;
    for (int sIndex = 0; sIndex < indexParm; ++sIndex)
    {
        sCurrent = sCurrent->mNext;
    }
    sCurrent->mPrev->mNext = sCurrent->mNext;
    sCurrent->mNext->mPrev = sCurrent->mPrev;

    delete sCurrent;
    --this->mCount;
}


#endif
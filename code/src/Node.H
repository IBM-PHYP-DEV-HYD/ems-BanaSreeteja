#ifndef NODE_H
#define NODE_H

template <typename T>
class Deque;


template <typename T>
class Node
{
    private:

        T mData;
        Node* mPrev;
        Node* mNext;

    public:

        Node(T valueParm) : mData(valueParm), mPrev(NULL), mNext(NULL){}

        T& getData();

        Node<T>* getNext();
        Node<T>* getPrev();
        
        void setNext(Node<T>* nextParm);
        void setPrev(Node<T>* prevParm);

        void setData(T dataParm);

};

template<typename T>
T& Node<T>::getData() 
{ 
    return mData; 
}

template<typename T>
Node<T>* Node<T>::getNext() 
{ 
    return mNext; 
}

template<typename T>
Node<T>* Node<T>::getPrev() 
{ 
    return mPrev; 
}

template<typename T>
void Node<T>::setData(T dataParm)
{
    mData = dataParm;
}

template<typename T>
void Node<T>::setNext(Node<T>* nextParm) 
{ 
    mNext = nextParm; 
}
    
template<typename T>
void Node<T>::setPrev(Node<T>* prevParm) 
{ 
    mPrev = prevParm; 
}


#endif
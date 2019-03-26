//
//  Queue.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    T *storage;
    int currentSize;
    int maxSize;
    void doubleSpace()
    {
        T *tmp;
        tmp = new T[maxSize*2];
        maxSize = maxSize*2;
        for (int i = 0;i < currentSize;i++)
        {
            tmp[i] = storage[i];
        }
        T *temp = storage;
        storage = tmp;
        delete temp;
    }
public:
    Queue(int initSize = 10);
    T deQueue();
    T front();
    T end();
    bool isEmpty();
    void enQueue(T d);
    void traverse();
    ~Queue()
    {
        delete storage;
    }
};

template <class T>
Queue<T>::Queue(int initSize)
{
    currentSize = 0;
    maxSize = initSize;
    storage = new T[maxSize];
}

template <class T>
T Queue<T>::deQueue()
{
    if (currentSize==0) {
        cout << "Empty Queue!" <<endl;
        return 3;
    }
    T tmp = storage[0];
    for (int i = 0;i < currentSize-1;i++)
    {
        storage[i] = storage[i+1];
    }
    currentSize--;
}

template <class T>
void Queue<T>::enQueue(T d)
{
    if (currentSize==maxSize) doubleSpace();
    storage[currentSize++] = d;
}

template <class T>
T Queue<T>::front()
{
    if (currentSize==0) {
        cout << "Empty Queue!" <<endl;
        return 3;
    }
    return storage[0];
}

template <class T>
T Queue<T>::end()
{
    return storage[currentSize-1];
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (currentSize==0);
}

template <class T>
void Queue<T>::traverse()
{
    for (int i = 0;i < currentSize;i++) cout << storage[i] << ' ';
    cout << endl;
}

int main()
{
    Queue<int> a(1);
    a.enQueue(3);
    a.enQueue(4);
    a.traverse();
    a.deQueue();
    a.deQueue();
    cout << a.isEmpty() <<endl;
    a.deQueue();
    a.enQueue(5);
}

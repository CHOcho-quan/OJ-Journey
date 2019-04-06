//
//  Heap.cpp
//  
//
//  Created by 铨 on 2019/4/4.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

template <class T>
class Heap
{
private:
    int currentSize;
    int maxSize;
    T *data;
    void doubleSpace();
    void percolateUp(int hole);
    void percolateDown(int hole);
public:
    Heap(int initSize = 10)
    {
        maxSize = initSize;
        currentSize = 0;
        data = new T[maxSize];
    }
    Heap(T *d, int size)
    {
        maxSize = 2*size;
        data = new T[maxSize];
        currentSize = size;
        for (int i = 0;i < size;i++) data[i] = d[i];
        buildHeap();
    }
    void push(T d);
    T pop();
    void buildHeap();
    void traverse();
};

template <class T>
void Heap<T>::doubleSpace()
{
    T *tmp;
    tmp = new T [maxSize = 2 * maxSize];
    for (int i = 0;i < maxSize;i++) tmp[i] = data[i];
    T *temp = data;
    data = tmp;
    delete temp;
}

template <class T>
void Heap<T>::percolateUp(int hole)
{
    int tmp = data[hole];
    while (data[hole] > data[(hole - 1) / 2] && hole != 0)
    {
        data[hole] = data[(hole - 1) / 2];
        hole = (hole - 1) / 2;
    }
    data[hole] = tmp;
}

template <class T>
void Heap<T>::percolateDown(int hole)
{
    T tmp;
    while (2 * hole + 2 < currentSize)
    {
        if (data[2 * hole + 1] >= data[2 * hole + 2] && data[2 * hole + 1] > data[hole])
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 1;
            continue;
        }
        if (data[2 * hole + 2] > data[2 * hole + 1] && data[2 * hole + 2] > data[hole])
        {
            tmp = data[2 * hole + 2];
            data[2 * hole + 2] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 2;
            continue;
        }
        if (data[2 * hole + 1] <= data[hole] && data[2 * hole + 2] <= data[hole]) break;
    }
    if (2 * hole + 2 == currentSize)
    {
        if (data[2 * hole + 1] > data[hole])
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
        }
    }
}

template <class T>
void Heap<T>::push(T d)
{
    if (currentSize == maxSize) doubleSpace();
    data[currentSize++] = d;
    percolateUp(currentSize-1);
}

template <class T>
T Heap<T>::pop()
{
    T tmp = data[0];
    data[0] = data[--currentSize];
    percolateDown(0);
    return tmp;
}

template <class T>
void Heap<T>::buildHeap()
{
    for (int i = (currentSize-1) / 2;i >= 0;i--) percolateDown(i);
}

template <class T>
void Heap<T>::traverse()
{
    for (int i = 0;i < currentSize;i++) cout << data[i] << ' ';
    cout << endl;
}

int main()
{
    int a[8] = {1,2,3,4,5,6,7,110};
    Heap<int> c(a, 8);
    c.traverse();
}

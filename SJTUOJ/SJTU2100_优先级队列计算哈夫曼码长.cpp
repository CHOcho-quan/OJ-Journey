#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//这是节点
template <class T>
class Node {
public:
    Node *left;
    Node *right;
    T data;
    Node():left(NULL),right(NULL){}
    Node(T datai,Node *lefti = NULL,Node *righti=NULL)
    {
        data = datai;
        left = lefti;
        right = righti;
    }
    ~Node(){}
};

template <class T>
class priorityQueue {
private:
    int currentSize;
    T *data;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateUp(int hole);
    void percolateDown(int hole);
    int parent(int x) {return ((x+1)/2-1);}
public:
    priorityQueue(int initSize = 100)
    {
        data = new T[initSize];
        maxSize = initSize;
        currentSize = 0;
    }
    priorityQueue(const T datum[],int size)
    {
        data = new T[2*size];
        currentSize = size;
        maxSize = 2*size;
        for (int i = 0;i < size;i++) data[i] = datum[i];
        buildHeap();
    }
    ~priorityQueue() {delete [] data;}
    void traverse() const {for (int i = 0;i < currentSize;i++) cout << data[i] << ' ';}
    bool isEmpty() const {return currentSize==0;}
    void enQueue(const T &x);
    int size() const {return currentSize;}
    T deQueue();
    T getHead() {return data[0];}
};

template <class T>
void priorityQueue<T>::buildHeap()
{
    for (int i = parent(currentSize-1);i >= 0;i--) percolateDown(i);
}

template <class T>
void priorityQueue<T>::doubleSpace()
{
    T *tmp = data;
    data = new T[2*maxSize];
    for (int i = 0;i < currentSize;i++) data[i] = tmp[i];
}

template <class T>
void priorityQueue<T>::percolateUp(int hole)
{
    while (hole!=0)
    {
        if (data[parent(hole)] < data[hole]) break;
        else
        {
            T tmp = data[parent(hole)];
            data[parent(hole)] = data[hole];
            data[hole] = tmp;
            hole = parent(hole);
        }
    }
}

template <class T>
void priorityQueue<T>::enQueue(const T &x)
{
    if (currentSize == maxSize) doubleSpace();
    data[currentSize] = x;
    currentSize++;
    percolateUp(currentSize-1);
}

template <class T>
void priorityQueue<T>::percolateDown(int hole)
{
    T tmp;
    while (2 * hole + 2 < currentSize)
    {
        if (data[2 * hole + 1] <= data[2 * hole + 2] && data[2 * hole + 1] < data[hole])
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 1;
            continue;
        }
        if (data[2 * hole + 2] < data[2 * hole + 1] && data[2 * hole + 2] < data[hole])
        {
            tmp = data[2 * hole + 2];
            data[2 * hole + 2] = data[hole];
            data[hole] = tmp;
            hole = 2 * hole + 2;
            continue;
        }
        if (data[2 * hole + 1] >= data[hole] && data[2 * hole + 2] >= data[hole]) break;
    }
    if (2 * hole + 2 == currentSize)
    {
        if (data[2 * hole + 1] < data[hole])
        {
            tmp = data[2 * hole + 1];
            data[2 * hole + 1] = data[hole];
            data[hole] = tmp;
        }
    }
}

template <class T>
T priorityQueue<T>::deQueue()
{
    T result = data[0];
    data[0] = data[currentSize - 1];
    currentSize--;
    percolateDown(0);
    return result;
}

int main()
{
    priorityQueue<int> a(50000);
    int n,c,tmp1,tmp2,sum = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> c;
        a.enQueue(c);
    }

    while (a.size() > 1)
    {
        tmp1 = a.deQueue();
        if (!a.isEmpty()) tmp2 = a.deQueue();
        sum+=tmp1+tmp2;
        a.enQueue(tmp1 + tmp2);
    }
    cout << sum;
}

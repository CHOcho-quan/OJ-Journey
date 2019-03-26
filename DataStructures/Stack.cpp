//
//  Stack.cpp
//  
//
//  Created by 铨 on 2019/3/26.
//
//

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    T *storage;
    int currentSize;
    int maxSize;
    void doubleSpace()
    {
        T *tmp;
        tmp = new T[maxSize=2*maxSize];
        for (int i = 0;i < currentSize;i++) tmp[i] = storage[i];
        T *temp = storage;
        storage = tmp;
        delete temp;
    }
public:
    Stack(int initSize = 10);
    void push(T d);
    T pop();
    T top();
    void traverse();
    bool isEmpty();
    ~Stack()
    {
        delete storage;
    }
};

template <class T>
Stack<T>::Stack(int initSize)
{
    storage = new T[maxSize = initSize];
    currentSize = 0;
}

template <class T>
void Stack<T>::push(T d)
{
    if (currentSize == maxSize) doubleSpace();
    storage[currentSize++] = d;
}

template <class T>
T Stack<T>::pop()
{
    if (currentSize == 0)
    {
        cout << "Empty Stack!" << endl;
        return 3;
    }
    return storage[currentSize--];
}

template <class T>
T Stack<T>::top()
{
    if (currentSize == 0)
    {
        cout << "Empty Stack!" << endl;
        return 3;
    }
    return storage[currentSize-1];
}

template <class T>
void Stack<T>::traverse()
{
    for (int i = 0;i < currentSize;i++) cout << storage[i] << ' ';
    cout << endl;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (currentSize==0);
}

int main()
{
    Stack<int> a(1);
    a.push(1);
    a.push(2);
    a.push(3);
    a.traverse();
    cout << a.isEmpty() << endl;
    a.pop();
    a.pop();
    cout << a.top() << endl;
    a.traverse();
}

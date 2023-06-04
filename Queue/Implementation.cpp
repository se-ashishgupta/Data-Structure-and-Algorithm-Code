#include <iostream>
using namespace std;
// Naive all O(1) except deque O(n)
struct Queue
{
    int size, cap;
    int *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    bool isFUll()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void enque(int x)
    {
        if (isFUll())
            return;
        arr[size] = x;
        size++;
    }
    void deque() // O(n)
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getFromt()
    {
        if (isEmpty())
            return -1;
        else
            return arr[0];
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return arr[size - 1];
    }
};
// Efficient all O(1)
struct Queue1
{
    int front, size, cap;
    int *arr;
    Queue1(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    bool isFUll()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    int getFromt()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }
    void enque(int x)
    {
        if (isFUll())
            return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void deque() // O(1)
    {
        if (isFUll())
            return;
        front = (front + 1) % cap;
        size--;
    }
};

int main()
{

    return 0;
}
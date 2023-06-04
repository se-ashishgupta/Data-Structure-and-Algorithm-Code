#include <iostream>
using namespace std;
// All O(1) except delete front and insert front arr O(n)
struct Deque
{
    int size, cap;
    int *arr;
    Deque(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void insertRear(int x)
    {
        if (isFull())
        {
            return;
        }
        arr[size] = x;
        size++;
    }
    void insertFront(int x)
    {
        if (isFull())
            return;
        for (int i = size - 1; i >= 0; i++)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = x;
        size++;
    }
    void deleteRear()
    {
        if (isEmpty())
            return;
        size--;
    }
    void deleteFront()
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return size - 1;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return 0;
    }
};

struct Deque1
{
    int size, cap, front;
    int *arr;
    Deque1(int c)
    {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void insertRear(int x)
    {
        if (isFull())
        {
            return;
        }
        int new_rear = (front + size) % cap;
        arr[new_rear] = x;
        size++;
    }
    void insertFront(int x)
    {
        if (isFull())
            return;
        front = (front + cap - 1) % cap;
        arr[front] = x;
        size++;
    }
    void deleteRear()
    {
        if (isEmpty())
            return;
        size--;
    }
    void deleteFront()
    {
        if (isEmpty())
            return;
        front = (front + 1) % cap;
        size--;
    }
    int getRear()
    {
        if (isEmpty())
            return -1;
        else
            return (front + size - 1) % cap;
    }
    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }
};

int main()
{

    return 0;
}
#include <iostream>

using namespace std;

struct MinHeap
{
    int *arr;
    int size;
    int capacity;
    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int x) // TC : O(log(size))
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MinHeap *root = new MinHeap(5);
    root->insert(10);
    root->insert(15);
    root->insert(20);
    root->insert(25);
    root->insert(30);
    root->display();
}
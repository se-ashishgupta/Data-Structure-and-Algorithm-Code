#include <iostream>
#include <list>

using namespace std;

struct MyHash
{
    int *arr;
    int cap, size;
    MyHash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[c];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }

    int hash(int key)
    {

        return key % cap;
    }

    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;

            i = (i + 1) % cap;

            if (i == h)
                return false;
        }
        return false;
    }

    bool insert(int key)
    {
        if (size == cap)
            return false;
        int i = hash(key);
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
            i = (i + 1) % cap;

        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool remove(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
};

int main()
{
    MyHash h(6);
    cout << h.insert(10);
    cout << h.remove(10);
    cout << h.search(10);

    return 0;
}

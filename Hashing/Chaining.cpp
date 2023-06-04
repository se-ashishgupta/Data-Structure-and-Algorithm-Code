#include <iostream>
#include <list>

using namespace std;

struct Chaining
{
    int BUCKET;
    list<int> *table;

    Chaining(int b)
    {
        BUCKET = b;
        table = new list<int>[b];
    }

    void insert(int key)
    {
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key % BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key % BUCKET;
        for (auto x : table[i])
            if (x == key)
                return true;
        return false;
    }
};

int main()
{
    Chaining one(5);
    one.insert(100);
    one.remove(100);
    cout << one.search(100);

    return 0;
}
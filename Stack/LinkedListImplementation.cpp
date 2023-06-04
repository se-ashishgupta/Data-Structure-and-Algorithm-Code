#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int size;
    MyStack()
    {
        head = NULL;
        size = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop()
    {
        if (head == NULL)
            return INT16_MAX;

        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return res;
    }
    int sized()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int peak()
    {
        if (head == NULL)
            return INT16_MAX;

        return head->data;
    }
};

int main()
{
    MyStack s;
    cout << s.sized();
}

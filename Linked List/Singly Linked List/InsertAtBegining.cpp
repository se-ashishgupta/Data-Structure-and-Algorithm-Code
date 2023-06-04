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

Node *insertBegin(Node *head, int x) // TC: O(1)
{
    // Node *temp;
    // temp->data = x;
    // temp->next = head;

    Node *temp = new Node(x);
    temp->next = head;

    return temp;
}
int main()
{
    Node *head = NULL;
    head = insertBegin(head, 30);
}

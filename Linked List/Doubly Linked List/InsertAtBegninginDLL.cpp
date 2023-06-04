#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node *insertAtBegning(Node *head, int k)
{
    Node *temp = new Node(k);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }

    return temp;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    head = insertAtBegning(head, 50);
    head = insertAtBegning(head, 40);
    head = insertAtBegning(head, 30);
    head = insertAtBegning(head, 20);
    traverse(head);
    return 0;
}

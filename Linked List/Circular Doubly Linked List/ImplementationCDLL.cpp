#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *insertAtHead(Node *head, int k)
{
    Node *temp = new Node(k);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}
Node *insertAtEnd(Node *head, int k)
{
    Node *temp = new Node(k);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head->prev = head->next->next;
    head->next->prev = head;
    head->next->next->prev = head->next;
    traverse(head);
    head = insertAtEnd(head, 40);
    traverse(head);

    return 0;
}
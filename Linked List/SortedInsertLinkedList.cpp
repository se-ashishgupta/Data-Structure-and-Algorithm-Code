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

void traverse(Node *head)
{

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *sortedInsert(Node *head, int k)
{
    Node *temp = new Node(k);
    if (head == NULL)
        return temp;

    if (k < head->data)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    while (curr->next != NULL && curr->next->data < k)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    traverse(head);
    head = sortedInsert(head, 25);
    cout << endl;
    traverse(head);

    return 0;
}
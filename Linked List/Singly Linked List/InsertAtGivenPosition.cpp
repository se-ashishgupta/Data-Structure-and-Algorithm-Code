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
    Node *temp = new Node(x);
    temp->next = head;

    return temp;
}
void printList(Node *head) // TC: O(n)   TC:O(1)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
Node *insertGivenPos(Node *head, int pos, int data) // TC: O(1)
{

    Node *temp = new Node(data);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    int i = 1;
    while (i < pos - 1 && curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
        return head;

    temp->next = curr->next;
    curr->next = temp;

    return head;
}
int main()
{
    Node *head = NULL;
    head = insertBegin(head, 50);
    head = insertBegin(head, 40);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    head = insertGivenPos(head, 3, 30);
    head = insertGivenPos(head, 6, 60);
    printList(head);
    return 0;
}

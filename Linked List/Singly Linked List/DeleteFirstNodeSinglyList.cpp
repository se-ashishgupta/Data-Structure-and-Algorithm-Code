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
void printList(Node *head) // TC: O(n)   TC:O(1)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void printListRecuesion(Node *head) // TC: O(n)   TC:O(n)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    printListRecuesion(head->next);
}

Node *deleted(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // TRAVERSING //
    printList(head);
    cout << endl;
    head = deleted(head);
    printListRecuesion(head);

    return 0;
}
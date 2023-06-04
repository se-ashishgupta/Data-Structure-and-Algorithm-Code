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

Node *insertEnd(Node *head, int k) // TC: O(n)
{
    Node *temp = new Node(k);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {

        Node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        temp->next = head;
        curr->next = temp;
        return head;
    }
}
Node *insertEnd1(Node *head, int k) // TC : O(1)
{
    Node *temp = new Node(k);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return temp;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    traverse(head);
    cout << endl;
    head = insertEnd1(head, 05);
    traverse(head);

    return 0;
}
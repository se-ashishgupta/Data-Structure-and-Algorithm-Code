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

Node *insertHead(Node *head, int k) // TC: O(n)
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
Node *insertHead1(Node *head, int k) // TC : O(1)
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

Node *deleteHead(Node *head) // TC:O(1)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}
Node *deleteKthNode(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        return deleteHead(head);
    }
    Node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
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
    head = insertHead1(head, 50);
    traverse(head);
    cout << endl;
    head = deleteKthNode(head, 2);
    traverse(head);
    return 0;
}

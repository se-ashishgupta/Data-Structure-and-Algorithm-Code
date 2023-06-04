#include <iostream>
#include <vector>
#include <unordered_set>
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

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int IntersectionPointofTwoLinkedList(Node *head, Node *head1) // One Traversal
{
    int c1 = 0, c2 = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        c1++;
    }
    for (Node *curr = head1; curr != NULL; curr = curr->next)
    {
        c2++;
    }
    int d = abs(c1 - c2);
    Node *curr1, *curr2;
    if (c1 >= c2)
    {
        curr1 = head;
        curr2 = head1;
        while (d)
        {
            curr1 = curr1->next;
            d--;
        }
    }
    else
    {

        curr1 = head1;
        curr2 = head;
        while (d)
        {
            curr1 = curr1->next;
            d--;
        }
    }

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}
int main()
{
    Node *head = new Node(5);
    head->next = new Node(8);
    head->next->next = new Node(7);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(15);
    Node *head1 = new Node(9);
    head1->next = head->next->next->next;
    cout << IntersectionPointofTwoLinkedList(head, head1);
    // traverse(head);

    return 0;
}

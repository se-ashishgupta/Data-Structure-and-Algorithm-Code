#include <iostream>
#include <vector>
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

Node *ReverseLinkedListNaive(Node *head) // Two Traversal and AS:O(n)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = ReverseLinkedListNaive(head->next);
    // Node *rest_tail = head->next;
    // rest_tail->next = head;
    // or
    head->next->next = head;
    head->next = NULL;
    return rest_head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head = ReverseLinkedListNaive(head);
    traverse(head);

    return 0;
}
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

Node *ReverseLinkedList(Node *head) // TC:O(n)   AS:O(1)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *ReverseLinkedListNaive(Node *head) // Two Traversal and AS:O(n)
{
    vector<int> arr;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = arr.back();
        arr.pop_back();
    }
    return head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head = ReverseLinkedList(head);
    traverse(head);

    return 0;
}
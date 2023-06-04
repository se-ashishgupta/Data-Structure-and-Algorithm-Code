#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
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
bool PlaindromeLL(Node *head) // TC:O(m+n)   AS:O(1)
{
    if (head == NULL)
        return true;

    Node *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *rev = ReverseLinkedList(slow->next);

    Node *curr = head;
    while (rev != NULL)
    {
        if (rev->data != curr->data)
        {
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}
bool PlaindromeLLNaive(Node *head) // TC:O(m+n)   AS:O(1)
{
    stack<int> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        s.push(curr->data);
    }
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.top() != curr->data)
            return false;

        s.pop();
    }
    return true;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(10);
    cout << PlaindromeLL(head);
    return 0;
}
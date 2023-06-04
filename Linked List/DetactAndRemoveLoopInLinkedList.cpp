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

void DetectLoopInALinkedList(Node *head) // TC: O(n+m)  AS: O(n)  where n is size of loop and m is total size of LL - n approx length of LL
{
    Node *slow_p = head, *fast_p = head;
    while (slow_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            break;
    }
    if (fast_p != slow_p)
        return;
    slow_p = head;
    while (slow_p->next != fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }

    slow_p->next = NULL;
}
void FindLengthOfLoopInLL(Node *head) // TC: O(n+m)  AS: O(n)  where n is size of loop and m is total size of LL - n approx length of LL
{
    Node *slow_p = head, *fast_p = head;
    while (slow_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            break;
    }
    if (fast_p != slow_p)
        return;
    int res = 0;
    do
    {
        slow_p = slow_p->next;
        res++;
    } while (slow_p != fast_p);

    cout << res;
}
void FindFirstNodeInLoopInLL(Node *head) // TC: O(n+m)  AS: O(n)  where n is size of loop and m is total size of LL - n approx length of LL
{
    Node *slow_p = head, *fast_p = head;
    while (slow_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
            break;
    }
    if (fast_p != slow_p)
        return;
    slow_p = head;
    while (slow_p->next != fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }

    cout << fast_p->next->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head->next->next;
    FindLengthOfLoopInLL(head);

    return 0;
}
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

bool DetectLoopInALinkedList3(Node *head)
{
    Node *temp = new Node(0);
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;

        if (curr->next == temp)
        {
            return true;
        }
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}
bool DetectLoopInALinkedList4(Node *head) // TC: O(n)    AS:O(n)
{
    unordered_set<Node *> s;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;

        s.insert(curr);
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head->next;
    cout << DetectLoopInALinkedList4(head);

    return 0;
}
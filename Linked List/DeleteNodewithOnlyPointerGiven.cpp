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
void DeleteNodewithOnlyPointerGiven(Node *ptr) // But Last Node should not be given this is not handle by this trick
{
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    DeleteNodewithOnlyPointerGiven(head->next);
    traverse(head);

    return 0;
}
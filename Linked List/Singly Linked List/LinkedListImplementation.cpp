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
int main()
{

    // IMPLEMENTATION //

    // Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head->next = temp1;
    // temp1->next = temp2;

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // TRAVERSING //
    printList(head);
    cout << endl;
    printListRecuesion(head);

        return 0;
}
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtTail(Node *&Tail, int data)
{
    Node *n2 = new Node(data);
    Tail->next = n2;
    Tail = Tail->next;
    n2->next = NULL;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
Node* floydsalog(Node *head)
{
    // empty node
    if (head == NULL)
    {
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        // fast ko 2 step badhana h
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            // cycle is present
            cout << "this node is present inside loop " << slow->data << endl;
            // we can return both slow and fast because they both are in same point
            return slow;
        }
    }
   
    return NULL;
}
Node* StartingPointofLoop(Node *head)
{
    // empty node
    if (head == NULL)
    {
        return head;
    }
    Node *intersection = floydsalog(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void RemoveLop(Node *head){
    Node *startingNode=StartingPointofLoop(head);
      Node *temp = startingNode;
    while (temp->next != startingNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *n1 = new Node(10);
    head = n1;
    tail = n1;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 60);
    InsertAtTail(tail, 70);
    InsertAtTail(tail, 80);
    InsertAtTail(tail, 90);
    // we are making a loop to check this algo
    Node *temp = head;
    while (temp->data != 60)
    {
        temp = temp->next;
    }
    tail->next = temp;
    if (floydsalog(head) != NULL)
    {
        cout << "loop is present " << endl;
        StartingPointofLoop(head);
        RemoveLop(head);
    }
    else
    {
        cout << "No loop present " << endl;
    }
    print(head);
    return 0;
}
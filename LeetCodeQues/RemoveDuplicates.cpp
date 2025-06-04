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
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            next=NULL;
        }
        delete next;
        cout<<"Node deleted with data "<<value<<endl;
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
void RemoveDuplicates(Node* &head){
    if(head==NULL){
        return;
    }
    Node*curr=head;
    while (curr->next!=NULL)
    {
    if(curr->data==curr->next->data){
        Node *temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
    }
    else{
        curr=curr->next;
    }
    }
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *n1 = new Node(10);
    head = n1;
    tail = n1;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 60);
    InsertAtTail(tail, 60);
    InsertAtTail(tail, 60);
    InsertAtTail(tail, 70);
    InsertAtTail(tail, 80);
    InsertAtTail(tail, 90);
    InsertAtTail(tail, 90);
    InsertAtTail(tail, 90);
    print(head);
    RemoveDuplicates(head);
    print(head);
    return 0;
}
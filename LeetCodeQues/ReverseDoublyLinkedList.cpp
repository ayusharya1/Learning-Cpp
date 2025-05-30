#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void InsertAtTail(Node* &tail,int data){
    Node *temp=new Node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void ReverseLinkedList(Node* &head){
    if(head==NULL){
        cout<<"Linked list is empty "<<endl;
        return;
    }
    Node*next=NULL;
    Node*prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=curr->prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main(){
      Node *head=NULL;
    Node *tail=NULL;
    Node *n1=new Node(10);
    head=n1;
    tail=n1;
    InsertAtTail(tail,20);
    InsertAtTail(tail,40);
    InsertAtTail(tail,60);
    print(head);
    cout<<"head "<<head->data<<endl;
    
    ReverseLinkedList(head);
    
    print(head);
    cout<<"head "<<head->data<<endl;
    return 0;
}
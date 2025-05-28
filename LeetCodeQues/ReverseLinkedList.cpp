#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void InsertAtTail(Node* &Tail,int data){
    //create new node
    Node* n2=new Node(data);
    //insertion using tail pointer
    Tail->next=n2;
    Tail=Tail->next;
    n2->next=NULL;
}
//iterative approcah
// void ReverseLinkedList(Node* &head){
//      Node *prev=NULL;
//     Node *curr=head;
//     while(curr!=NULL){
//         Node *store=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=store;
//     }
//     head=prev;
// }
//recursive approach
void ReverseLinkedList(Node* &head,Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node *store=curr->next;
        curr->next=prev;
        prev=curr;
        curr=store;
    ReverseLinkedList(head,curr,prev);
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
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
    //iterative
    // ReverseLinkedList(head);
    //recursive
    Node *prev=NULL;
    Node *curr=head;
    ReverseLinkedList(head,curr,prev);
    print(head);
    cout<<"head "<<head->data<<endl;
    return 0;
}
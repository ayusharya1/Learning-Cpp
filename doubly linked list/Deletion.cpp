#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
     //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data "<<value<<endl;
    }
};
void InsertAtHead(Node* &head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void DeleteFromHead(Node* &head){
    Node *temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    temp->next=NULL;
    delete temp;
}
void DeleteFromTail(Node* & tail){
    Node *temp=tail;
    tail->prev->next=NULL;
    tail=temp->prev;
    delete temp;
}
void DeleteFromPos(Node* &head,Node* & tail,int pos){
    if(pos==1){
        DeleteFromHead(head);
    }
    else{
        Node *temp=head;
        Node *prv=NULL;
        for(int i=1;i<=pos-1;i++){
            prv=temp;
            temp=temp->next;
        }
        if(temp->next==NULL){
            DeleteFromTail(tail);
        }
        else{
            temp->next->prev=prv;
            prv->next=temp->next;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }
}
void print(Node* &head){
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
int main(){
     Node *node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    InsertAtHead(head,5);
    InsertAtHead(head,3);
    InsertAtHead(head,2);
    InsertAtHead(head,1);
    print(head);
    // DeleteFromHead(head);
    // DeleteFromTail(tail);
    DeleteFromPos(head,tail,2);
    print(head);
    return 0;
}
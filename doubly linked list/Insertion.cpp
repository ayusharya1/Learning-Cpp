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
void InsertAtHead(Node* &head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void print(Node* &head){
    Node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
void InsertAtTail(Node* &tail,int data){
    Node *temp=new Node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void InsertAtPoint(Node* &head,Node* &tail,int data,int position){
    if(position==1){
        InsertAtHead(head,data);
    }
    else{
        Node *temp=head;
       for(int i=1;i<position-1;i++){
        temp=temp->next;
       }
    if(temp->next == NULL){
          InsertAtTail(tail,data);
    }
    else{
    Node *newone=new Node(data);
       newone->next=temp->next;
      temp->next->prev=newone;
      temp->next=newone;
      newone->prev=temp;
    }
       
        
    }
}
int main(){
    Node *node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    InsertAtHead(head,5);
    InsertAtHead(head,3);
    InsertAtTail(tail,55);
    InsertAtTail(tail,65);
    InsertAtPoint(head,tail,8,3);
    InsertAtPoint(head,tail,100,7);
    print(head);
    return 0;
}
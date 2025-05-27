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
void InsertAtHead(Node* &Head,int data){//Humne Head mein reference isliye liyah kyunki mein copy nhi banana chata jh changes honge direct Head mein
    //create new node
    Node* n2=new Node(data);
    //insertion using head pointer

    n2->next=Head;
    Head=n2;
}
void InsertAtTail(Node* &Tail,int data){
    //create new node
    Node* n2=new Node(data);
    //insertion using tail pointer
    Tail->next=n2;
    Tail=Tail->next;
    n2->next=NULL;
}
void InsertAtAnyPoint(Node *Head,int data,int pos){
    Node *temp=Head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    Node *n2=new Node(data);
    n2->next=temp->next;
    temp->next=n2;
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
    InsertAtHead(head,5);
    InsertAtTail(tail,20);
    InsertAtTail(tail,40);
    InsertAtTail(tail,60);
    InsertAtAnyPoint(head,15,3);
    print(head);
    return 0;
}
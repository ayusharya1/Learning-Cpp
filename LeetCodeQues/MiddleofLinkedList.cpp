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
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int length(Node *head){
    Node *temp=head;
    int count=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void Middle(Node*head){
    Node* temp=head;
    int i=1;
    int mid=length(head)/2 + 1;
    while (i<mid && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    cout<<"Middle is  "<<temp->data<<endl;
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
    InsertAtTail(tail,70);
    InsertAtTail(tail,80);
    print(head);
    Middle(head);
    return 0;
}
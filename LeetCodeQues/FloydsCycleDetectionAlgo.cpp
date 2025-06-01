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
    Node* n2=new Node(data);
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
bool floydsalog(Node *head){
    //empty node
    if(head==NULL){
        return false;
    }
    Node *fast=head;
    Node *slow=head;
    while (fast != NULL && fast->next != NULL)
    {
        //fast ko 2 step badhana h
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            //cycle is present
            cout<<"this node is present inside loop "<<slow->data<<endl;
            return true;
        }
    }
    return false;
    
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
    InsertAtTail(tail,90);
    //we are making a loop to check this algo
    Node* temp=head;
    while(temp->data!=60){
        temp=temp->next;
    }
    tail->next=temp;
    if(floydsalog(head)==true){
        cout<<"loop is present "<<endl;
    }
    else{
       cout<<"No loop present "<<endl; 
    }
    return 0;
}
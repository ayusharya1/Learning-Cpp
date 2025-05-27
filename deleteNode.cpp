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
    ~ Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;    // Recursively deletes the next node
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
    /*Recursion to delete entire list: If a node is deleted and it still points to another node (next != NULL), the destructor will also delete that next node. This continues recursively until the end of the list. This is useful when you want to delete the entire list from a single node.
this->next = NULL;: After deleting the next node, the pointer is set to NULL to avoid dangling pointers.*/
};
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void DeleteNodeStart(Node* &head){
    Node *temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    cout<<"start wale chale "<<endl;
}
void DeleteNodeEnd(Node* &head,Node* &tail){
    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node *curr=temp->next;
    temp->next=NULL;
    tail=temp;
    curr->next=NULL;
    cout<<"mein chala"<<endl;
    delete curr;
    
}
void DeleteAtpoint(Node* &head,Node* &tail,int i){
    if(i==1){
        DeleteNodeStart(head);
    }
    else{
        Node *curr=head;
        Node *prev=NULL;
        int cnt=1;
        while(cnt<i){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            DeleteNodeEnd(head,tail);
        }
        else{
            prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        }

    }
}
int main(){
     Node *head=NULL;
    Node *tail=NULL;
    Node *n1=new Node(10);
    Node *n2=new Node(20);
    Node *n3=new Node(30);
    Node *n4=new Node(50);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;
    head=n1;
    tail=n4;
    print(head);
    // DeleteNodeStart(head);
    // DeleteNodeEnd(head,tail);
    DeleteAtpoint(head,tail,2);
    print(head);
    return 0;
}
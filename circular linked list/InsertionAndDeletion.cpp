#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data "<<value<<endl;
    }
};
void InsertNode(Node* &tail,int element,int data){
    //list is empty
    if(tail==NULL){
        Node *temp=new Node(data);
        temp->next=temp;
        tail=temp;
    }
    else{
        //List is not empty
        Node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node *newnode=new Node(data);
        newnode->next=curr->next;
        curr->next=newnode;
        
    }
}
//traverse circular liniked list
void print(Node *tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"list is empty "<<endl;
        return;
    }
    do{
        cout<<tail->data<<endl;
        tail=tail->next;
    } while(tail!=temp);
}
void DeleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty "<<endl;
        return;
    }
    else{
        Node *prev=tail;
        Node *curr=tail->next;
        while (curr ->data !=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 node in linked list
        if(curr==prev){
            tail=NULL;
            
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
            delete curr;
    }
}

int main(){
    Node* tail=NULL;
    InsertNode(tail,5,3);
    InsertNode(tail,3,6);
    InsertNode(tail,6,9);
    InsertNode(tail,3,5);
    print(tail);
    DeleteNode(tail,6);
    print(tail);
    return 0;
}
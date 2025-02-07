#include<iostream>
#include<vector>
#define ST static int
using namespace std; 
class Node{
public:
    int data ;
    Node* next;

    Node(int val){
        data = val ; 
        next = NULL;
    }
};
class List{
    Node* head ; 
    Node* tail ; 
public: 
    List(){
        head = NULL ; 
        tail = NULL ;
    }

    void push_front( int val ){
        Node *newNode = new Node(val);
        if ( head == NULL){
            head = newNode;
            tail = newNode;
        }else {
            (*newNode).next = head ; 
            head = newNode ; 
        }
    }

    void push_back( int val ){
        Node *newNode = new Node(val);
        if ( tail == NULL){
            head = newNode ; 
            tail = newNode ;
        }else {
            (*tail).next = newNode ;
            tail = newNode;
        }
    }

    void print(){
        Node* temp = head ; 
        while ( temp != NULL){
            cout<<(*temp).data<<" -> ";
            temp = (*temp).next ; 
        }
        cout<<"NULL"<<endl;
    }

    void pop_front(){
        if( head == NULL){
            cout<<"Linked List is empty\n";
            return;
        }
        Node *temp = head ; 
        head = (*temp).next ; 
        (*temp).next = NULL;
        delete temp ;
    }
    
    void pop_back(){
        if( tail == NULL){
            cout<<"Linked List is empty\n";
            return;
        }
        Node* temp = head ; 
        while( (*temp).next != tail){
            temp = (*temp).next;
        }
        (*temp).next = NULL ;
        delete tail;   
        tail = temp ; 
    }
};
int main(){
    List ll;
    
    ll.push_back(0);
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.print();
    ll.pop_back();
    ll.pop_front();
    ll.print();

    system("pause");
    return 0;
}
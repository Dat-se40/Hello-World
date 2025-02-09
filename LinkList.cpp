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
    void insert(int val, int pos) {
        
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }
        
        if (pos == 0) {
            push_front(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* temp = head;
        int index = 0;
    
        while (temp != NULL && index < pos - 1) {
            temp = temp->next;
            index++;
        }
        
        if (temp == NULL) {
            cout << "Position exceeds list length\n";
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void write(){
        int size , val ; 
        
        cout<<"Enter the size of Linked List ";
        cin>>size;

        for ( int i = 0 ; i < size ; i++){
            cout<<"Enter the value of Node["<<i<<"] :\n"; 
            cin>>val;
            push_back(val);
        }
    }

    int search( int target ){
        Node* temp  = head;
        int index = 0 ; 

        while ( temp != NULL){
            if ( temp ->data == target ) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }
    
};
int main(){
    List ll;
    
    ll.write();
    ll.print();
    
    system("pause");
    return 0;
}

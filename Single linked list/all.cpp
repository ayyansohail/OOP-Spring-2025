#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    //Constructor to initialize node with a given value
    Node(int value){
        data = value;
        next = nullptr; //Initially the node does not point to any other node
    }
};

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(int value){
       Node* newNode = new Node(value);
       newNode->next = head;
       head = newNode;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);

        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){ //Traverse to last node
            temp = temp->next;
        }
        temp->next = newNode; //Link last node to new node 
    }

    //Delete a node by value
    void deleteValue(int value){
        if(head == nullptr){
            return;
        }
        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next->data != value && temp->next != nullptr){
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout<<"Value not found"<<endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void display(){
        if(head == nullptr){
            cout<<"Linked List is empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;

    }
};

int main() {
    LinkedList List;
    List.insertAtBeginning(10);
    List.insertAtBeginning(20);
    List.insertAtEnd(30);
    List.insertAtEnd(40);

    cout<<"Linked List after insertions: ";
    List.display();

    List.deleteValue(20);
    cout<<"List After deletion: ";
    List.display();
}
#include<iostream>
using namespace std;

template<typename T>

class GenericLinkedList {

    private:
    struct Node {
        T data;
        Node* next;

        Node(T d): data(d), next(nullptr) {}
    };

    Node* head;

    public:
    GenericLinkedList(): head(nullptr) {}
    
    void insertAtTail(T val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFromTail(){
        if(head == nullptr){
            throw runtime_error("Linked List is empty");
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void print() {
        if(head == nullptr){
            throw runtime_error("Linked List is empty");
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    GenericLinkedList<int> intGLL;
    intGLL.insertAtTail(1);
    intGLL.insertAtTail(2);
    intGLL.insertAtTail(3);
    intGLL.print();
    intGLL.deleteFromTail();
    intGLL.print();

    GenericLinkedList<double> doubleGLL;
    doubleGLL.insertAtTail(1.1);
    doubleGLL.insertAtTail(2.2);
    doubleGLL.print();
    doubleGLL.deleteFromTail();
    doubleGLL.print();
}








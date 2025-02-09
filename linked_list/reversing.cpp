#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
class LinkedList {
    Node* head;
    public:
    LinkedList(){
        this->head = NULL;
    }
    void insertAtTail(int data){
        Node* temp = head;
        if(head==NULL){
            head = new Node(data);
            return;
        }
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
        return;
    }
    void printLL(){
        if(head==NULL){
            cout << "Empty Linked List!" << endl;
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //Reversing
    void reverseIterative(){
        if(head->next==NULL || head==NULL){
            return;
        }
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr->next;
        while(next!=NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        head = curr;
    }
};

int main(){
    LinkedList ll = LinkedList();
    ll.insertAtTail(5);
    ll.insertAtTail(11);
    ll.insertAtTail(19);
    ll.insertAtTail(17);
    ll.insertAtTail(51);
    ll.printLL();
    ll.reverseIterative();
    ll.printLL();


}
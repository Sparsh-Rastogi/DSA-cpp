#include <bits/stdc++.h>
using namespace std;

string arr [] = {"1. Add Node at Head", "2. Add Node at Tail", "3. Insert node", "4. Delete node from "};

void ask(){
    for(int i = 0;i<4;i++){
        cout << arr[i] << endl;
    }
}

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

    //insertion
    void insertAtHead(int data){
        Node* temp = new Node();
        temp->data = data;
        if(head==NULL){
            head = temp;
            head->next = NULL;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void insertAtTail(int data){
        if(head==NULL){
            insertAtHead(data);
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
        return;
    }
    void insertAt(int pos, int data){
        if(head==NULL && pos!=0){
            cout << "invalid argument!" << endl;
            return;
        }
        if(pos==0){
            insertAtHead(data);
            return;
        }
        Node* temp = head;
        pos--;
        while(pos--){
            if(temp==NULL){
                cout << "Linked List not of sufficient length!" << endl;
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
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

    //deletion
    void deleteAt(int pos){
        if(head==NULL){
            cout << "Can't perform deletion on Empty List" << endl;
            return;
        }
        Node* temp = head;
        if(pos==0){
            head = head->next;
            return;
        }
        pos--;
        while(pos--){
            if(temp==NULL){
                cout << "Linked List not of sufficient length!" << endl;
                return;
            }
            temp = temp->next;
        }
        if(temp->next==NULL){
            cout << "Linked List not of sufficient length!" << endl;
            return;
        }
        temp->next = temp->next->next;
        return;
    }
};

int main(){
    LinkedList ll = LinkedList();
    while(true){
        ask();
        int ans;
        cin >> ans;
        if(ans == 1){
            cout << "Enter the data to add: " << endl;
            cin >> ans;
            ll.insertAtHead(ans);
            cout << endl;
        }
        else if(ans==2){
            cout << "Enter the data to add: " << endl;
            cin >> ans;
            ll.insertAtTail(ans);
            cout << endl;
        }
        else if(ans==3){
            cout << "Enter the position to add at: " << endl;
            int pos;
            cin >> pos;
            cout << endl << "Enter the data to add: " << endl;
            cin >> ans;
            cout << endl;
            ll.insertAt(pos,ans);
        }
        else if(ans == 4){
            cout << "Enter the position to remove from? " << endl;
            cin >> ans;
            cout << endl;
            ll.deleteAt(ans);
        }
        else{
            return 0;
        }
        ll.printLL();
    }

    
}
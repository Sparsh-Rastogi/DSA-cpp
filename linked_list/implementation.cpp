#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist {
    Node *head;

  public:
    Linkedlist() {
        head = NULL;
    }
    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }
    void insertAt(int pos,int data){
        if(pos==0){
            this->insertAtHead(data);
            return;
        }
        Node* temp = head;
        pos--;
        while(pos--){
            if(temp->next==NULL){
                cout << "Not a valid position" << endl;
                return;
            }
            temp = temp->next;
        }
        Node *node = new Node(data);
        node->next = temp->next;
        temp->next = node;
    }
    void insertAtTail(int data){
        if(head==NULL){
            this->insertAtHead(data);
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        Node* node = new Node(data);
        temp->next = node;
    }
    void print() {
        Node *temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Linkedlist arrToLL(int arr[], int n){
    Linkedlist list;
    for(int i = n-1;i>-1;i--){
        list.insertAtHead(arr[i]);
    }
    return list;
}
int main() {
    Linkedlist list;
    int arr[] = {1,4,7,8,4,2,5};
    list = arrToLL(arr,sizeof(arr)/sizeof(int));
    list.print();
    list.insertAt(2,29);
    list.print();
    list.insertAtTail(57);
    list.print();
    return 0;
}
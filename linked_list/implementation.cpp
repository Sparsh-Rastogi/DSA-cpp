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
    cout << "Elements of the list are: ";
    list.print();
    cout << endl;
    return 0;
}
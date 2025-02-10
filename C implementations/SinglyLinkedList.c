#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
}LinkedList;

Node* newnode(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
LinkedList* newLL(){
    LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->head = NULL;
    return temp;
}
void atTail(LinkedList* ll,int value){
    Node* temp = newnode(value);
    if(ll->head == NULL){
        ll->head = temp;
        return;
    }
    Node* i = ll->head;
    while(i->next!=NULL){
        i = i->next;
    }
    i->next = temp;
    return;
}

void atHead(LinkedList* ll, int value){
    Node* temp = newnode(value);
    if(ll->head == NULL){
        ll->head = temp;
        return;
    }
    temp->next = ll->head;
    ll->head = temp;
    return;
}
int length(LinkedList* ll){
    if(ll->head == NULL){
        return 0;
    }
    Node* i = ll->head;
    int len = 0;
    while(i!=NULL){
        i = i->next;
        len++;
    }
    return len;
}
void atPos(LinkedList* ll, int value, int pos){
    if(pos>length(ll)){
        printf("Invalid input \n");
    }
    Node* temp = newnode(value);
    if(pos==0){
        atHead(ll,value);
        return;
    }
    pos--;
    Node* i = ll->head;
    while(pos--){
        i=i->next;
    }
    temp->next = i->next;
    i->next = temp;
    return;
}
void printLL(LinkedList* ll){
    Node* temp = ll->head;
    if(temp==NULL){
        printf("Empty List! \n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next; 
    }
    printf("\n");
    return;
}
void delAtHead(LinkedList* ll){
    if(ll->head== NULL){
        printf("The LinkedList is empty \n");
        return;
    }
    ll->head = ll->head->next;
}
void delAtTail(LinkedList* ll){
    if(ll->head == NULL){
        printf("The linkedlist is empty \n");
        return;
    }
    Node* i = ll->head;
    if(i->next==NULL){
        delAtHead(ll);
    }
    while(i->next->next!=NULL){
        i = i->next;
    }
    i->next = i->next->next;
    return;
}
void delAtPos(LinkedList* ll,int pos){
    if(pos>length(ll)-1){
        printf("Invalid Input! \n");
        return;
    }
    if(pos==0){
        delAtHead(ll);
        return;
    }
    pos--;
    Node* i = ll->head;
    while(pos--){
        i=i->next;
    }
    i->next = i->next->next;
}
int main(){
    LinkedList* ll = newLL();
    atTail(ll,11);
    atTail(ll,13);
    atTail(ll,17);
    atTail(ll,21);
    printf("%d \n",length(ll));
    printLL(ll);
    atHead(ll,3);
    atHead(ll,5);
    printLL(ll);
    printf("%d \n",length(ll));
    atPos(ll,4,2);
    printLL(ll);
    delAtHead(ll);
    printLL(ll);
    delAtTail(ll);
    printLL(ll);
    delAtPos(ll,4);
    printLL(ll);
    delAtPos(ll,1);
    printLL(ll);
}

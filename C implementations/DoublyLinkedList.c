#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
}LinkedList;

Node* newnode(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
LinkedList* newLL(){
    LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

void atHead(LinkedList* ll, int value){
    Node* temp = newnode(value);
    if(ll->head==NULL){
        ll->head = temp;
        ll->tail = temp;
        return;
    }
    ll->head->prev = temp;
    temp->next = ll->head;
    ll->head = temp;
}
void atTail(LinkedList* ll, int value){
    Node* temp = newnode(value);
    if(ll->head==NULL){
        atHead(ll,value);
    }
    Node* i = ll->head;
    while(i->next!=NULL){
        i=i->next;
    }
    i->next = temp;
    temp->prev = i;
    ll->tail = temp;
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
void RprintLL(LinkedList* ll){
    Node* temp = ll->tail;
    if(temp==NULL){
        printf("Empty List! \n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
    return;
}

int main(){
    LinkedList* ll = newLL();
    atHead(ll,3);
    atHead(ll,11);
    printLL(ll);
    atHead(ll,5);
    atTail(ll,19);
    printLL(ll);
    RprintLL(ll);
}

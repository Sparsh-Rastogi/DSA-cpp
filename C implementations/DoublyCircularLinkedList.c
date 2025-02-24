#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next; 
    struct Node* prev;
} Node;

typedef struct CDLL
{
    Node* head;
} CDLL;

Node* newNode(){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

CDLL* newLinkedList(){
    CDLL* temp = (CDLL*)malloc(sizeof(CDLL));
    temp->head = NULL;
    return temp;
}

void insertAtHead(CDLL* ll,int data){
    Node* temp = newNode();
    temp->data = data;
    if(ll->head==NULL){
        ll->head = temp;
        ll->head->next = ll->head;
        ll->head->prev = ll->head;
        return;
    }
    temp->next = ll->head;
    temp->prev = ll->head->prev;
    ll->head->prev->next = temp;
    ll->head->prev = temp;
    ll->head = temp;
}

void insertAtPos(CDLL* ll, int data, int index){
    if(index==0){
        insertAtHead(ll,data);
        return;
    }
    Node* temp = newNode();
    temp->data = data;
    Node* i= ll->head;
    index--;
    while(index--){
        i=i->next;
    }
    temp->next = i->next;
    temp->prev = i;
    i->next = temp;
    i->next->next->prev = temp;
    return;
}
void deleteAtHead(CDLL* ll){
    if(ll->head==NULL){
        printf("Empty List! \n");
        return;
    }
    if(ll->head->next==ll->head){
        ll->head = NULL;
        return;
    }
    ll->head->next->prev = ll->head->prev;
    ll->head->prev->next = ll->head->next;
    ll->head = ll->head->next;
    return;
}
void deleteAtPos(CDLL* ll,int pos){
    if(ll->head==NULL){
        printf("Empty List! \n");
    }
    Node* i = ll->head;
    while(pos--){
        i = i->next;
    }
    i->prev->next = i->next;
    i->prev->next->prev = i->prev;
    return;
}

void traversal(CDLL* ll){
    if(ll->head == NULL){
        printf("Empty List! \n");
        return;
    }
    Node* temp = ll->head;
    printf("%d ", temp->data);
    temp = temp->next;
    while(temp!=ll->head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(CDLL* ll){
    if(ll->head == NULL){
        printf("Empty List!");
        return;
    }
    Node* temp = ll->head->prev;
    printf("%d ", temp->data);
    temp = temp->prev;
    while (temp!=ll->head->prev)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    
}

void search(CDLL* ll, int target){
    if(ll->head==NULL){
        printf("Empty List! \n");
        return;
    }
    Node* i = ll->head;
    int ctr=0;
    while(i->data!=target){
        i = i->next;
        ctr++;
        if(i==ll->head){
            printf("Not Found! \n");
            return;
        }
    }
    printf("Found at %d \n",ctr);

}
int main(){
    CDLL* ll = newLinkedList();
    insertAtHead(ll,5);
    insertAtHead(ll,9);
    insertAtHead(ll,17);
    insertAtHead(ll,23);
    traversal(ll);
    insertAtPos(ll,13,2);
    traversal(ll);
    reverse(ll);
    deleteAtPos(ll,1);
    traversal(ll);
    search(ll,9);
    search(ll,8);
    deleteAtHead(ll);
    traversal(ll);
}

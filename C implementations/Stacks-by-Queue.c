#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int front;
    int rear;
    int arr[100];
} queue;

//implementing a queue
int isEmpty(queue *Q){
    if(Q->front==-1){
        return 1;
    }
    return 0;
}

int isFull(queue *Q){
    if(Q->rear==99){
        return 1;
    }
    return 0;
}

int peek(queue *Q){
    if(isEmpty(Q)){
        printf("The queue is empty!");
        exit(137);
    }
    return Q->arr[Q->front];
}

int Enqueue(queue *Q, int data){
    if(isFull(Q)){
        printf("The queue is full!");
        exit(137);
    }
    if(Q->front==-1){
        Q->front++;
    }
    Q->rear++;
    Q->arr[Q->rear] = data;
}

int Dequeue(queue *Q){
    if(isEmpty(Q)){
        printf("The queue is empty!");
        exit(137);
    }
    Q->front++;
    if(Q->front>Q->rear){
        Q->rear=-1;
        Q->front=-1;
    };
}

int printQueue(queue *Q){
    int temp = Q->front;
    while(temp<=Q->rear){
        printf("%d ",Q->arr[temp]);
        temp++;
    }
    printf("\n");
}

//implementing stack using queue
int push(queue* Q,int data){
    queue temp = {-1,-1};
    Enqueue(&temp,data);
    while(!isEmpty(Q)){
        Enqueue(&temp,peek(Q));
        Dequeue(Q);
    }
    while(!isEmpty(&temp)){
        Enqueue(Q,peek(&temp));
        Dequeue(&temp);
    }
}

int pop(queue* Q){
    int to_return = peek(Q);
    Dequeue(Q);
    return to_return;
}

int printStack(queue* Q){
    queue temp = *Q;
    queue stack = {-1,-1};
    while(!isEmpty(&temp)){
        push(&stack,pop(&temp));
    }
    while(!isEmpty(&stack)){
        printf("%d ",pop(&stack));
    }
    printf("\n");
}
int main(){
    queue q ={-1,-1};
    push(&q,10);
    push(&q,5);
    push(&q,11);
    printStack(&q);
    pop(&q);
    printStack(&q);
    push(&q,55);
    printStack(&q);
    printf("%d \n",peek(&q));
}
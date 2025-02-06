#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int arr [100];
    int top;
} Stack;
//implementing a stack
int isEmpty(Stack* S){
    if(S->top==-1){
        return 1;
    }
    return 0;
}

int isFull(Stack* S){
    if(S->top==99){
        return 1;
    }
    return 0;
}

int peek(Stack* S){
    if(isEmpty(S)){
        printf("Stack is empty!");
        return -1;
    }
    return S->arr[S->top];
}

int push(Stack *S, int data){
    if(isFull(S)){
        printf("The Stack is full!");
        exit(137);
    }
    S->top++;
    S->arr[S->top] = data;
}

int pop(Stack *S){
    if(isEmpty(S)){
        printf("Stack i empty!");
        return -1;
    }
    S->top--;
    return S->arr[S->top + 1];
}

int printStack(Stack *S){
    int temp = S->top;
    while(temp!=-1){
        printf("%d ",S->arr[temp]);
        temp--;
    }
    printf("\n");
}

//implementing queue with stack
int enqueue(Stack* S, int data){
    Stack temp;
    temp.top=-1;
    while(!isEmpty(S)){
        push(&temp,pop(S));
    }
    push(S,data);
    while(!isEmpty(&temp)){
        push(S,pop(&temp));
    }
}
int dequeue(Stack* S){
    return pop(S);
}
int main(){
    Stack q;
    q.top=-1;
    enqueue(&q,2);
    enqueue(&q,5);
    enqueue(&q,9);
    enqueue(&q,17);
    printStack(&q);
    dequeue(&q);
    printStack(&q);
    printf("%d",peek(&q));

}
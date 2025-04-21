#include <bits/stdc++.h>
using namespace std;
int st[100];
int top = 0;
typedef struct Node{
    int data;
    struct Node* next;
} node;

void dfs(int i, node** adjList,int* visited){
    node* it = adjList[i];
    while(it!=NULL){
        // cout << "HERE it is: " << it->data << endl;
        if(!visited[it->data])dfs(it->data,adjList,visited); 
        it = it->next;
    }
    visited[i] = 1;
    st[top++] = i;
    return;
}
int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    int visited[n+1] = {0};
    node** adjList = (node**)malloc(sizeof(node*)*(n+1));
    for(int i = 0;i<n+1;i++){
        adjList[i]=NULL;
    }

    int e1,e2;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2;
        node* it = adjList[e1];
        if(it==NULL){
            adjList[e1] = new node();
            adjList[e1]->data = e2;
            adjList[e1]->next = NULL;
            continue;
        }
        while(it->next!=NULL){
            it = it->next;
        }
        it->next = new node();
        it->next->data = e2;
        it->next->next = NULL;
    }
    for(int i = 0;i<n;i++){
        if(visited[i])continue;
        dfs(i, adjList,visited);
    }
    for(int i = --top;i>-1;i--){
        cout << st[i] << " ";
    }
    cout << endl;
    
    
}
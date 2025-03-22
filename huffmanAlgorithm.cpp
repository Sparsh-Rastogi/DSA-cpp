#include <bits/stdc++.h>
using namespace std;
int parent(int i){return (i-1)/2;}
int left(int i){return 2*i +1;}
int right(int i){return 2*i +2;}
struct Node
{
    pair<char,int> data;
    struct Node* left;
    struct Node* right;
    Node(pair<char,int> val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void printv(vector<Node*> &v){
    for(int i = 0;i<v.size();i++){
        if(v[i]==nullptr){continue;}
        cout << v[i]->data.first << " " << v[i]->data.second << " , ";
    }
    cout << endl;
}

typedef struct PQueue {
    vector<Node*> v;
    int front;
    int rear;

    PQueue() : v(100, nullptr), front(-1), rear(-1) {}
} PQueue;


int AgreaterB(Node* a, Node* b){
    if(a->data.second==b->data.second){return a->data.first>b->data.first;}
    return a->data.second>b->data.second;
}
void heapifyUp(vector<Node*> &v, int i,int front){
    if(i<=front){return;}
    if(AgreaterB(v[parent(i)],v[i])){
        swap(v[i],v[parent(i)]);
    }
    heapifyUp(v,parent(i),front);
    return;
}
void heapifyDown(vector<Node*> &v, int i,int rear){
    // cout << "size: " << size << endl;
    //cout << v[i]->data.first << " " << v[i]->data.second << endl;
    if(left(i)>=rear && right(i)>=rear){
        return;
    }
    else if(left(i)>=rear){
        if(AgreaterB(v[i],v[right(i)])){
            swap(v[i],v[right(i)]);
            heapifyDown(v,right(i),rear);
        }
        return;
    }
    else if(right(i)>=rear){
        if(AgreaterB(v[i],v[left(i)])){
            swap(v[i],v[left(i)]);
            heapifyDown(v,left(i),rear);
        }
        return;
    }
    else{
        if(AgreaterB(v[left(i)],v[right(i)])){
            if(AgreaterB(v[i],v[right(i)])){
                swap(v[i],v[right(i)]);
                heapifyDown(v,right(i),rear);
            }
            return;
        }
        else{
            if(AgreaterB(v[i],v[left(i)])){
                swap(v[i],v[left(i)]);
                heapifyDown(v,left(i),rear);
            }
            return;
        }
    }
}
void buildHeap(vector<Node*> &v,int front){
    for(int i =0;i<v.size();i++){
        heapifyUp(v,i,front);
    }
    return;
}
void heapSort(vector<Node*> &v,int front,int rear){
    for(int i = 0;i<rear-front;i++){
        swap(v[rear-i-1],v[front]);
        heapifyDown(v,0,rear-i-1);
        // printv(v);
    }
}
Node* deQueue(PQueue* q){
    Node* toreturn = q->v[q->front];
    q->rear--;
    swap(q->v[q->front],q->v[q->rear]);
    heapifyDown(q->v,q->front,q->rear);
    if(q->front==q->rear){
        q->front = -1;
        q->rear = -1;
    }
    return toreturn;
}
void insert(PQueue* q, Node* a){
    if(q->rear==-1){
        q->front=0;
        q->rear=0;
    }
    q->v[q->rear]= a;
    
    heapifyUp(q->v,q->rear,q->front);
    q->rear++;
    return;
}

Node* huffmanTree(PQueue* q){
    while(q->rear-q->front!=1){
        Node* l = deQueue(q);
        Node* r = deQueue(q);
        Node* root = new Node({'#',l->data.second+r->data.second}); 
        root->left = l;
        root->right = r;
        insert(q,root);
        //printv(q->v);
    }
    return deQueue(q);
}
void huffmanCode(Node* root, string* code, string s){
    if(root==NULL){return;}
    if(root->data.first!='#'){
        code[(int)(root->data.first - 'a' )] = s;
        return;
    }
    huffmanCode(root->left,code,s+"0");
    huffmanCode(root->right,code,s+"1");
}
void preOrder(Node* root){
    if(root==NULL){return;}
    printf("%c %d ", root->data.first, root->data.second);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root==NULL){return;}
    inOrder(root->left);
    printf("%c %d ", root->data.first, root->data.second);
    inOrder(root->right);
}
int main(){
    string s;
    int freqTable[26] = {0};
    cin >> s;
    for(int i =0;i<s.size();i++){
        freqTable[s[i]-'a']++;
    }
    PQueue my_priority_queue;
    PQueue* q= &my_priority_queue;
    for(int i = 0;i<26;i++){
        if(freqTable[i]!=0){
            // cout << (char)(i+'a') << " : " << freqTable[i] << endl;
            Node* temp = new Node({(char)(i+'a'),freqTable[i]});
            insert(q,temp);
        }
    }
    Node* root = huffmanTree(q);
    // preOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    string code[26] = {""};
    huffmanCode(root,code,"");
    for(int i = 0;i<26;i++){
        if(code[i]!=""){
            cout << (char)(i+'a') << " : " << code[i] << endl;
        }
    }
    //heapSort(q->v,q->front,q->rear);
    //printv(q->v);
    
    return 0;

}
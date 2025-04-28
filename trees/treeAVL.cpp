#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int getHeight(Node* a){
    return a?a->height:0;
}
Node* Lrotate(Node* a){
    Node* c = a->right;
    a->right = c->left;
    c->left = a;
    a->height = 1+max(getHeight(a->right),getHeight(a->left));
    c->height = 1+max(getHeight(c->right),getHeight(c->left));
    return c;
    
}
Node* Rrotate(Node* a){
    Node* b = a->left;
    a->left = b->right;
    b->right = a;
    a->height = 1+max(getHeight(a->right),getHeight(a->left));
    b->height = 1+max(getHeight(b->right),getHeight(b->left));
    return b;
}
Node* LRrotate(Node* a){
    a->left = Lrotate(a->left);
    return Rrotate(a);
    
}
Node* RLrotate(Node* a){
    a->right = Rrotate(a->right);
    return Lrotate(a);
}
Node* insert(Node* root, int key){
    if(root==NULL){
        Node* a = (Node*)malloc(sizeof(Node));
        a->left = NULL;
        a->right = NULL;
        a->height = 1;
        a->data = key;
        return a;
    }
    if(key<root->data){
        root->left = insert(root->left,key);
    }
    else if (key>root->data){
        root->right = insert(root->right,key);
    }
    
    root->height = 1+max(getHeight(root->right),getHeight(root->left));
    
    int bF = getHeight(root->left) - getHeight(root->right);
    if(bF>1 && key<root->left->data){
        return Rrotate(root);
    }
    if(bF>1 && key>root->left->data){
        return LRrotate(root);
    }
    if(bF<-1 && key>root->right->data){
        cout << "L rotatinggg" << bF << endl;
        return Lrotate(root);
    }
    if(bF<-1 && key<root->right->data){
        return RLrotate(root);
    }
    return root;
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front(); q.pop();
        cout << temp->data << " " ;
        if(temp->left!=NULL){q.push(temp->left);}
        if(temp->right!=NULL){q.push(temp->right);}
    }
}
void preOrder(Node* root){
    if(root==NULL){return;}
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root==NULL){return;}
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL){return;}
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main(){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 1;
    root->height = 1;
    root->left= NULL;
    root->right = NULL;
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    
}
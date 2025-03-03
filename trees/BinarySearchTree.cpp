#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left=NULL;
    temp->right = NULL;
    return temp;
}
void insert(Node* root, int val){
    Node* i = root;
    Node* temp = newNode(val);
    while (1)
    {
        if(val>i->data){
            if(i->right==NULL){
                i->right=temp;
                return;
            }
            else{
                i = i->right;
            }
        }
        else{
            if(i->left==NULL){
                i->left=temp;
                return;
            }
            else{
                i = i->left;
            }
        }
    }
}
void search(Node* root, int val){
    if(root==NULL){
        cout << "element not found " << endl;
        return;
    }
    if(root->data>val){
        search(root->left,val);
    }
    else if(root->data<val){
        search(root->right,val);
    }
    else{
        cout << "Element Found!" << endl;
    }
}

Node* deleteNode(Node* root, int val){
    if(root==NULL){
        cout << "element not found " << endl;
        return NULL;
    }
    if(root->data>val){
        root->left = deleteNode(root->left,val);
    }
    else if(root->data<val){
        root->right = deleteNode(root->right,val);
    }
    else{
        if(root->left ==NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        Node* temp = root->right;
        while(temp->left){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
void inOrder(Node* root){
    if(root==NULL){return;}
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main(){
    Node* root = newNode(5);
    insert(root,11);
    insert(root,7);
    insert(root,21);
    insert(root,39);
    inOrder(root);
    cout << endl;
    deleteNode(root,21);
    inOrder(root);
}
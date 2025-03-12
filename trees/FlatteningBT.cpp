#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void flatten(Node* root){
    if(root==NULL){return;}
    flatten(root->right);
    flatten(root->left);
    Node* temp = root;
    if(temp->left!=NULL){
        temp = temp->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
    }
    //cout << temp->data << endl;
    temp->right = root->right;
    if(root->left!=NULL){
        root->right = root->left;
    }
    root->left = NULL;
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    // inOrder(root);
    // cout << endl;
    flatten(root);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
}

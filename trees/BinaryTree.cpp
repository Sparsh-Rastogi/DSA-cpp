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
/*
   1
  / \
 /   \
 2   3
/ \ / \
4 5 6 7 
*/
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
int height(Node* root){
    if(root==NULL){return 0;}
    return max(height(root->left),height(root->right))+1;
}
Node* preInTree(int* pre, int* in,int low, int high, int* ctr){
    //high is not inclusive
    Node* root = new Node(pre[*ctr]);
    if(low>=high){return NULL;}
    for(int i = low;i<high;i++){
        
        //cout << i << " " << *ctr << endl;
        if(in[i]==pre[*ctr]){
            *ctr = *ctr + 1;
            root->left = preInTree(pre,in,low,i,ctr);
            if(root->left==NULL){*ctr = *ctr -1;}
            *ctr = *ctr + 1;
            root->right = preInTree(pre,in,i+1,high,ctr);
            if(root->right==NULL){*ctr = *ctr -1;}
            return root;
        }
    }
    return NULL;
}
Node* postInTree(int* post, int* in, int low, int high, int*ctr){
    Node* root = new Node(post[*ctr]);
    if(low>=high){return NULL;}
    for(int i = low;i<high;i++){
        //cout << i << " " << *ctr << " " << high << " " << low << endl;
        if(in[i]==post[*ctr]){
            *ctr= *ctr -1;
            root->right = postInTree(post,in,i+1,high,ctr);
            if(root->right==NULL){*ctr = *ctr +1;}
            *ctr = *ctr -1;
            root->left = postInTree(post,in,low,i,ctr);
            if(root->left==NULL){*ctr = *ctr +1;}
            return root;
        }
    }
    return NULL;
}
int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // preOrder(root);
    // printf("\n");
    // inOrder(root);
    // printf("\n");
    // postOrder(root);
    // printf("\n");
    // printf("height of tree: %d ",height(root));

    int n;
    cout << "Enter number of nodes in the tree: ";
    cin >> n;
    int pre[n];
    int in[n];
    cout << "Enter the preOrder: \n";
    for(int i = 0;i<n;i++){
        cin >> pre[i];
    }
    cout << "Enter the inOrder: \n";
    for(int i = 0;i<n;i++){
        cin >> in[i];
    }
    int ctr = 0;
    Node* root = preInTree(pre,in,0,n,&ctr);
    postOrder(root);
    cout << endl;
    cout << "Enter number of nodes in the tree: ";
    cin >> n;
    int POST[n];
    int IN[n];
    cout << "Enter the postOrder: \n";
    for(int i = 0;i<n;i++){
        cin >> POST[i];
    }
    cout << "Enter the inOrder: \n";
    for(int i = 0;i<n;i++){
        cin >> IN[i];
    }
    ctr = n-1;
    Node* ROOT = postInTree(POST,IN,0,n,&ctr);
    preOrder(ROOT);
    cout << endl;

}
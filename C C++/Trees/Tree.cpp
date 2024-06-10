#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int key){
        val=key;
        left=right=NULL;
    }
};


void preorder(Node* root){
    if(root!=NULL){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

Node* insert(Node* root, int key){
    if(root==NULL)
        return new Node(key);
    else if(root->val<key)
        root->right=insert(root->right,key);
    else
        root->left=insert(root->left,key);
    return root;
}





int height(Node* root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

int main(){
    // Node* r=new Node(1);
    // Node* r1=new Node(2);
    // Node* r2=new Node(3);
    // Node* r3=new Node(4);
    // Node* r4=new Node(5);
    // r->left=r1;
    // r->right=r2;
    // r->left->left=r3;
    // r->right->right=r4;
    
    int n,m; cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>m;
        root=insert(root,m);
    }

    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"postorder : ";
    postorder(root);
    cout<<endl;
    cout<<"inorder : ";
    inorder(root);
    cout<<endl;
    cout<<"Height : "<<height(root)<<endl;
}
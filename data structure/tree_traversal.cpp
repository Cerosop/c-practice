#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left_child = NULL, *right_child = NULL;
};

void preorder(node *root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void inorder(node *root){
    if(root){
        inorder(root->left_child);
        cout<<root->data<<" ";
        inorder(root->right_child);
    }
}

void postorder(node *root){
    if(root){
        postorder(root->left_child);
        postorder(root->right_child);
        cout<<root->data<<" ";
    }
}

int main(){
    int n, m, a;
    queue<node*> next_node;
    cin>>n;
    while(n--){
        cin>>m>>a;
        node *root = new node;
        next_node.push(root);
        m--;
        root->data = a;
        while(m--){
            cin>>a;
            if(!next_node.front()->left_child){
                node *new_node = new node;
                new_node->data = a;
                next_node.front()->left_child = new_node;
                next_node.push(new_node);
            }
            else if(!next_node.front()->right_child){
                node *new_node = new node;
                new_node->data = a;
                next_node.front()->right_child = new_node;
                next_node.push(new_node);
            }
            else{
                next_node.pop();
                node *new_node = new node;
                new_node->data = a;
                next_node.front()->left_child = new_node;
                next_node.push(new_node);
            }
        }
        while(!next_node.empty()){
            next_node.pop();
        }
        preorder(root);
        cout<<"\n";
        inorder(root);
        cout<<"\n";
        postorder(root);
        cout<<"\n";
    }
}
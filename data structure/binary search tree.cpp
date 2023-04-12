#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* Insert(Node* node, int data){
    if(node == NULL){
        node = new Node;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
    }
    else if(node->data < data){
        node->right = Insert(node->right, data);
        node->right->parent = node;
    }
    else{
        node->left = Insert(node->left, data);
        node->left->parent = node;
    }
    return node;
}

void PrintTreeInOrder(Node* node){
    if(node == NULL)
        return;
    cout << node->data << " ";
    PrintTreeInOrder(node->left);

    PrintTreeInOrder(node->right);
}

Node* Search(Node* node, int data){
    if (node == NULL)
        return NULL;
    else if(node->data == data)
        return node;
    else if(node->data < data)
        return Search(node->right, data);
    else
        return Search(node->left, data);
}

int FindMin(Node* node)
{
    if(node == NULL)
        return -1;
    else if(node->left == NULL)
        return node->data;
    else
        return FindMin(node->left);
}

int Successor(Node* node){
    if (node->right != NULL)
    {
        return FindMin(node->right);
    }
    return -1;
}
Node* Remove(Node* node,int data){
    if (node == NULL)
        return NULL;
    if (node->data == data){
        if (node->left == NULL && node->right == NULL)
            node = NULL;
        else if (node->left == NULL && node->right != NULL){
            node->right->parent = node->parent;
            node = node->right;
        }
        else if (node->left != NULL && node->right == NULL){
            node->left->parent = node->parent;
            node = node->left;
        }
        else{
            int successordata = Successor(node);
            node->data = successordata;
            node->right = Remove(node->right, successordata);
        }
    }
    else if (node->data < data)
        node->right = Remove(node->right, data);
    else
        node->left = Remove(node->left, data);
    return node;
}

int main(){
    Node* root = new Node;
    root = NULL;
    for (int i = 0; i < 10; i++){
        int n;
        cin>>n;
        root = Insert(root, n);
    }
    PrintTreeInOrder(root);
    cout<<"\n";
    int n;
    cin>>n;
    Remove(root, n);
    PrintTreeInOrder(root);
}

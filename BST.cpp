#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
};
Node *root = NULL;

void Insert(int data){
    if(root == NULL){
        root = new Node;
        root->data = data;
        return;
    }
    else{
        Node *node = root;
        while(1){
            if(node->data > data){
                if(node->left != NULL)
                    node = node->left;
                else{
                    Node *newnode = new Node;
                    newnode->data = data;
                    newnode->left = NULL;
                    newnode->right = NULL;
                    newnode->parent = node;
                    node->left = newnode;
                    break;
                }
            }
            else if(node->data < data){
                if(node->right != NULL)
                    node = node->right;
                else{
                    Node *newnode = new Node;
                    newnode->data = data;
                    newnode->left = NULL;
                    newnode->right = NULL;
                    newnode->parent = node;
                    node->right = newnode;
                    break;
                }
            }
            else{
                return;
            }
        }
    }
}

int count1 = 0;
void Search(Node* node, int i){
    if(root == NULL){
        cout<<"\n";
        return;
    }
    if(node == NULL)
        return;
    Search(node->left, i);
    if(count1 == i)
        return;
    count1++;
    if(count1 == i){
       cout<<node->data<<"\n";
       return;
    }
    Search(node->right, i);
}

void Delete(int data){
    if(root == NULL){
        cout<<"cannot delete\n";
    }
    else{
        Node *node = root;
        while(1){
            if(node->data > data){
                if(node->left != NULL)
                    node = node->left;
                else{
                    cout<<"cannot delete\n";
                    break;
                }
            }
            else if(node->data < data){
                if(node->right != NULL)
                    node = node->right;
                else{
                    cout<<"cannot delete\n";
                    break;
                }
            }
            else{
                if(node->left == NULL){
                    if(node->right == NULL){
                        if(node != root){
                            if(node->parent->left == node){
                                node->parent->left = NULL;
                            }
                            else if(node->parent->right == node){
                                node->parent->right = NULL;
                            }
                        }
                        else
                            root = NULL;
                    }
                    else{
                        if(node != root){
                            if(node->parent->left == node){
                                node->parent->left = node->right;
                                node->right->parent = node->parent;
                            }
                            else if(node->parent->right == node){
                                node->parent->right = node->right;
                                node->right->parent = node->parent;
                            }
                        }
                        else{
                            root = root->right;
                            root->parent = NULL;
                        }
                    }
                    
                }
                else if(node->right == NULL){
                    if(node != root){
                        if(node->parent->left == node){
                            node->parent->left = node->left;
                            node->left->parent = node->parent;
                        }
                        else if(node->parent->right == node){
                            node->parent->right = node->left;
                            node->left->parent = node->parent;
                        }
                    }
                    else{
                        root = root->left;
                        root->parent = NULL;
                    }
                }
                else{
                    Node *tmp = node->left;
                    while(tmp->right != NULL){
                        tmp = tmp->right;
                    }
                    if(tmp->parent != node){
                        tmp->parent->right = tmp->left;
                        if(tmp->left){
                            tmp->left->parent = tmp->parent;
                        }
                        
                        tmp->left = node->left;
                        node->left->parent = tmp;
                    }
                    tmp->parent = node->parent;
                    tmp->right = node->right;
                    node->right->parent = tmp;
                    if(node != root){
                        if(node->parent->left == node){
                            node->parent->left = tmp;
                        }
                        else if(node->parent->right == node){
                            node->parent->right = tmp;
                        }
                    }
                    else{
                        root = tmp;
                    }
                }
                break;
            }
        }
    }
}

int h = 1, record = 0;
void Height(Node* node){
    if(node == NULL)
        return;
    h++;

    Height(node->left);
    h--;
    if(record < h){
        record = h;
    }
    h++;
    Height(node->right);
    h--;
}//cout<<record;

void Traversal(){
    if(root == NULL){
        cout<<"\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
    cout<<"\n";
}

int main(){
    
    string s;
    int a;
    while(cin>>s){
        if(s == "insert"){
            cin>>a;
            Insert(a);
        }
        else if(s == "delete"){
            cin>>a;
            Delete(a);
        }
        else if(s == "search"){
            cin>>a;
            count1 = 0;
            Search(root, a);
        }
        else if(s == "height"){
            h = 1;
            record = 0;
            Height(root);
            cout<<record<<"\n";
        }
        else if(s == "traversal"){
            Traversal();
            break;
        }
    }
}
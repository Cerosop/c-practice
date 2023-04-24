//042501
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node *next = NULL;
};

void freelist(Node *first){
    if(first->next){
        freelist(first->next);
    }
    delete(first);
}

Node *insert(Node *first, int data){
    Node *second = first;
    while(second->next){
        if(second->next->value > data){
            Node *newnode = new Node;
            newnode->value = data;
            newnode->next = second->next;
            second->next = newnode;
            return first;
        }
        second = second->next;
    }
    Node *newnode = new Node;
    newnode->value = data;
    second->next = newnode;
    return first;
}

Node *createlist(int arr[], int n){
    Node *first = new Node;
    Node *second = first;
    for(int i = 0; i < n; i++){
        Node *newnode = new Node;
        newnode->value = arr[i];
        second->next = newnode;
        second = second->next;
    }
    return first;
}

void printlist(Node *first){
    first = first->next;
    while(first){
        cout<<first->value<<" ";
        first = first->next;
    }
    cout<<"\n";
}

int main(){
    Node *first;
    int arr[] = {14, 27, 32, 46};
    first = createlist(arr, 4);
    printlist(first);

    int data = 38;
    first = insert(first, data);
    printlist(first);
    freelist(first);
    system("pause");
    return 0;
}
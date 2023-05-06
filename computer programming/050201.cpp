//050201
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node *next;
};
typedef struct node Node;

node *front, *rear;
const int n = 8;

void createQ(){
    front = rear = (Node *)malloc(sizeof(Node)); 
    for(int i = 0; i < n; i++){
        node *tmp = (Node *)malloc(sizeof(Node));
        rear->next = tmp;
        rear = rear->next;
    }
    rear->next = front;
    rear = front;
}

void printlist(){
    if(front == rear)
        cout<<"no element in the queue\n";
    else{
        node *tmp = front;
        while(tmp != rear){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
}

void addQ(char c){
    if(rear->next == front)
        cout<<"the queue is full\n";
    else{
        rear->data = c;
        rear = rear->next;
    }
}

void deleteQ(){
    if(front == rear)
        cout<<"no element to delete\n";
    else
        front = front->next;
}

int main(){
    createQ();
    addQ('A');
    addQ('B');
    addQ('C');
    printlist();
    deleteQ();
    addQ('D');
    deleteQ();
    printlist();
    addQ('E');
    addQ('F');
    addQ('G');
    addQ('H');
    addQ('I');
    printlist();
    deleteQ();
    deleteQ();
    deleteQ();
    deleteQ();
    deleteQ();
    deleteQ();
    deleteQ();
    printlist();
    return 0;
}
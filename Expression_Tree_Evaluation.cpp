/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-07 19:22:18
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-07 23:19:07
 * @FilePath: \c++\Expression_Tree_Evaluation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *left_child = NULL, *right_child = NULL;
};

void postorder(node *root, queue<char> *post){
    if(root){
        postorder(root->left_child, post);
        postorder(root->right_child, post);
        if(root->data != ' ')
            post->push(root->data);
        // cout<<root->data<<" ";
    }
}

int main(){
    int n;
    long long ans, tmp; 
    cin>>n;
    queue<node*> next_node;
    node *root = new node;
    next_node.push(root);
    string a;
    cin>>a;
    if(a == "-1"){
        cout<<"0\n";
        return 0;
    }
    root->data = a[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < pow(2, i); j++){
            cin>>a;
            if(a == "-1"){
                a = " ";
            }
            if(!next_node.front()->left_child){
                node *new_node = new node;
                new_node->data = a[0];
                next_node.front()->left_child = new_node;
                next_node.push(new_node);
            }
            else if(!next_node.front()->right_child){
                node *new_node = new node;
                new_node->data = a[0];
                next_node.front()->right_child = new_node;
                next_node.push(new_node);
            }
            else{
                next_node.pop();
                node *new_node = new node;
                new_node->data = a[0];
                next_node.front()->left_child = new_node;
                next_node.push(new_node);
            }
        }
    }
    while(!next_node.empty()){
        next_node.pop();
    }
    queue<char> post;
    postorder(root, &post);
    stack<long long> numbers;
    while(!post.empty()){
        if(post.front() <= '9' && post.front() >= '0'){
            numbers.push(post.front() - '0');
            
        }
        else{
            tmp = numbers.top();
            numbers.pop();
            if(post.front() == '+'){
                ans = numbers.top();
                ans += tmp;
            }
            else if(post.front() == '-'){
                ans = numbers.top();
                ans -= tmp;
            }
            else if(post.front() == '*'){
                ans = numbers.top();
                ans *= tmp;
            }
            else if(post.front() == '/'){
                ans = numbers.top();
                ans /= tmp;
            }
            numbers.pop();
            numbers.push(ans);
        }
        post.pop();
    }
    ans = numbers.top();
    cout<<ans<<"\n";
}
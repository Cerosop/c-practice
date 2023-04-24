#include<bits/stdc++.h>
using namespace std;

string s, ans;
int ans2;

struct node{
    int v = 0;
    string s;
    vector<node *> next;
    node() : next(26, nullptr){}
};

void insert(node *root, int j){
    if(j < s.size()){
        if(!root->next[s[j] - 'a']){
            node *newnode = new node;
            root->next[s[j] - 'a'] = newnode;
        }
        insert(root->next[s[j] - 'a'], j + 1);
    }
    else{
        root->v++;
        root->s = s;
    }
}

void after(node *root){
    for(int i = 0; i < 26; i++){
        if(root->next[i]){
            after(root->next[i]);
            if(root->v < root->next[i]->v){
                root->v = root->next[i]->v;
                root->s = root->next[i]->s;
            }
        }
    }
}

void find(node *root, int j){
    if(j < s.size()){
        if(!root->next[s[j] - 'a']){
            ans = "";
            ans2 = -1;
        }
        else
            find(root->next[s[j] - 'a'], j + 1);
    }
    else{
        ans = root->s;
        ans += ' ';
        ans2 = root->v;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    node *root = new node;
    int n, q;
    cin>>n;
    while(n--){
        cin>>s;
        insert(root, 0);
    }
    after(root);
    cin>>q;
    while(q--){
        cin>>s;
        find(root, 0);
        cout<<ans<<ans2<<"\n";
    }
}
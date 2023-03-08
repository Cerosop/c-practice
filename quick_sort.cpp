#include<bits/stdc++.h>
using namespace std;
struct lis{
    int score;
    string name;
};

lis liss[1000001];
int n, k = 1;

bool equal(lis a, lis b){
    if(a.score - b.score)
        return false;
    if(a.name == b.name)
        return true;
    return false;
}

bool cmp(lis a, lis b){
    if(a.score - b.score)
        return a.score > b.score;
    for(int i = 0; i < min(a.name.size(), b.name.size()); i++){
        if(a.name[i] - b.name[i])
            return a.name[i] < b.name[i];
    }
    if(a.name.size() - b.name.size())
        return a.name.size() > b.name.size();
}

void quick_sort(int l, int r){
    int i = l, j = r + 1;
    if(l < r){
        lis pivot = liss[l];
        do{
            do
                i++;
            while(i <= r && !equal(liss[i], pivot) && !cmp(liss[i], pivot));
            do
                j--;
            while(j > l && !equal(liss[j], pivot) && cmp(liss[j], pivot));
            if(i < j)
                swap(liss[i], liss[j]);
        }while(i < j);
        swap(liss[l], liss[j]);
        cout<<"The index of the "<<k++<<"-th pivot is "<<j<<".\n";
        quick_sort(l, j - 1);
        quick_sort(j + 1, r);
    }
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>liss[i].name>>liss[i].score;
    quick_sort(0, n - 1);
    for(int i = 0; i < n; i++)
        cout<<liss[i].name<<" "<<liss[i].score<<"\n";
}
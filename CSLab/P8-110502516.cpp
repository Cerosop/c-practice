/*
* Practice 8
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string name, id;
    float eng, math, chi;
    int eng1, math1, chi1;
    cout<<"Please input your name : ";
    cin>>name;
    cout<<"Please input your stuent ID : ";
    cin>>id;
    cout<<"English score : ";
    cin>>eng;
    cout<<"Math score : ";
    cin>>math;
    cout<<"Chinese score : ";
    cin>>chi;
    cout<<"English weight : ";
    cin>>eng1;
    cout<<"Math weight : ";
    cin>>math1;
    cout<<"Chinese weight : ";
    cin>>chi1;
    cout<<"\nStudent name : "<<name;
    cout<<"\nStudent ID : "<<id;
    int aa = (eng + math + chi) / 3, wa = (eng * eng1 + math * math1 + chi * chi1) / (eng1 + math1 + chi1);
    cout<<"\nArithmetic average : "<<aa;
    cout<<"\nWeighted average : "<<wa<<"\n";
}

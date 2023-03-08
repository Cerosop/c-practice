/*
* Assignment 12
* Name: 許尚軒
* Student Number: 110502516
* Course 2021-CE1003-A
*/
#include <iostream>
#include <ctime>
using namespace std;


void f(int , int , int *);
void f_2(int , int , int *);

int main()
{
    int loop_num = 30000;
    int a, b;
    cin >> a >> b;
    double start_time = clock(); // get clock before execute

    for(int i=0;i<loop_num;i++){
        //cout<<"i "<<i<<"\n";
        f_2(a, b, &b);
        for(int j=0;j<loop_num;j++){
            //cout<<"j "<<j<<"\n";
            f(a, b, &a);
        }
    }
    double end_time = clock(); // get clock after execute

    cout << a << endl;
    cout << b << endl;
    cout << end_time - start_time << endl; // get execute time

    return 0;
}


void f(int a, int b, int *a1){
    a = a % 7;
    b = b % 11;
    *a1 = a * a - 3 * b;
}

void f_2(int a, int b, int *a1){
    a = a % 13;
    b = b % 5;
    *a1 = b * b - 13 * a;
}

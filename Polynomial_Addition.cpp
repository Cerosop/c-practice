#include<bits/stdc++.h>
using namespace std;

struct point
{
    int coe, exp;
    point *next;
};

void push(point *tmp, int coe, int exp){
    point *newpoint = new point;
    newpoint->coe = coe;
    newpoint->exp = exp;
    newpoint->next = NULL;
    tmp->next = newpoint;
}

point pop(point *head){
    point pop = *head->next;
    head->next = head->next->next;
    return pop;
}

int main(){
    int n, exp, coe;
    point head1, head2, *tmp;
    head1.next = NULL;
    head2.next = NULL;
    cin>>n;
    tmp = &head1;
    while(n--){
        cin>>coe>>exp;
        push(tmp, coe, exp);
        tmp = tmp->next;
    }
    cin>>n;
    tmp = &head2;
    while(n--){
        cin>>coe>>exp;
        push(tmp, coe, exp);
        tmp = tmp->next;
    }
    while(head1.next || head2.next){
        if(!head1.next){
            point out = pop(&head2);
            if(out.coe== 0)
                continue;
            cout<<out.coe<<" "<<out.exp<<" ";
        }
        else if(!head2.next){
            point out = pop(&head1);
            if(out.coe== 0)
                continue;
            cout<<out.coe<<" "<<out.exp<<" ";
        }
        else{
            if(head1.next->exp > head2.next->exp){
                point out = pop(&head1);
                if(out.coe== 0)
                    continue;
                cout<<out.coe<<" "<<out.exp<<" ";
            }
            else if(head1.next->exp < head2.next->exp){
                point out = pop(&head2);
                if(out.coe== 0)
                    continue;
                cout<<out.coe<<" "<<out.exp<<" ";
            }
            else{
                point out1 = pop(&head1);
                point out2 = pop(&head2);
                if(out1.coe + out2.coe == 0)
                    continue;
                cout<<out1.coe + out2.coe<<" "<<out1.exp<<" ";
            }
        }
    }
}
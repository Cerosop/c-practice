#include<bits/stdc++.h>
using namespace std;
void insert(int binary_Search_Dynamic[], bool isNULL[], int num_array[], int si, int value){
    int first_pos = 1;
    while(first_pos < si && !isNULL[first_pos]){
        first_pos *= 2;
    }
    if(first_pos >= si){
        //cout<<"memory si out\n";
        return;
    }
    int plus_pos[(int)log2(first_pos)] = {};
    for(int i = first_pos; i < first_pos * 2; i++){
        int mi = value, mipos = -1, every_first = 1;
        for(int j = 0; j < (int)log2(first_pos); j++){
            if(plus_pos[j] >= pow(2, j)){
                every_first *= 2;
                continue;
            }
            if(isNULL[every_first + plus_pos[j]]){
                plus_pos[j]++;
                j--;
                continue;
            }
            if(mi > binary_Search_Dynamic[every_first + plus_pos[j]]){
                mi = binary_Search_Dynamic[every_first + plus_pos[j]];
                mipos = every_first + plus_pos[j];
            }
            every_first *= 2;
        }
        if(mi != INT_MAX){
            num_array[(int) log2(first_pos)]++;
            binary_Search_Dynamic[i] = mi;
            isNULL[i] = false;
            if(mipos == -1){
                value = INT_MAX;
                continue;
            }
            isNULL[mipos] = true;
            plus_pos[(int)log2(mipos)]++;
            num_array[(int)log2(mipos)]--;
        }
        
    }
}

int search(int binary_Search_Dynamic[], bool isNULL[], int si, int value){
    int first_pos = 1;
    while(first_pos < si){
        while(first_pos < si && (isNULL[first_pos] || binary_Search_Dynamic[first_pos] > value)){
            first_pos *= 2;
        }
        if(first_pos >= si){
            break;
        }
        int l = first_pos, r = first_pos * 2 - 1;
        int middle = (l + r) / 2;
        while(isNULL[middle]){
            middle++;
        }
        while(binary_Search_Dynamic[middle] != value){
            if(l >= r){
                break;
            }
            if(binary_Search_Dynamic[middle] > value){
                if(middle > (l + r) / 2)
                    middle = (l + r) / 2;
                r = middle - 1;
                middle = (l + r) / 2;
                while(isNULL[middle] && middle < r){
                    middle++;
                }
                if (middle == r){
                    middle = (l + r) / 2;
                    while(isNULL[middle] && middle > l){
                        middle--;
                    }
                    if(middle == l){
                        break;
                    }
                }
            }
            else{
                if(middle < (l + r) / 2)
                    middle = (l + r) / 2;
                l = middle + 1;
                middle = (l + r) / 2;
                while(isNULL[middle] && middle < r){
                    middle++;
                }
                if (middle == r){
                    middle = (l + r) / 2;
                    while(isNULL[middle] && middle > l){
                        middle--;
                    }
                    if(middle == l){
                        break;
                    }
                }
            }
        }
        if(binary_Search_Dynamic[middle] == value){
            return middle;
        }
        first_pos *= 2;
    }
    return -1;
}

void Delete(int binary_Search_Dynamic[], bool isNULL[], int num_array[], int si, int value){
    int pos = search(binary_Search_Dynamic, isNULL, si, value);
    //cout<<pos<<"p\n";
    if(pos != -1){
        isNULL[pos] = true;
        num_array[(int)log2(pos)]--;
        if((int)log2(pos) > 0){
            //cout<<num_array[(int)log2(pos)]<<" "<<num_array[(int)log2(pos) - 1]<<" "<<(int)log2(pos)<<"\n";

            if(num_array[(int)log2(pos)] + num_array[(int)log2(pos) - 1] <= pow(2, (int)log2(pos)) && num_array[(int)log2(pos) - 1] > 0){
                int tmp[num_array[(int)log2(pos) - 1] + num_array[(int)log2(pos)]], posh = pow(2, (int)log2(pos)), posl = pow(2, (int)log2(pos) - 1);
                for(int i = 0; i < num_array[(int)log2(pos) - 1] + num_array[(int)log2(pos)]; i++){
                    while(isNULL[posh]){
                        posh++;
                    }
                    while(isNULL[posl]){
                        posl++;
                    }
                    if(posh >= pow(2, (int)log2(pos) + 1)){
                        tmp[i] = binary_Search_Dynamic[posl];
                        isNULL[posl] = true;
                    }
                    else if(posl >= pow(2, (int)log2(pos))){
                        tmp[i] = binary_Search_Dynamic[posh];
                        isNULL[posh] = true;
                    }
                    else{
                        if(binary_Search_Dynamic[posh] > binary_Search_Dynamic[posl]){
                            tmp[i] = binary_Search_Dynamic[posl];
                            isNULL[posl] = true;
                        }
                        else{
                            tmp[i] = binary_Search_Dynamic[posh];
                            isNULL[posh] = true;
                        }
                    }
                }
                for(int i = 0; i < num_array[(int)log2(pos) - 1] + num_array[(int)log2(pos)]; i++){
                    binary_Search_Dynamic[(int)pow(2, (int)log2(pos)) + i] = tmp[i];
                    isNULL[(int)pow(2, (int)log2(pos)) + i] = false;
                }
                num_array[(int)log2(pos)] += num_array[(int)log2(pos) - 1];
                num_array[(int)log2(pos) - 1] = 0;
            }
            else if(num_array[(int)log2(pos)] <= pow(2, (int)log2(pos) - 1) && num_array[(int)log2(pos) - 1] == 0){
                int j = pow(2, (int)log2(pos));
                for(int i = pow(2, (int)log2(pos) - 1); i < pow(2, (int)log2(pos)); i++){
                    for(;j < pow(2, (int)log2(pos) + 1); j++){
                        if(isNULL[j]){
                            continue;
                        } 
                        binary_Search_Dynamic[i] = binary_Search_Dynamic[j];
                        isNULL[i] = false;
                        isNULL[j] = true;
                        break;
                    }
                    j++;
                }
                num_array[(int)log2(pos) - 1] = num_array[(int)log2(pos)];
                num_array[(int)log2(pos)] = 0;
            }
        }
        //cout<<num_array[(int)log2(pos)]<<" "<<(int)log2(pos)<<" "<<isNULL[(int)pow(2, (int)log2(pos))]<<" "<<(int)pow(2, (int)log2(pos))<<"\n";
        if(num_array[(int)log2(pos)] > 0 && isNULL[(int)pow(2, (int)log2(pos))]){
            int posn = pow(2, (int)log2(pos)) + 1;
            while(isNULL[posn]){
                posn++;
            }
            binary_Search_Dynamic[(int)pow(2, (int)log2(pos))] = binary_Search_Dynamic[posn];
            isNULL[posn] = true;
            isNULL[(int)pow(2, (int)log2(pos))] = false;
            //cout<<"ff\n";
        }
        //cout<<"Delete Success\n";
    }
    else{
        //cout<<"Delete Failed\n";
    }
}
int n = 5000005;
int si = pow(2, (int)log2(n) + 1);
int binary_Search_Dynamic[(int)pow(2, (int)log2(5000000) + 1)], num_array[(int)log2(5000000) + 1] = {};
bool isNULL[(int)pow(2, (int)log2(5000000) + 1)];
int rdarr[5000000];
int main(){
    
    
    for(int i = 0; i < 5000000; i++){
        rdarr[i] = i;
    }
    double START = clock();
    for(int i = 0; i < 5000000; i++){
        int rdindex = rand() % (5000000 - i);
        int a = rdarr[rdindex];
        swap(rdarr[rdindex], rdarr[4999999 - i]);
        insert(binary_Search_Dynamic, isNULL, num_array, si, a);
    }
    cout<<"\n"<<"insert所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";

    for(int i = 0; i < 5000000; i++){
        rdarr[i] = i;
    }
    START = clock();
    for(int i = 0; i < 5000000; i++){
        int rdindex = rand() % (5000000 - i);
        int a = rdarr[rdindex];
        swap(rdarr[rdindex], rdarr[4999999 - i]);
        int x = search(binary_Search_Dynamic, isNULL, si, a);
    }
    cout<<"\n"<<"search所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";

    for(int i = 0; i < 5000000; i++){
        rdarr[i] = i;
    }
    START = clock();
    for(int i = 0; i < 5000000; i++){
        int rdindex = rand() % (5000000 - i);
        int a = rdarr[rdindex];
        swap(rdarr[rdindex], rdarr[4999999 - i]);
        Delete(binary_Search_Dynamic, isNULL, num_array, si, a);
    }
    cout<<"\n"<<"delete所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
    // double a = 0;
    // for(int i = 1; i <= 5000000; i++){
    //     a += log2(i) * log2(i);
    // }
    // cout<<a / (1000000000 / 0.679)<<" \n";
    // a = 0;
    // for(int i = 1; i <= 5000000; i++){
    //     a += log2(i);
    // }
    // cout<<a / (1000000000 / 0.679);
    // START = clock();
    // long long int a4 = 1;
    // for(long long int i = 0; i < 50000000000; i++){
    //     if(a4%2){
    //         a4+=2;
    //     }
    // }
    // cout<<a4<<" ";
    // cout<<"\n"<<"所花費: "<<(double)(clock() - START) / CLOCKS_PER_SEC<<" s\n";
}
#include<bits/stdc++.h>
using namespace std;
void insert(int binary_Search_Dynamic[], bool isNULL[], int num_array[], int size, int value){
    int first_pos = 1;
    while(first_pos < size && !isNULL[first_pos]){
        first_pos *= 2;
    }
    if(first_pos >= size){
        //cout<<"memory size out\n";
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

int search(int binary_Search_Dynamic[], bool isNULL[], int size, int value){
    int first_pos = 1;
    while(first_pos < size){
        while(first_pos < size && (isNULL[first_pos] || binary_Search_Dynamic[first_pos] > value)){
            first_pos *= 2;
        }
        if(first_pos >= size){
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

void Delete(int binary_Search_Dynamic[], bool isNULL[], int num_array[], int size, int value){
    int pos = search(binary_Search_Dynamic, isNULL, size, value);
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
        cout<<"Delete Success\n";
    }
    else{
        cout<<"Delete Failed\n";
    }
}

int main(){
    int n, m;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cin>>m;
    int size = pow(2, (int)log2(n + m) + 1);
    int binary_Search_Dynamic[size], num_array[(int)log2(size)] = {};
    bool isNULL[size];
    for(int i = 0; i < size; i++){
        isNULL[i] = true;
    }
    for(int i = 0; i < n; i++){
        int a = arr[i];
        insert(binary_Search_Dynamic, isNULL, num_array, size, a);
        //cout<<"Insert Success\n";
        // for(int i = 1; i < size; i++){
        //     cout<<binary_Search_Dynamic[i]<<" ";
        // }
        // cout<<"\n";
    }
    
    while(m--){
        char c;
        int a;
        cin>>c>>a;
        switch (c){
        case 's':
            if(search(binary_Search_Dynamic, isNULL, size, a) != -1){
                cout<<"Found\n";
            }
            else{
                cout<<"Not Found\n";
            }
            break;
        case 'i':
            if(search(binary_Search_Dynamic, isNULL, size, a) != -1){
                cout<<"Insert Failed\n";
            }
            else{
                insert(binary_Search_Dynamic, isNULL, num_array, size, a);
                cout<<"Insert Success\n";
                // for(int i = 1; i < size; i++){
                //     cout<<isNULL[i]<<"||"<<binary_Search_Dynamic[i]<<" ";
                // }
                // cout<<"\n";
            }
            break;
        case 'd':
            Delete(binary_Search_Dynamic, isNULL, num_array, size, a);
            // for(int i = 1; i < size; i++){
            //     cout<<isNULL[i]<<"||"<<binary_Search_Dynamic[i]<<" ";
            // }
            // cout<<"\n";
            break;
        default:
            break;
        }
    }
}
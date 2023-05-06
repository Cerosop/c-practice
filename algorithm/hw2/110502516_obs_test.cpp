#include<bits/stdc++.h>
using namespace std;

// struct hash_pair{
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const{
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         if (hash1 != hash2) 
//             return hash1 ^ hash2;   
//         return hash1;
//     }
// };

struct obs{
    int a, b, v;
};

bool cmp(obs a, obs b){
    if(a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

vector<obs> v;
short p[2001][2001], have_solved[2001][2001];
bool obsb[2001][2001][2];
short anss[2001][2001];
vector<pair<int, int>> r;
// map<int, int> have_solved;

int solve(int h, int w){
    if(v.size()){
        if(have_solved[h][w] != -1)
            return have_solved[h][w];
        obs tmp = v[v.size() - 1];
        v.pop_back();
        int ans = solve(h, w);
        if(h - tmp.a >= 0 && w - tmp.b >= 0)
            ans += (p[tmp.a + tmp.v - 1][tmp.b - tmp.v] - solve(tmp.a + tmp.v - 1, tmp.b - tmp.v)) * p[h - tmp.a][w - tmp.b];
        v.push_back(tmp);

        ans %= 2552;
        if(ans < 0)
            ans += 2552;
        
        if(have_solved[h][w] == -1){
            // cout<<"a ";
            r.push_back(make_pair(h, w));
        }
        have_solved[h][w] = ans;

        // if(!have_solved.count(h * 3000 + w))
        //     have_solved.insert(pair<int, int>(h * 3000 + w, ans));
        // else
        //     have_solved[h * 3000 + w] = ans;
        return ans;
    }
    return 0;
}

int main(){
    freopen("testw.txt", "w", stdout);

    int h, w, k = 1000, q, a, b, c, d, ans;
    long long int t1, t2;
    vector<int> input;
    for(h = 100, w = h; h <= 2000; h++, w++){
        p[0][0] = 1;
        for(int i = 1; i <= h; i++)
            p[i][0] = p[i - 1][0];
        for(int i = 1; i <= w; i++)
            p[0][i] = p[0][i - 1];
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                p[i][j] += p[i][j - 1];
                p[i][j] += p[i - 1][j];
                while(p[i][j] >= 2552)
                    p[i][j] -= 2552;
            }
        }

        
        memset(have_solved, -1, sizeof(have_solved));
        t1 = 0, t2 = 0;
        for(int k1 = 0; k1 < k; k1++){
            q = k1 / 10 + 1;
            input.clear();
            for(int u = 0; u < q; u++){
                c = rand() % 2;
                if(c){
                    a = rand() % h;
                    b = rand() % h + 1;
                    input.push_back(a);
                    input.push_back(b);
                    input.push_back(a + 1);
                    input.push_back(b);
                }
                else{
                    a = rand() % h + 1;
                    b = rand() % h;
                    input.push_back(a);
                    input.push_back(b);
                    input.push_back(a);
                    input.push_back(b + 1);
                }
            }

            auto start = chrono::high_resolution_clock::now();
            v.clear();
            for(auto x: r)
                have_solved[x.first][x.second] = -1;
            r.clear();
            for(int q1 = 0; q1 < q; q1++){
                a = input[q1 * 4];
                b = input[q1 * 4 + 1];
                c = input[q1 * 4 + 2];
                d = input[q1 * 4 + 3];
                if(a < c){
                    obs *newobs = new obs;
                    newobs->a = c;
                    newobs->b = d;
                    newobs->v = 0;
                    v.push_back(*newobs);
                    free(newobs);
                }
                if(b < d){
                    obs *newobs = new obs;
                    newobs->a = c;
                    newobs->b = d;
                    newobs->v = 1;
                    v.push_back(*newobs);
                    free(newobs);
                }
            }
            sort(v.begin(), v.end(), cmp);
            
            ans = p[h][w] - solve(h, w);
            if(ans < 0)
                ans += 2552;
            // cout<<ans<<"\n";
            auto finish1 = chrono::high_resolution_clock::now();
            t1 += chrono::duration_cast<chrono::nanoseconds>(finish1 - start).count();
            if(!(k1 % 10)){
                cout<<h<<" "<<q<<" "<<t1 / 10<<" ";
                t1 = 0;
            }
                

            start = chrono::high_resolution_clock::now();
            memset(obsb, 0, ((h + 1) * (w + 1))<<1);
            memset(anss, 0, ((h + 1) * (w + 1))<<1);
            for(int q1 = 0; q1 < q; q1++){
                a = input[q1 * 4];
                b = input[q1 * 4 + 1];
                c = input[q1 * 4 + 2];
                d = input[q1 * 4 + 3];
                if(a < c)
                    obsb[c][d][0] = true;
                if(b < d)
                    obsb[c][d][1] = true;
            }
            anss[0][0] = 1;
            for(int i = 1; i <= h; i++){
                if(!obsb[i][0][1])
                    anss[i][0] = anss[i - 1][0];
            }
            for(int i = 1; i <= w; i++){
                if(!obsb[0][i][0])
                    anss[0][i] = anss[0][i - 1];
            }
            for(int i = 1; i <= h; i++){
                for(int j = 1; j <= w; j++){
                    if(!obsb[i][j][1])
                        anss[i][j] += anss[i][j - 1];
                    if(!obsb[i][j][0])
                        anss[i][j] += anss[i - 1][j];
                    while(anss[i][j] >= 2552){
                        anss[i][j] -= 2552;
                    }
                }
            }
            // cout<<anss[h][w]<<"\n";
            finish1 = chrono::high_resolution_clock::now();
            t2 += chrono::duration_cast<chrono::nanoseconds>(finish1 - start).count();
            if(!(k1 % 10)){
                cout<<t2 / 10<<"\n";
                t2 = 0;
            }
        }
    }
}
struct edge{
    int c1, c2, w;
};

int get_an(int a){ //算祖先
    if(an[a] == a)
        return a;
    an[a] = get_an(an[a]); 
    return an[a];
}

int main(){
    srand(time(NULL));
    vector<edge> v, ans_v;
    while(m--)
        edge *newedge = new edge;
        input>>newedge->c1>>newedge->c2>>newedge->w;
        v.push_back(*newedge);  //總道路

    int ans_min = INT_MAX;
    
    for(int k = 0; k < 10000; k++) //跑10000次
        for(i from 1 to n) //初始化祖先
            an[i] = i;
        vector<edge> tmp = v; //做計算的vector
        vector<edge> anstmp; //存這次答案的vector
        count = 0;
        while(1)
            if(count >= n - 2 || !tmp.size())
                break;
            x = rand() % tmp.size();    //隨機選一條路
            if(get_an(tmp[x].c1) == get_an(tmp[x].c2)) //自己走到自己
                swap(*(tmp.end() - 1), *(tmp.begin() + x)); //與最後一位交換再pop掉
                tmp.pop_back();
                continue;
            if((get_an(tmp[x].c1) == get_an(1) && get_an(2) == get_an(tmp[x].c2)) || 
               (get_an(tmp[x].c1) == get_an(2) && get_an(1) == get_an(tmp[x].c2))) //要融合的集合包刮1 2
                anstmp.push_back(tmp[x]);
                swap(*(tmp.end() - 1), *(tmp.begin() + x));
                tmp.pop_back();
                continue;
            an[an[tmp[x].c2]] = an[tmp[x].c1];  //c2的祖先的祖先改為c1的祖先
            count++;
            swap(*(tmp.end() - 1), *(tmp.begin() + x));
            tmp.pop_back();

        for(i from 0 to tmp.size() - 1)
            if(get_an(tmp[i].c1) != get_an(tmp[i].c2)) //道路左右在不同集合
                anstmp.push_back(tmp[i]);

        ans = 0;
        for(i from 0 to anstmp.size() - 1)
            ans += anstmp[i].w;

        if(ans_min > ans)
            ans_min = ans;
            ans_v = anstmp;

    for(int i = 0; i < ans_v.size(); i++)
        cout<<ans_v[i].c1<<" "<<ans_v[i].c2<<"\n";
}
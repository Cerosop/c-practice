#include <bits/stdc++.h>
#define ll long long
#define cl(x) (2*x + 1)
#define cr(x) (2*(x + 1))
#define int long long

using namespace std;

struct seg {

	vector<pair<int, ll>> v;
	vector<pair<int, ll>> lazy;

	seg(int _n): v(vector<pair<int, ll>>(_n << 2, make_pair(0, 0))), lazy(vector<pair<int, ll>>(_n << 2, make_pair(0, 0))) {}

	void pull(int i, int l, int r) {
		if (l == r) return;
		int mid = (l + r) / 2;
		push(cl(i), l, mid);
		push(cr(i), mid + 1, r);
		if(v[cl(i)].second >= v[cr(i)].second){
			v[i] = v[cl(i)];
		}
		else{
			v[i] = v[cr(i)];
		}
	}

	void push(int i, int l, int r) {
		if (lazy[i].second) {
			if(v[i].second < lazy[i].second || (v[i].second == lazy[i].second && v[i].first > lazy[i].first)){
				v[i] = lazy[i];
			}
			if (l != r) {
				if(lazy[cl(i)].second < lazy[i].second || (lazy[cl(i)].second == lazy[i].second && lazy[cl(i)].first > lazy[i].first)){
					lazy[cl(i)] = lazy[i];
				}
				if(lazy[cr(i)].second < lazy[i].second || (lazy[cr(i)].second == lazy[i].second && lazy[cr(i)].first > lazy[i].first)){
					lazy[cr(i)] = lazy[i];
				}
			}
			lazy[i].second = 0;
		}
	}

	void build(vector<ll>& arr, int i, int l, int r) {
		if (l == r)
			v[i] = make_pair(l, arr[l]);
		else {
			int mid = (l + r) / 2;
			build(arr, cl(i), l, mid);
			build(arr, cr(i), mid + 1, r);
			pull(i, l, r);
		}
	}

	void update(int i, int l, int r, int nl, int nr, int x) {
		push(i, l, r);

		if (l >= nl and r <= nr) {
			v[i].second = x;
			// if(lazy[i].second < x || (lazy[i].second == x && lazy[i].first > l)){
			// 	lazy[i].second = x;
			// 	lazy[i].first = l;
			// }
			return;
		}

		int mid = (l + r) / 2;
		if (nl <= mid)
			update(cl(i), l, mid, nl, nr, x);
		if (nr > mid)
			update(cr(i), mid + 1, r, nl, nr, x);
		pull(i, l, r);
	}

	pair<int,ll> query(int i, int l, int r, int nl, int nr) {
		push(i, l, r);
		if (l >= nl and r <= nr) return v[i];

		int mid = (l + r) / 2;

		pair<int ,ll> ret=make_pair(l,0);
		if (nl <= mid){
            pair<int,ll> q=query(cl(i), l, mid, nl, nr);
            if(ret.second<=q.second){
                if(ret.second!=q.second or ret.first>q.first) 
					ret=q;
            }
        }

		if (nr > mid){
            pair<int,ll> q=query(cr(i), mid + 1, r, nl, nr);
            if(ret.second<q.second){
                if(ret.second!=q.second or ret.first>q.first) 
					ret=q;
            }
        }
		return ret;
	}
};

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	seg segtree(n);
	segtree.build(arr, 0, 0, n - 1);

	for (int i = 0, a, b, c; i < q; i++) {
		cin >>  a >> b >> c;;
		if (a == 1) {
			segtree.update(0, 0, n - 1, b - 1, b - 1, c);
		}
		else {

			cout << segtree.query(0, 0, n - 1, b - 1, c - 1).first+1 << "\n";
		}
	}
    //for (int i = 0; i < n; i++) cout<< arr[i]<<" ";
	return 0;
}
/*
5 3
1 2 3 4 5
2 2 4
1 3 5
2 1 5
*/
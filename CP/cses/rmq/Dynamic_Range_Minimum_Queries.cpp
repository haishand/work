#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxx = 1e9+10;

ll mini(vector<ll> &BIT, int k) {
	ll res = BIT[k];
	while(k>0) {
		res = min(res, BIT[k]);
		k-=k&(-k);
	}
	return res;
}

void add(vector<ll> &BIT, vector<int> &x, int n, int k, int u) {
	u -= x[k];
	x[k] += u;
	while(k<=n) {
		BIT[k]+=u;
		k+=k&(-k);
	}
}
int main() {
	int n, q;
	cin >>n >> q;
	vector<ll> BIT(n+1, maxx);
	vector<int> x(n+1, maxx);
	for(int i=1; i<=n; i++) {
		int e;
		cin >> e;
		add(BIT, x, n, i, e);
	}
	/*
	for(int i=1; i<=n; i++) {
		printf("BIT[%d]=%lld\n", i, BIT[i]);
	}
	return 0;
	*/
	for(int i=0; i<q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		ll ans = 0;
		switch(t) {
			case 1:
				add(BIT, x, n, a, b);
				break;
			case 2:
				ans = min(mini(BIT, b), mini(BIT, a-1));
				cout << ans << endl;
				break;
		}
	}

	return 0;
}

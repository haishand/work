#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum(vector<ll> &BIT, int k) {
	ll res = 0;
	while(k>0) {
		res += BIT[k];
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
	vector<ll> BIT(n+1, 0);
	vector<int> x(n+1, 0);
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
				ans = sum(BIT, b)-sum(BIT, a-1);
				cout << ans << endl;
				break;
		}
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, q;
	cin >>n >> q;
	vector<int> a(n+1, 0);
	vector<ll> sum(n+1, 0);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sum[0] = 0;
	for(int i=1; i<=n; i++) {
		sum[i] = sum[i-1]+a[i];
	}

	for(int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		ll ans = sum[b]-sum[a-1];
		cout << ans << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1), t(n+1);
	vector<ll> sa(n+1, 0), st(n+1, 0);
	a[0] = 0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		sa[i] = sa[i-1] + a[i];
	}

	t[0] = 0;
	ll rest = 0;
	for(int i=1; i<=n; i++) {
		cin >> t[i];
		rest += (t[i]==1?a[i]:0);
		st[i] = st[i-1] + (t[i]==1?a[i]:0);
	}

	ll ans = 0;
	for(int i=1; i+k-1<=n; i++) {
		ans = max(ans, sa[i+k-1]-sa[i-1]-(st[i+k-1]-st[i-1]));
	}
	cout << ans+rest << endl;
	return 0;
}

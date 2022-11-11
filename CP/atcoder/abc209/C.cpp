#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+10;
const int MOD = 1e9+7;

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());

	ll ans = 1;
	for(int i=0; i<n; i++) {
		ans *= max(0, c[i]-i);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}

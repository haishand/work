#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;
const ll maxval = 2e5+10;
const ll inf = 1e18+8;

#define fi first
#define se second

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;

		vector<ll> x(n+1), p(n+1);
		x[0] = 0;
		for(int i=1; i<=n; i++) {
			cin >> x[i];
		}

		partial_sum(x.begin(), x.end(), p.begin());

		ll ans = inf;
		for(int i=0; i<=n; i++) {
			ans = min(ans, a*x[i] + b*(p[n]-p[i]-(n-i-1)*x[i]));
		}
		cout << ans << endl;

	}
	return 0;
}

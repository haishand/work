#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;
const ll maxval = 2e5+10;

#define fi first
#define se second

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;

		vector<ll> x(n+1);
		x[0] = 0;
		for(int i=1; i<=n; i++) {
			cin >> x[i];
		}

		ll ans = 0;
		int cap = 0;
		for(int i=1; i<=n; i++) {
			if(a*(x[i]-x[cap]) < b*(x[i]-x[cap])*(n-i)) {
				ans += b*(x[i]-x[cap])+a*(x[i]-x[cap]);
//				printf("conquer and change capital to kingdom %d with cost: %lld\n", i, b*(x[i]-x[cap])+a*(x[i]-x[cap]));
				cap = i;
			}else {
				ans += b*(x[i]-x[cap]);
//				printf("just conquer the kingdom %d with cost: %lld\n", i, b*(x[i]-x[cap]));
			}
		}
		cout << ans << endl;

	}
	return 0;
}

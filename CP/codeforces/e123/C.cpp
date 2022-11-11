#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int small = -1e9;
typedef pair<ll, int> pii;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		vector<ll> a(n+1);
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		vector<ll> sum(n+1);
		sum[0] = 0;
		for(int i=1; i<=n; i++) {
			sum[i] = sum[i-1]+a[i];
		}

		vector<ll> mx(n+1);
		mx[0] = 0;
		for(int k=1; k<=n; k++) {
			mx[k] = small;
			for(int i=0; i+k<=n; i++) {
				mx[k] = max(mx[k], sum[i+k]-sum[i]);
			}
		}
		for(int k=0; k<=n; k++) {
			ll ans = 0;
			for(int i=0; i<=n; i++) {
				ans = max(ans, mx[i]+min(i, k)*x);
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}

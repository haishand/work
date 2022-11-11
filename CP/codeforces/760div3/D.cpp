#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll ans = 0;
		for(int i=1; i<=n-2*k; i++) {
			ans += a[i];
		}
		for(int i=1; n-k+i<=n; i++) {
			ans += a[n-2*k+i]/a[n-k+i];
		}
		cout << ans << endl;
	}
	return 0;
}

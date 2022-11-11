#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e9;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		for(int i=0; i<n; i++) {
			ll t = a[i%n]+a[(i+1)%n]+a[(i+2)%n];
			ans = max(ans, t); 
		}
		cout << ans << endl;
	}
	return 0;
}

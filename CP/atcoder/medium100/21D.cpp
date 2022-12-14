#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		++mp[a[i]];
	}
	
	ll total = 0;
	for(auto &p : mp) {
		ll t = p.second;
		total += t*(t-1)/2;
	}
	for(int i=0; i<n; i++) {
		ll t = mp[a[i]];
//		printf("total=%lld, t=%d\n", total, t);
		ll ans = total - (t-1);
		cout << ans << endl;
	}
	return 0;
}

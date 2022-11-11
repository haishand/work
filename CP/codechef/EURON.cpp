#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	vector<int> b;
	b.push_back(a[0]);
	for(int i=1; i<n; i++) {
		auto it = upper_bound(b.begin(), b.end(), a[i]);
		ans += b.end()-it;
		b.insert(it, a[i]);
	}
	cout << ans << endl;
	return 0;
}


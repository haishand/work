#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		--a[i];
	}
	for(int i=0; i<n; i++) {
		cin >> b[i];
		--b[i];
	}
	for(int i=0; i<n; i++) {
		cin >> c[i];
		--c[i];
	}
	vector<int> count(n);
	for(int i=0; i<n; i++) {
		++count[b[c[i]]];
	}
	ll ans = 0;
	for(int i=0; i<n; i++) {
		if(count[a[i]]) {
			ans += count[a[i]];
		}
	}
	cout << ans << endl;
	return 0;
}

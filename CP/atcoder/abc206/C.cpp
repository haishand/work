#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll ans = (n*(n-1))/2;

	sort(a.begin(), a.end());
	a.push_back(-1);
	ll cnt = 1;
	for(int i=0; i<n; i++) {
		if(a[i] != a[i+1]) {
			ans -= (cnt*(cnt-1))/2;
			cnt = 1;
		}else {
			++cnt;
		}
	}
	cout << ans << endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n; ll k;
	cin >> n >> k;
	vector<pair<ll, ll>> a;
	for(int i=0; i<n; i++) {
		ll x, y;
		cin >> x >> y;
		a.push_back({x, y});
	}
	sort(a.begin(), a.end());
	for(int i=0; i<n; i++) {
		if(a[i].first>k) break;
		k+=a[i].second;
	}
	cout << k << endl;
	return 0;
}

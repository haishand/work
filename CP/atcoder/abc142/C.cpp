#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		mp[a[i]] = i+1;
	}
	sort(a.begin(), a.end());
	for(int i=0; i<n; i++) {
		cout << mp[a[i]] << " ";
	}
	return 0;
}

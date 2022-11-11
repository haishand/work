#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i=0; i<n; i++) {
		cin >> b[i];
	}

	vector<array<int, 2>> x; 
	for(int i=0; i<n; i++) {
		x.push_back({i-b[i], i});
	}
	sort(x.begin(), x.end());
	ll s = b[x[0][1]];
	ll ans = s;
	for(int i=1; i<x.size(); i++) {
		if(x[i][0] == x[i-1][0]) {
			s+=b[x[i][1]];
		}else {
			s=b[x[i][1]];
		}
		if(s>ans) {
			ans = s;
		}
	}
	cout << ans << endl;
	return 0;
}

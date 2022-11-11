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
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		int mi = a[0];
		int ans = 0;
		for(int i=1; i<n; i++) {
			if(mi>a[i]) {
				mi = a[i];
				ans = i;
			}
		}
		cout << ans+1 << endl;
	}
	return 0;
}

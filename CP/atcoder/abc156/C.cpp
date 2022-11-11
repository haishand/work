#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e6+10;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = maxn;
	for(int p=1; p<=100; p++) {
		int t = 0;
		for(int i=0; i<n; i++) {
			t += (a[i]-p)*(a[i]-p);
		}
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}

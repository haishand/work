#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<int> b(m);
	for(int i=0; i<m; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	
	int i = 0, j=0;
	int ans = maxn;
	while(i<n && j<m) {
		int t = abs(a[i]-b[j]);
		if(t<ans) {
			ans = t;
		}
		if(a[i]>b[j]) {
			++j;
		}else {
			++i;
		}
	}
	cout << ans << endl;
	return 0;
}

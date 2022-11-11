#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i=0; i<n; ++i) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int mid = n/2;
	int ans = d[mid]-d[mid-1];
	cout << ans << endl;
	return 0;
}

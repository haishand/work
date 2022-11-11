#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int ma = 0;
	for(int i=1; i<n; i++) {
		ma = max(ma, abs(a[i]-a[i-1]));
	}
	ma = max(ma, abs(k-a[n-1]+a[0]));
	cout << k-ma << endl;
	return 0;
}

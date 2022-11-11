#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int gcd(int a, int b) {
	if(a==0) {
		return b;
	}
	return gcd(b%a, a);
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int ans = abs(a[0] - x);
	for(int i=0; i<n-1; i++) {
		ans = min(ans, gcd(abs(a[i]-x), abs(a[i+1]-a[i])));
	}
	cout << ans << endl;
	return 0;
}

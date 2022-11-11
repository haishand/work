#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
	}
	int t = k;
	int ans = 1;
	while(t<n) {
		t+=k-1;
		++ans;	
	}
	cout << ans << endl;
	return 0;
}

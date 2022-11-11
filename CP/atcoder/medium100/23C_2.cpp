#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 3;
const int M = 5;

int can(vector<int> &a, int n) {
	int res = 1;
	if(a[0] == 0 && n>1) {
		res = 0;	
	}else {
		for(int i=1; i<n; i++) {
			if(a[i] == -1) {
				res = 0;
				break;
			}
		}
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> ans(N, -1);
	for(int i=0; i<m; i++) {
		int s, c;
		cin >> s >> c;
		if(ans[s-1] != -1 && ans[s-1] != c) {
			cout << -1 << endl;
			exit(0);
		}
		ans[s-1] = c;
	}

	if(ans[0] == -1 && n>1) {
		ans[0] = 1;
	}
	if(ans[0] == -1 && n==1) {
		ans[0] = 0;
	}
	for(int i=1; i<n; i++) {
		if(ans[i] == -1) {
			ans[i] = 0;
		}
	}
	if(can(ans, n)) {
		for(int i=0; i<n; i++) {
			cout << ans[i];
		}
	}else {
		cout << -1 ;
	}
	cout << endl;
	return 0;
}
	

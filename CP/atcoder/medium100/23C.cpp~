#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int M = 5;

int n, m;
vector<int> ans(M, -1);
vector<int> digit(M, -1);

void dfs(int k) {
	if(k > m) {
		if(ans[0] != -1) {
			for(int i=0; i<m; i++) {
				cout << ans[i];
			}
		}else {
			cout << -1 << endl;
		}
		exit(0);
	}
	if(digit[k] != -1) {
		ans[k] = digit[k];
		dfs(k+1);
	}else {
		if(k==0) {
			ans[k] = 1;
		}else {
			ans[k] = 0;
		}
		dfs(k+1);
	}
}
int main() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int s, c;
		cin >> s >> c;	
		if(s-1==0 && c==0) {
			cout << -1 << endl;
			exit(0);
		}
		if(digit[s-1] != -1 && digit[s-1] != c) {
			cout << -1 << endl;
			exit(0);
		}
		digit[s-1] = c;
	}

	dfs(0);
	return 0;
}
	

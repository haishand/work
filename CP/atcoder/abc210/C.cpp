#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5+10;

const int MAXC = 1e9+10;
int c[N];
map<int, int> mp;

int main() {
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	for(int i=1; i<=k; i++) {
		++mp[c[i]];
	}

	int ans = mp.size();
	for(int j=k+1; j<=n; j++) {
		mp[c[j]]++;
		mp[c[j-k]]--;
		if(mp[c[j-k]] == 0) {
			mp.erase(c[j-k]);
		}
		if(mp.size() > ans) {
			ans = mp.size();
		}
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN =  2e5+10;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(MAXN);
	vector<int> cnt(MAXN, 0);
	for(int i=0; i<N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int diff = 0;
	for(int i=0; i<=MAXN; i++) {
		if(cnt[i] == 0) {
			cnt[i] = MAXN;
		}else {
			++diff;
		}
	}
	sort(cnt.begin(), cnt.end());
	int ans = 0;
	if(diff - K > N) {
		cout << 0 << endl;
	}else {
		int i = 0;
		while(diff > K) {
			ans += cnt[i];
			--diff;
			++i;
		}
		cout << ans << endl;
	}
	return 0;
}

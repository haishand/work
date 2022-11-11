#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >>n >> x;
		vector<int> a(n+1);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		int ans = 0;
		int cnt = 1;
		int mi = a[0];
		for(int i=0; i<n; i++) {
			mi = min(mi, a[i]);
			if(mi*cnt >= x) {
				++ans;
				cnt = 1;
				mi = a[0];
			}else {
				++cnt;
			}
//			printf("mi=%d, cnt=%d, ans=%d\n",mi, cnt, ans);
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N+1);
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin()+N);
	a[N] = 0;	//sentinel
	int ans = 0;
	int cnt = 1;
	for(int i=1; i<=N; i++) {
		if(a[i] == a[i-1]) {
			++cnt;
//			printf("=, a[%d] = %lld, cnt=%d\n", i, a[i], cnt);
		}else {
			if(cnt%2 != 0) {
				++ans;	
			}
			cnt = 1;
//			printf("<>, a[%d] = %lld, cnt=%d\n", i, a[i], cnt);
		}
	}
	cout << ans << endl;
	return 0;
}

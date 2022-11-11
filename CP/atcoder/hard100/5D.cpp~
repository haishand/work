#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+10;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(MAXN);
	ll ans = 0;
	priority_queue<int> pq;
	for(int i=0; i<N; i++) {
		cin >> a[i];
		ans += a[i];
		pq.push(a[i]);
	}
	int y = M;
	while(y>0) {
		int ma = pq.top();
		pq.pop();
		ans -= (ma-ma/2);
		pq.push(ma/2);
		--y;
	}
	/*
	while(y>0) {
		int ma = 0;
		int mi = 0;
		for(int i=0; i<N; i++) {
			if(ma<a[i]) {
				ma = a[i];
				mi = i;
			}
		}
		ans -= (ma-ma/2);
		a[mi] = a[mi]/2;
		--y;
		
	}
	*/
	cout << ans << endl;
	return 0;
}

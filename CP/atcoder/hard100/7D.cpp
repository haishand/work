#include<bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<int, int> pii;

bool mycomp(const pii& a, const pii& b) {
	return a.second>b.second;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<pii> bc(m), canuse;
	for(int i=0; i<m; i++) {
		cin >> bc[i].first >> bc[i].second; 
	}
	sort(bc.begin(), bc.end(), mycomp);

	int s = 0;
	for(int i=0; s<n && i<m; i++) {
		canuse.push_back(make_pair(bc[i].first, bc[i].second));
		s+=bc[i].first;
	}

	priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());
	for(int i=0; i<canuse.size(); i++) {
		int b = canuse[i].first;
		int c = canuse[i].second;
		do {
			int e = pq.top();
			if(e>=c) break;
			pq.pop();
			pq.push(c);
			--b;
		}while(b);
	}
	ll ans = 0;
	while(!pq.empty()) {
		int e = pq.top();
//		printf("pq: %d\n", e);
		pq.pop();
		ans += e;
	}
	cout << ans << endl;
	return 0;
}

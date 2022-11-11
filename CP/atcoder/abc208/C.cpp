#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;

int main() {
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];				
	}
	
	vector<int> b(n);
	iota(begin(b), end(b), 0);
	sort(begin(b), end(b), [&](int i, int j) { return a[i]<a[j];});

	vector<ll> answer(n, k/n);
	for(int i=0; i<k%n; i++) {
		++answer[b[i]];
	}
	for(int i=0; i<n; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
	int n, k;
	cin >> n >> k;

	double p = 0;
	for(int i=1; i<=n; i++) {
		int score = i;
		double coin = 1;
		int cnt = 0;
		while(score<k) {
			score *= 2;
			coin *= 0.5;
			++cnt;
		}
		p += (double)1/n*coin;
	}
	if(p <= 0) {
		cout << 0 << endl;
	}else {
		cout.precision(12);
		cout << p << endl;
	}
}
	

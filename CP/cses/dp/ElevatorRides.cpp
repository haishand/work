#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> w(n);
	for(int i=0; i<n; i++) {
		cin >> w[i];
	}
	pair<int, int> best[1<<n];
	best[0] = {1, 0};
	for(int s = 1; s < (1<<n); s++) {
		best[s] = {n+1, 0};
		for(int p=0; p<n; p++) {
			if(s & (1<<p)) {
				auto option = best[s ^ (1<<p)];
				if(option.second + w[p] <= x) {
					option.second += w[p];
				}else {
					option.first++;
					option.second = w[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
	cout << best[(1<<n)-1].first << endl;
	return 0;
}

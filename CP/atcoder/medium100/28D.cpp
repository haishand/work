#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5+10;
double f(int val) {
	return val*(val+1)/2.0/val;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(MAXN);
	for(int i=1; i<=N; i++) {
		cin >> a[i];
	}
	vector<double> sum(MAXN);
	sum[0] = 0;
	for(int i=1; i<=N; i++) {
		sum[i] += sum[i-1]+f(a[i]);
	}

	double ans = 0;
	for(int i=0; i+K<=N; i++) {
		ans = max(ans, sum[i+K]-sum[i]);
	}
	cout << setiosflags(ios::fixed) << setprecision(12) << ans << endl;
	return 0;
}

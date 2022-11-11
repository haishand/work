#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

ll fact(int n) {

}
ll ncr(int n, int i, int p) {

}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int a1 = count(a.begin(), a.end(), '1');
		int b1 = count(b.begin(), b.end(), '1');
		int mi = abs(a1-b1);
		int ma = n-((a1+b1)-n);

		ll ans = 0;
		for(int i = mi; i<=ma; i++) {
			ans += ncr(n, i, p);
		}
	}
	return 0;
}

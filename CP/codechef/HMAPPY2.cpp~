#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if(a==0) {
		return b;
	}
	return gcd(b%a, a);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll N, A, B, K;
		
		cin >> N >> A >> B >> K;
		ll lcm = A/gcd(A, B)*B;
		ll apply = N/A;
		ll chef = N/B;
		ll com = N/lcm;
		if(apply+chef-2*com>=K) {
			cout << "Win" << endl;
		}else {
			cout << "Lose" << endl;
		}
	}
	return 0;
}

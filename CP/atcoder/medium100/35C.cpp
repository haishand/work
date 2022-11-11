#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if(a==0) {
		return b;
	}
	return gcd(b%a, a);
}
int main() {
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	ll g = gcd(C, D);
	ll t = C*D/g;
	ll ans = (B-A+1)-(B/C- (A-1)/C + B/D - (A-1)/D - (B/t-(A-1)/t));
	cout << ans << endl;
	return 0;
}

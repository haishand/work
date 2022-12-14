#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if(a==0) {
		return b;
	}
	return gcd(a%b, a);
}

ll egcd(ll a, ll b, ll& x, ll& y) {
	if(a==0) {
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1;
	ll g = egcd(a, b, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return g;
}

int main() {
	cout << gcd(60, 84) << endl;
	return 0;
}

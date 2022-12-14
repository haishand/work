#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;
const int maxn = 2e5+42;

ll fastpow(ll x, int y, int p) {
	x%=p;
	if(y==0) return 1;
	ll ans = 1;
	if(y%2) {
		ans *= x;
		ans %= p;
		--y;
	}
	ans *= fastpow(x*x, y/2, p);
	return ans%p;
}

ll modMul(ll x, ll y, int p) {
	x%=p;
	if(y==1) {
		return x;
	}
	ll ans = 0;
	if(y%2) {
		ans += x;
		--y;
	}
	ans += modMul(2*x, y/2, p);
	return ans%p;
}

ll gcd(ll x, ll y) {
	if(x==0) return y;
	return gcd(y, x%y);
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
	if(a==0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll g = exgcd(b%a, a, x1, y1);
	y = x1;
	x = y1-(b/a)*x1;
	return g;

}

int bpow(int x, int n) {
	return n ? n % 2 ? 1LL * x * bpow(x, n - 1) % mod : bpow(1LL * x * x % mod, n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod-2);
}

ll modInv(ll a, int p) {
	/*
	if(gcd(a, p) != 1) {
		return -1;
	}
	*/
	return (fastpow(a, p-2, p)%p+p)%p;
//	return bpow(a, p-2)%p;
}

ll modInv2(ll a, int p) {
	ll x, y;
	ll g = exgcd(a, p, x, y);
	return (x%mod+mod)%mod;
}

ll modDiv(ll x, ll y, int p) {
	x %= p;
	ll y_inv = modInv(y, p);
	if(y_inv == -1) {
		return 0;
	}
	return modMul(x, y_inv, p);
}

int f[maxn] = {0};
ll fact(ll n) {
	if(n==0) {
		return 1;
	}
	if(f[n]) {
		return f[n];
	}
	return f[n] = n*fact(n-1)%mod;
}

ll rfact(ll n) {
	return modInv2(fact(n), mod);
}
ll ncr2(ll n, ll r, int p) {
	return fact(n)*rfact(r)%mod * rfact(n-r)%mod;	
}

ll ncr(ll n, ll r, int p) {
	if(r==0) {
		return 1;
	}
	if(r>n-r) {
		r = n-r;
	}
	ll ans = 1;
	for(int i=1; i<=r; i++) {
		ans = modMul(ans, (n-i+1), p);
		ans = modDiv(ans, i, p);
	}
	return ans;
}

void test() {
	cout << modMul(5, 20, mod) << endl;
	cout << ncr(5, 3, mod) << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string sa, sb;
		cin >> sa >> sb;
		int a1 = 0, b1 = 0;
		for(int i=0; i<n; i++) {
			if(sa[i] == '1') {
				++a1;
			}
			if(sb[i] == '1') {
				++b1;
			}
		}

		int mi = abs(a1-b1), ma = a1+b1-2*max(0, a1+b1-n);
		ll ans = 0;
		for(int i=mi; i<=ma; i+=2) {
			ans += ncr2(n, i, mod);
			ans %= mod;
		}

		cout << ans << endl;
//		test();
	}
	return 0;
}

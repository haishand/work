#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 200;

int prime[maxn+1];
int used[maxn+1];
int semi_prime[maxn+1];

void pre_calc() {
	memset(prime, 0, sizeof(prime));
	memset(used, 0, sizeof(used));
	memset(semi_prime, 0, sizeof(semi_prime));
	for(int i=2; i<=maxn; i++) {
		if(!used[i]) {
			prime[i] = 1;
			for(int j=i; j<=maxn; j+=i) {
				used[j] = 1;
			}
		}
	}
	for(int i=2; i<=maxn; i++) {
		if(prime[i]) {
			for(int j=i+1; j<=maxn/i; j++) {
				if(prime[j]) {
					semi_prime[i*j] = 1;
				}
			}
		}
	}
}

int ok(int n) {
	for(int i=2; i<=n; i++) {
		if(semi_prime[i] && semi_prime[n-i]) {
//			printf("%d + %d = %d\n", i, n-i, n);
			return 1;
		}
	}
	return 0;
}

int main() {
	pre_calc();
	int t;
	cin >> t;
	while(t--) {
		int N;
		cin >> N;
		if(ok(N)) {
			cout << "YES";
		}else {
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}

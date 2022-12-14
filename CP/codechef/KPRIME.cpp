#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5;
int prime[maxn+1];
int used[maxn+1];
int kp[maxn+1];
void pre_calc() {
	memset(prime, 0, sizeof(prime));
	memset(used, 0, sizeof(used));
	memset(kp, 0, sizeof(kp));
	for(int i=2; i<=maxn; i++) {
		if(!used[i]) {
			prime[i] = 1;
			for(int j=i; j<=maxn; j+=i) {
				used[j] = 1;
				++kp[j];
			}
		}
	}

}
int main() {
	pre_calc();
	int t;
	cin >> t;
	while(t--) {
		int a, b, k;
		cin >> a >> b >> k;

		int ans = 0;
		for(int i=a; i<=b; i++) {
//			printf("kp[%d]=%d\n", i, kp[i]);
			if(kp[i] == k) {
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

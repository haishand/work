#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e7;
const int P = 30;

int a1[] = {0,1,3,8,1,5,4,7,7,4,5,1,8,3,1,0,9,7,2,9,5,6,3,3,6,5,9,2,7,9};
int a2[] = {1,2,5,3,4,9,3,0,7,1,6,7,5,8,9,9,8,5,7,6,1,7,0,3,9,4,3,5,2,1};

/*
void pre_calc() {
	ans[0] = 0; ans[1] = 1;
	for(int i=2; i<=maxn; i++) {
		ans[i] = (ans[i-1]+ans[i-2])%10;
	}
}
*/
int main() {
	/*
	pre_calc();
	for(int i=1; i<100; i+=2) {
		cout << "," << ans[i];;
	}
	*/
	int t;
	cin >> t;
	while(t--) {
		ll n; cin >> n;

		ll k = 1;
		while(k<n) {
			k*=2;
		}
		if(k>n) {
			k/=2;
		}
		cout << a2[(k/2)%P-1] << endl;
	}
	return 0;
}

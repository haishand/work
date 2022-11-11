#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int N;
		cin >> N; 
		int found = 0;
		ll ans = -1;
		for(int i=sqrt(N); i>0 && !found; i--) {
			if(N%i==0) {
				int a = (N/i-i)/2;
				int b = (N/i+i)/2;
				if((N+a*a == b*b) && (a!=0)) {
					ans = (1LL)*a*a;
					found = 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e9;

int main() {

	int t;
	cin >> t;
	while(t--) {

		ll n, m, x, y;
		cin >> n >>m >> x >> y;

		int can = 0;
		if((n-1)%x == 0 && (m-1)%y == 0) {
			// op1 op2 combined
			can = 1;
//			cout << "@1" << endl;
		}else if((n-1 == 1 && (m-1)%y == 1)) {
			// op3 once
			can = 1;
//			cout << "@2" << endl;
		}else if((n-2>=0) && (m-2>=0) && (n-1-1)%x == 0 && (m-1-1)%y == 0) {
			// op3 combined op1 and op2
			can = 1;
//			cout << "@3" << endl;
		}
		string ans = "Chefirnemo";
		if(!can) {
			ans = "Pofik";
		}
		cout << ans << endl;
	}
	return 0;
}

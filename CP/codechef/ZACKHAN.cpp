#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if(a==0) {
		return b;
	}
	return gcd(b%a, a);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int L, B;
		cin >> L >> B;
		cout << gcd(L, B)<< endl;
	}
	return 0;
}

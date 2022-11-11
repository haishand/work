#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	ll t = n%k;
	cout << min(t, k-t) << endl;
	return 0;
}

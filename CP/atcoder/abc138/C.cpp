#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	float ans = (v[0]+v[1])/2.0;
	for(int i=2; i<n; i++) {
		ans = (ans + v[i])/2.0;	
	}
	cout << ans << endl;
	return 0;
}

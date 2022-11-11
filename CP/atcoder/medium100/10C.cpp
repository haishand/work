#include <bits/stdc++.h>
using namespace std;
 
const int MA = 1e5+10;

int main() {
	int n;
	cin >> n;
	vector<int> b(MA);
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		++a;
		++b[a];
		++b[a-1];
		++b[a+1];
	}
	int ans = 0;
	for(int i=0; i<MA; i++) {
		if(b[i]>ans) {
			ans = b[i];
		}
	}
	cout << ans << endl;
    return 0;
}

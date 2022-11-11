#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	int a, b;
	cin >> a >> b;

	int socket = 1;
	int ans = 0;
	while(socket<b) {
		++ans;
		socket += a-1; 
	}
	cout << ans << endl;
	return 0;
}

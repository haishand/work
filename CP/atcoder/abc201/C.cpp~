#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	string s;
	cin >> s;
	int ans = 0;

	for(int pin=0; pin<=9999; pin++) {
		vector<int> flag(10, 0);
		int t = pin;
		for(int i=0; i<4; i++) {
			flag[t%10] = 1;
			t/=10;
		}
		int flag2 = 1;
		for(int i=0; i<=9; i++) {
			if(s[i] == 'o' && !flag[i]) flag2 = 0;
			if(s[i] == 'x' && flag[i]) flag2 = 0;
		}
		if(flag2) {
			++ans;
		}
	}
	cout << ans <<endl;
	return 0;
}

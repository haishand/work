#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s, t;
	cin >> s >> t;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	int n = s.length();
	int m = t.length();
	int flag = 0;
	for(int i=0; i<m; i++) {
		if(s[i]<t[i]) {
			flag = 1;
			break;
		}else if(s[i]>t[i]){
			flag = 0;
			break;
		}
	}
	if(flag) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
	return 0;
}

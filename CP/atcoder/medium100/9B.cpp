#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int flag = 0;
	for(int i=0; i<b; i++) {
		if(i*a%b == c%b) {
			flag = 1;
			break;
		}
	}
	if(flag) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}

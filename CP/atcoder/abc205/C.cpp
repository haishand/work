#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void output(int x, int y) {
	if(x>y) {
		cout << ">" << endl;
	}else if(x<y) {
		cout << "<" << endl;
	}else {
		cout << "=" << endl;
	}
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(c%2 == 0) {
		output(abs(a), abs(b));
	}else {
		output(a, b);
	}
	return 0;
}

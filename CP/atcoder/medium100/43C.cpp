#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int X;
	cin >> X;
	int s = 0;
	int i;
	for(i=1; s<X; i++) {
		s += i;
	}
	cout << i-1 << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+10;

int main() {
	int N;
	cin >> N;
	vector<int> a(MAXN);
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}

	int m2 = 0;
	int m4 = 0;
	for(int i=0; i<N; i++) {
		if(a[i]%4==0) ++m4;
		else if(a[i]%2 == 0) ++m2;
	}
	if(m2/2+m4>=N/2) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
	return 0;
}

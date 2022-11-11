#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	vector<vector<int>> c(3, vector<int>(3, 0));
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cin >> c[i][j];
		}
	}

	vector<int> a(3), b(3);
	a[0] = 0;
	for(int j=0; j<3; j++) {
		b[j] = c[0][j] - a[0];
	}
	for(int i=1; i<3; i++) {
		a[i] = c[i][0] - b[0];
	}

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(c[i][j] != a[i]+b[j]){
				cout << "No" <<endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}

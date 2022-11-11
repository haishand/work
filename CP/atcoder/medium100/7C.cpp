#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int rate(int score) {
	if(score>=3200) {
		return 8;
	}
	return score/400;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> color(9);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		++color[rate(a[i])];
	}

	int mi = 8, ma = 0;
	int nc = 0;
	for(int i=0; i<8; i++) {
		if(color[i]) {
			++nc;
		}	
	}
	mi = (nc == 0)?1:nc;
	ma = nc+color[8];
	cout << mi << " " << ma << endl;
	return 0;
}

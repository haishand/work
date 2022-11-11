#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w, 0));
	vector<int> xrow(h), xcol(w, 0);
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			char c;
			cin >> c;
			if(c == '.') {
				a[i][j] = 0;
			}else {
				a[i][j] = 1;
				++xrow[i];
				++xcol[j];
			}
		}
	}
	for(int i=0; i<h; i++) {
		if(xrow[i] == 0) {
			continue;
		}
		for(int j=0; j<w; j++) {
			if(xcol[j] == 0) {
				continue;
			}
			if(a[i][j] == 0) {
				printf(".");
			}
			if(a[i][j] == 1) {
				printf("#");
			}
		}
		printf("\n");
	}
    return 0;
}

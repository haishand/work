#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int within(int v, int low, int high) {
	if(v>=low && v<high) {
		return 1;
	}
	return 0;
}
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	vector<vector<int>> ans(h, vector<int>(w, 0));
	for(int i=0; i<h; i++) {
		cin >> grid[i];
	}
	for(int x=0; x<h; x++) {
		for(int y=0; y<w; y++) {
			if(grid[x][y] == '#') {
				continue;
			}
			int bomb = 0;
			for(int k=0; k<8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(within(nx, 0, h) && within(ny, 0, w)) {
					if(grid[nx][ny] == '#') {
						++bomb;
					}
				}
			}
			ans[x][y] = bomb;

		}
	}
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(grid[i][j] == '#') {
				cout << '#';
			}else {
				cout << ans[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}

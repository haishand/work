#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool within(int v, int low, int high) {
	if(v>=low && v<high) {
		return true;
	}
	return false;
}
int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> grid(h, vector<char> (w, '.'));
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			cin >> grid[i][j];
		}
	}

	vector<vector<bool>> can(h, vector<bool>(w, false));
	for(int x=0; x<h; x++) {
		for(int y=0; y<w; y++) {
			if(grid[x][y] == '#') {
				// check if any adjcent squares have '#' from horizontal/vertical
				for(int k=0; k<4; k++) {
					int nx = x+dx[k];
					int ny = y+dy[k];
					if(within(nx, 0, h) && within(ny, 0, w)) {
						if(grid[nx][ny] == '#') {
							can[x][y] = true;
							break;
						}
					}
				}
			}
		}
	}
	bool allcan = true;
	for(int x=0; x<h; x++) {
		for(int y=0; y<w; y++) {
			if(grid[x][y] == '#')
				allcan &= can[x][y];
		}
	}
	if(allcan) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
    return 0;
}

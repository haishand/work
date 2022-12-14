#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXH = 110;
const int MAXW = 110;

char grid[MAXH][MAXW];
int dp[MAXH][MAXW];

int main() {
	int h, w;
	cin >> h >> w;
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w; j++) {
			cin >> grid[i][j];
		}
	}
	
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[1][1] = (grid[1][1] == '#');
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w; j++) {
			dp[i][j] = min(dp[i][j], min(dp[i][j-1] + (grid[i][j-1] == '.' && grid[i][j] == '#'), dp[i-1][j] + (grid[i-1][j] == '.' && grid[i][j] == '#')));
		}
	}
	cout << dp[h][w] << endl;
	return 0;;
}

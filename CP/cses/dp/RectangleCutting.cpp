#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxa = 500;
const int maxb = 500;
const int inf = 0x3f3f3f3f;

int dp[maxa+1][maxb+1];

int main() {
	int a, b;
	cin >> a >> b;
	for(int i=0; i<=a; i++) {
		for(int j=0; j<=b; j++) {
			if(i==j) {
				dp[i][j] = 0;
			}else {
				dp[i][j] = inf;
				for(int k=1; k<i; k++) {
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1);
				}
				for(int k=1; k<j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1);
				}
			}
		}
	}
	cout << dp[a][b] << endl;
	return 0;
}

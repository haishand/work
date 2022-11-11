#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, Y;
	cin >> N >> Y;
	for(int x=0; x<=N; x++) {
		for(int y=0; y<=N; y++) {
			int z = N - x - y;
			if(z<0) continue;
			if(10000*x+5000*y+1000*z == Y) {
				printf("%d %d %d\n", x, y, z);
				exit(0);
			}
		}
	}
	printf("-1 -1 -1\n");
	return 0;
}

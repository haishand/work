#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 0x3f3f3f3f;
const int MAXN  = 500;

int T;
ll N;
ll dp[MAXN][MAXN];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        ll ans = 0;
        for(int i=1; 2*i+1<=N; i++) {
            ans += 1LL*((2*i+1)*4-4)*i;
        }
        cout << ans << endl;
    }
}
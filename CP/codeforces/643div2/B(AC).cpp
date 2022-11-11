#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5+10;
int T, N;
int e[MAXN];
map<int, int> mii;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        mii.clear();
        int e;
        for(int i=1; i<=N; i++) {
            scanf("%d", &e);
            mii[e]++;
        }
        int ans = 0; int rest = 0;
        for(auto e : mii) {
            ans +=(rest + e.second)/e.first;
            rest = (rest + e.second)%e.first;
        }        
        printf("%d\n", ans);
    }
    return 0;
}
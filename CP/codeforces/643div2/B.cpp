#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int T, N;
int e[MAXN];
int cnt[MAXN];
set<int> s;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        memset(cnt, 0, sizeof(cnt));
        s.clear();
        int e;
        for(int i=1; i<=N; i++) {
            scanf("%d", &e);
            cnt[e]++;
            s.insert(e);
        }
        int ans = 0; int rest = 0;
        for(auto e : s) {
            ans += (rest + cnt[e])/e;
            rest = (rest + cnt[e])%e;
        }        
        printf("%d\n", ans);
    }
    return 0;
}
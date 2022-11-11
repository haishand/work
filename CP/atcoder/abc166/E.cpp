#include<bits/stdc++.h>

using namespace std;
#define LL  long long

const int MAXN = 2e5+10;
const int MAXNUM = 1e9+10;
LL N;
LL A[MAXN];
map<LL, LL> mii;

int main()
{
    cin >> N;
    
    for(LL i=1; i<=N; i++) {
        cin >> A[i];
    } 

    for(LL i=1; i<=N; i++) {
        LL t = A[i] + i;
        mii[t]++;
    }

    LL ans = 0;
    for(LL j=1; j<=N; j++) {
        LL t = j-A[j];
        ans += mii[t];
    }
    cout << ans << endl;
    return 0;
}
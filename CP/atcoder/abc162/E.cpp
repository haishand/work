#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>

#define LL  long long
#define MAXK    100010
#define P   1000000007
using namespace std;
int N, K;

LL cnt[MAXK];

LL ans = 0;

int main()
{
    
    scanf("%d%d", &N, &K);

    for(int i=K; i>=1; i--) {
        int t = K/i;
        cnt[i] = pow(t, N);
        for(int j=i+i; j<=K; j+=i) {
            cnt[i] -= cnt[j];
            cnt[i] %= P;
        }
//        printf("%d %d\n", i, cnt[i]);
        ans += cnt[i]*i;
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}
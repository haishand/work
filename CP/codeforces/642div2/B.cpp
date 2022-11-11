#include<bits/stdc++.h>

using namespace std;

const int MAXN = 40;

int T, N, K;
int a[MAXN], b[MAXN];
int main() {
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i=1; i<=N; i++) {
            cin >> a[i];
        }
        for(int i=1; i<=N; i++) {
            cin >> b[i];
        }
        sort(a+1, a+N+1);
        sort(b+1, b+N+1);
        int ans = 0;
        if(a[1]>=b[N] || K==0) {
            // no swap needed
            ans = 0;
            for(int i=1; i<=N; i++) {
                ans += a[i];
            }
        }else {
            int t  =0; int flag = 1;
            int i;
            for(i=1; i<=N&&flag; i++) {
                int j = N-i+1;
                if(a[i]<b[j]) {
                    // swap
                    a[i] = b[j];
                    ++t;
                    if(t==K) {
                        flag = 0;
                    }
                }
                ans += a[i];
            }
            for(int j=i; j<=N; j++) {
                ans += a[j];
            }
        } 
        cout << ans << endl;
    }    
    return 0;
}
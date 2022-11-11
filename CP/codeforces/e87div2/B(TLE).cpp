#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int inf = 0x3f3f3f3f;
int c[4][MAXN];
int T;

//int dp[MAXN][MAXN];
inline int can(int i, int j) {
    for(int k=1; k<=3; k++) {
        if(c[k][j] - c[k][i-1] <=0) {
            return 0;
        }
    }
    return 1;
}
/*
int solve(int i, int j) {
    if(i>=j) return 0;
 //   if(dp[i][j]) return dp[i][j];
    int v1, v2, v3;
    v1 = v2 = v3 = inf;
    if(can(i+1,j)) {
        v1 = solve(i+1, j);
    }
    if(can(i,j-1)) {
        v2 = solve(i, j-1);
    }
    if(can(i+1, j-1)) {
        v3 = solve(i+1, j-1);
    }
//    return dp[i][j] = min(min(v1,v2),min(v3, j-i+1));
    return  min(min(v1,v2),min(v3, j-i+1));
}
*/
int main() {
    cin >> T;
    string s;
    while(T--) {
        cin >> s;
        memset(c, 0, sizeof(c));
        int n = s.length();
        for(int i=0; i<n; i++) {
            c[s[i]-'0'][i+1]++;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=3; j++) {
                c[j][i] += c[j][i-1];
            }
        }

/*
        for(int j=1; j<=3; j++) {
            for(int i=1; i<=n; i++){
                printf("$c[%d][%d]=%d ", j, i, c[j][i]);
            }
            printf("\n");
        }
        */

/*
        int i, j;
        i=1; j=n;
        int ans=0;
        if(can(i,j)) {
            ans = solve(i,j);
        }
        */
       int ans = inf;
       while(i<j) {
           if(can(i,j)) ans = min(ans, j-i+1);
           if(can(i+1,j)) {
               i++;
           }else {
               j--;
           }
       }
       cout << (ans==inf)?0:ans<< endl;

    }
    return 0;
}
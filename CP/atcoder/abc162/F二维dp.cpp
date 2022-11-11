#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>

#define LL  long long
//#define MAXN    200010
#define MAXN    20010
#define P   1000000007
using namespace std;
int N;
int A[MAXN];
int dp[MAXN][MAXN/2];

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }    
    memset(dp, 0, sizeof(dp));
    dp[1][1] = A[1]; dp[2][1] = max(A[1], A[2]);
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=i/2; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-2][j-1]+A[i]);

        }
    }
/*
	int i, j;
	i = N;j=N/2;
	cout<<"select:"<<endl;
	while(i&&j) {
		if(sel[i][j] != 0) {
			cout<<A[sel[i][j]]<<endl;
			i-=2;
			j-=1;
		}else {
			i-=1;
		}
	}
	*/
    cout << dp[N][N/2] << endl;

    return 0;
}

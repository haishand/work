#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>

#define LL  long long
#define MAXN    200010
#define P   1000000007
using namespace std;
int N;
int A[MAXN];
int dp[MAXN];
int sel[MAXN];

int ans = 0;

void print(int i){
	cout << "select: " <<endl;
	while(sel[i]) {
		cout <<  A[i] << endl;
		i = sel[i];
	}
}
int main()
{
    
    cin>>N;

    for(int i=1; i<=N; i++) {
        cin>>A[i];
    }    
    
    ans = 0;
    dp[0] = 0; dp[1] = A[1];dp[2] = A[2];
    sel[0] = 0;
    for(int i=3; i<=N; i++) {
    	if(dp[i-1]>dp[i-3]) {
    		sel[i] = i-1;
    	}else {
    		sel[i] = i-3;
    	}
        dp[i] = max(dp[i-2], dp[i-3]) + A[i];
    }
    ans = max(dp[N], max(dp[N-1], dp[N-2]));
    
    /*
    cout << dp[N];
    print(N);
    
    cout << dp[N-1];
    print(N-1);
    */
    cout<<dp[N-2]<<endl;
    print(N-2);
    
    cout << ans << endl;
    return 0;
}
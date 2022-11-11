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

LL fastpw(int base, int power) {
	LL result = 1;
	while(power>0) {
		if(power%2 == 1) {
			result = (result*base) %P;
		}
		power /= 2;
		base =(base*base) %P;

	}
	return result;
}

LL fastpw2(int base, int power) {
	LL result = 1;
	while(power>0) {
		if(power%2 == 0) {
			base = base * base % P;
			power /= 2;
		}else {
			power -= 1;
			result = result*base %P;
			power /= 2;
			base =base*base %P;
		}
	}
	return result;
}
int main()
{
    
    cin>>N>>K;

	cnt[K] = 1;
	ans = K;
    for(int i=K-1; i>=1; i--) {
        int t = K/i;
        cnt[i] = fastpw(t, N);
        //cnt[i] = pow(t, N);
        for(int j=i+i; j<=K; j+=i) {
            cnt[i] = cnt[i] + P - cnt[j];
            if(cnt[i]>=P) cnt[i]-=P;
        }
//        printf("%d %d\n", i, cnt[i]);
        ans += cnt[i]*i;
        ans %= P;
    }
    
//    cout << fastpw(2, 1000)<<endl;
    cout << ans << endl;
    return 0;
}
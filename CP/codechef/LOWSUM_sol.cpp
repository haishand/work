##include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define endl               "\n"

void solve(){
    ll n,q;
    scanf("%lld",&n);
    scanf("%lld",&q);
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        ll no;scanf("%lld",&no);
        a[i]=no;
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        ll no;scanf("%lld",&no);
        b[i]=no;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(q-->0){
        ll k;
        scanf("%lld",&k);
        ll low=a[0]+b[0],high=a[n-1]+b[n-1];
        ll ans=high;
        ll i,j,cnt;
        while(low<=high){
            ll mid = low + (high-low)/2;
            cnt=0,j=n-1;
            for(i=0;i<n&&(mid>a[i]);i++){
                while(j>=0&&(b[j]>mid-a[i]))j--;
                cnt+=j+1;
            }
            if(cnt>=k){
                ans=mid,high=mid-1;
            }
            else low=mid+1;
        }
        printf("%lld\n",ans);
    }
}

int main(){
    ll t;
    scanf("%lld",&t);
    while(t-->0){
        solve();
    }
}include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define endl               "\n"

void solve(){
    ll n,q;
    scanf("%lld",&n);
    scanf("%lld",&q);
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        ll no;scanf("%lld",&no);
        a[i]=no;
    }
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        ll no;scanf("%lld",&no);
        b[i]=no;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(q-->0){
        ll k;
        scanf("%lld",&k);
        ll low=a[0]+b[0],high=a[n-1]+b[n-1];
        ll ans=high;
        ll i,j,cnt;
        while(low<=high){
            ll mid = low + (high-low)/2;
            cnt=0,j=n-1;
            for(i=0;i<n&&(mid>a[i]);i++){
                while(j>=0&&(b[j]>mid-a[i]))j--;
                cnt+=j+1;
            }
            if(cnt>=k){
                ans=mid,high=mid-1;
            }
            else low=mid+1;
        }
        printf("%lld\n",ans);
    }
}

int main(){
    ll t;
    scanf("%lld",&t);
    while(t-->0){
        solve();
    }
}
